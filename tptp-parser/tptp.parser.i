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

// iterator support for python
%include "exception.i"
%exception {
    try
    {
        $function
    }
    catch (const StopNodeIterator&)
    {
        PyErr_SetString(PyExc_StopIteration, "End of iterator");
        return NULL;
    }
}

%include "tptp.ast.hh"
%include "tptp.parser.hh"
