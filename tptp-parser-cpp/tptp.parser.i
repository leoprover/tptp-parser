// TPTP parser interface for SWIG interface
%module tptp_parser
%{
#include "tptp.ast.hh"
#include "tptp.parser.hh"
%}

%ignore "";
%rename("%s") tptp::parse;
