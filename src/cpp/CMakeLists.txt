#############################################################
#
# Makefile     : CMakefile to build different tptp lexer and parser.
# Author       : Marco Träger
# Last Updated : 2020/07
#
#############################################################

project(TPTP_Parser)
cmake_minimum_required(VERSION 3.16)

####
# Dir setup
set(TPTP_BIN ${CMAKE_CURRENT_BINARY_DIR}/../bin/)
set(TPTP_BIN_PYTHON ${CMAKE_CURRENT_BINARY_DIR}/../bin/python3/)
set(TPTP_SOURCE_PYTHON ${CMAKE_CURRENT_SOURCE_DIR}/../python3/)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

####
# build BISON/FLEX parser
find_package(BISON 3.2)
find_package(FLEX)

BISON_TARGET(BFParser tptp.yy ${CMAKE_CURRENT_BINARY_DIR}/tptp.grammar.cc)
FLEX_TARGET(BFLexer tptp.ll ${CMAKE_CURRENT_BINARY_DIR}/tptp.lexer.cc)
ADD_FLEX_BISON_DEPENDENCY(BFLexer BFParser)

####
# build executable
add_executable(tptp_parser
    tptp.test.cc
    tptp.ast.hh tptp.parser.hh
    tptp.ast.cc tptp.parser.cc
    ${BISON_BFParser_OUTPUTS}
    ${FLEX_BFLexer_OUTPUTS}
)

####
# setup swig for python3 bindings
find_package(Python3 REQUIRED COMPONENTS Development)
find_package(SWIG)
include(UseSWIG)

set_property(SOURCE tptp.parser.i PROPERTY CPLUSPLUS ON)
set_property(SOURCE tptp.parser.i PROPERTY SWIG_MODULE_NAME tptp_parser)

swig_add_library(tptp_parser_python
    TYPE MODULE
    LANGUAGE python
    SOURCES tptp.parser.i 
    tptp.ast.hh tptp.parser.hh
    tptp.ast.cc tptp.parser.cc
    ${BISON_BFParser_OUTPUTS}
    ${FLEX_BFLexer_OUTPUTS}
)

set_property(TARGET tptp_parser_python PROPERTY SWIG_USE_TARGET_INCLUDE_DIRECTORIES ON)

# link python3 into the swig setup
target_link_libraries(tptp_parser_python Python3::Module)

####
# copy final files to bin
file(MAKE_DIRECTORY ${TPTP_BIN})
add_custom_command(TARGET tptp_parser POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy tptp_parser ${TPTP_BIN})

file(MAKE_DIRECTORY ${TPTP_BIN_PYTHON})
add_custom_command(TARGET tptp_parser_python POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${TPTP_SOURCE_PYTHON} ${TPTP_BIN_PYTHON})
add_custom_command(TARGET tptp_parser_python POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy _tptp_parser_python.so ${TPTP_BIN_PYTHON}/tptp_parser)
add_custom_command(TARGET tptp_parser_python POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy tptp_parser.py ${TPTP_BIN_PYTHON}/tptp_parser)
