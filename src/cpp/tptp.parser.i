// TPTP parser interface for SWIG interface

// TODO
// * change ignore/renames to a white- instead of a black-list
// * how to setup a well defined multi-target interface (with python2, python3, java, scala)?

%module tptp_parser
%include "std_string.i"                 // we need std::string support for the file name in
                                        //   tptp::parse
%include "exception.i"                  // we need execption support for the python iterator
                                        //   tptp::ast::node::__iter__ and 
                                        //   tptp::ast::node::__next__

%{
#include "tptp.ast.hh"
#include "tptp.parser.hh"
%}

%ignore yylex;                          // macro for the parser. TODO hide this away inside the package
%ignore tptp::parser;                   // the parser is accessable using "parse"

%ignore tptp::ast::node::operator=;         // ignoring assignment
%ignore tptp::ast::node::node(const node&); // ignore copy constructor s.t. we can import the move constructor
//%ignore tptp::ast::node::node;          // ignoring constuctor
//%ignore tptp::ast::node::~node;         // ignoring destructor
//%nodefaultdtor tptp::ast::node;         // don't generate a destructor
//%ignore tptp::ast::node::add_left;      // we're immutable, ignore adding
//%ignore tptp::ast::node::add_right;
%ignore tptp::ast::node::out;                       // no ostream support    
%ignore operator<<(std::ostream& o, const node& n); // no ostream support  
%ignore operator<<(std::ostream& o, structuretype); // no ostream support

%ignore tptp::ast::structuretype;
%ignore tptp::ast::node::structure;

%rename(__str__) tptp::ast::node::toString;
%rename(__getitem__) tptp::ast::node::getChild;
%rename(__setitem__) tptp::ast::node::setChild;

// iterator support for python
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

// warning, %includes need to be afer %rename and %ignore, as well as other import modifications
%include "tptp.ast.hh"
%include "tptp.parser.hh"
