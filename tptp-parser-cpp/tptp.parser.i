// TPTP parser interface for SWIG interface
%module tptp_parser
%include "std_string.i"

%{
#include "tptp.ast.hh"
#include "tptp.parser.hh"
%}

%ignore yylex;
%ignore tptp::parser;

%ignore tptp::ast::node::operator=;     // ignoring assignment
%ignore tptp::ast::node::node;          // ignoring constuctor
%ignore tptp::ast::node::~node;         // ignoring destructor
%nodefaultdtor tptp::ast::node;         // don't generate a destructor
%ignore tptp::ast::node::add_left;
%ignore tptp::ast::node::add_right;
%ignore tptp::ast::node::out;

%include "tptp.ast.hh"
%include "tptp.parser.hh"
