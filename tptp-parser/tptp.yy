%require "3.2" // for cpp api.value.automoves
%defines
%skeleton "lalr1.cc" // use newer C++ skeleton file
%define api.value.type variant
%define api.token.constructor
%define api.value.automove
%code requires
{
    // This is a parser-grammar file for TPTP language Version 7.2.0.1 using the flex/bison 
    // parser generator.
    // The BNF specification of the TPTP language was provided by Geoff Sutcliffe.
    // The grammar file is created by Marco Träger, inspired by the ANTLR grammer
    // (https://github.com/leoprover/Leo-III/blob/master/contrib/tptp.g4) written by 
    // Alexander Steen and Tobias Gleißner.
    // Date: Aug 2019
    // Last updated: Sep 2019

    #include <string>
    #include "tptp.ast.hh"

    using namespace tptp::ast;
    namespace tptp {
        class parser;
    }
}
%param { tptp::parser& drv }
%locations
%define parse.trace
%define parse.error verbose
%code { 
    #include <iostream>
    #include "tptp.parser.hh"
    #include "tptp.ast.hh"

    using namespace tptp;

    // $$ = N(IDENTIFIER);
    //   -> 
    // $$ = ast::node(ast::IDENTIFIER);
    // $$ = N(IDENTIFIER, $1, $2);
    //   -> 
    // $$ = ast::node(ast::IDENTIFIER, $1, $2);
    #define N(s, t, ...) ast::node(ast::nodetype::t, ast::structuretype::s __VA_OPT__(,) __VA_ARGS__ )
}

// DEVELOPMENT NOTE:
// When updating to new TPTP versions, one should always update all reference-comments to
// the BNF specification as well.

// %----v7.2.0.1 (TPTP version.internal development number)
// %----Added semantic rules for <thf_unitary_type>
// %------------------------------------------------------------------------------
// %----README ... this header provides important meta- and usage information
// %----
// %----Intended uses of the various parts of the TPTP syntax are explained
// %----in the TPTP technical manual, linked from www.tptp.org.
// %----
// %----Four kinds of separators are used, to indicate different types of rules:
// %----  ::= is used for regular grammar rules, for syntactic parsing.
// %----  :== is used for semantic grammar rules. These define specific values
// %----      that make semantic sense when more general syntactic rules apply.
// %----  ::- is used for rules that produce tokens.
// %----  ::: is used for rules that define character classes used in the
// %----       construction of tokens.
// %----
// %----White space may occur between any two tokens. White space is not specified
// %----in the grammar, but there are some restrictions to ensure that the grammar
// %----is compatible with standard Prolog: a <TPTP_file> should be readable with
// %----read/1.
// %----
// %----The syntax of comments is defined by the <comment> rule. Comments may
// %----occur between any two tokens, but do not act as white space. Comments
// %----will normally be discarded at the lexical level, but may be processed
// %----by systems that understand them (e.g., if the system comment convention
// %----is followed).
// %----
// %----Multiple languages are defined. Depending on your need, you can implement 
// %----just the one(s) you need. The common rules for atoms, terms, etc, come 
// %----after the definitions of the languages, and mostly all needed for all the 
// %----languages.
// %------------------------------------------------------------------------------
// %----Files. Empty file is OK.

%token END_OF_FILE 0
%token <std::string> DefinitionTHF
%token <std::string> DefinitionInclude DefinitionEnd
%token <std::string> Dollar_ite Dollar_let Dollar_thf Dollar_tff Dollar_fof Dollar_cnf Dollar_fot
%token <std::string> Lower_word Upper_word Integer Rational Real
%token <std::string> Assignment And Or Nand Nor Impl If Iff Niff
%token <std::string> Infix_equality Infix_inequality Not 
%token <std::string> ForallComb TyForall Forall ExistsComb TyExists Exists Lambda
%token <std::string> ChoiceComb Choice DescriptionComb Description EqComb App
%token <std::string> LParen RParen LBrkt RBrkt LCurly RCurly Comma Colon
%token <std::string> Double_quote Single_quote Do_string Sq_string
%token <std::string> Subtype_sign Arrow Less_sign Star Gentzen_arrow Plus
%token <std::string> Dollar_word Dollar_dollar_word

// binding strength: top:=low -> bottom:=high
%right Comma
%nonassoc Niff
%nonassoc Iff
%nonassoc If
%nonassoc Impl
%nonassoc Nor
%nonassoc Nand
%left Or
%left And
%nonassoc Infix_inequality
%nonassoc Infix_equality
%right Assignment
%left App
%right Arrow
%nonassoc Gentzen_arrow

%type <node> TPTP_file TPTP_input
%type <node> annotated_formula
%type <node> thf_annotated /*tff_annotated tcf_annotated fof_annotated cnf_annotated tpi_annotated*/
// thf
%type <node> thf_formula
%type <node> thf_logic_formula thf_binary_formula thf_unit_formula thf_preunit_formula thf_unitary_formula thf_apply_formula
%type <node> thf_quantified_formula thf_quantification thf_variable_list thf_variable_list__HELPER0 thf_typed_variable 
%type <node> /*thf_unary_formula*/ thf_prefix_unary /*thf_infix_unary*/ thf_atomic_formula thf_plain_atomic 
%type <node> thf_defined_atomic /*thf_defined_infix*/ thf_system_atomic
%type <node> thf_conditional thf_unitary_term thf_let thf_let_types thf_let_types_list
%type <node> thf_let_defn thf_let_defns thf_let_defns_list thf_tuple thf_formula_list thf_conn_term
%type <node> thf_top_level_type thf_atom_typing thf_binary_type thf_mapping_type thf_xprod_type thf_union_type thf_subtype thf_sequent
%type <node> thf_unitary_type thf_apply_type

// quantifier
%type <node> thf_quantifier th1_quantifier th0_quantifier fof_quantifier
%type <node> thf_unary_connective th1_unary_connective unary_connective nonassoc_connective assoc_connective
// general
%type <node> atom untyped_atom /*defined_infix_pred*/
%type <node> constant functor system_constant system_functor defined_constant defined_functor defined_term variable
%type <node> source optional_info useful_info
%type <node> include formula_selection name_list
%type <node> general_function general_data formula_data general_term general_list general_terms
%type <node> name formula_role annotations
%type <node> atomic_defined_word atomic_system_word number file_name
%type <node> atomic_word single_quoted distinct_object
%type <node> root

// Changes to original Grammar are marked by @annontations
%%

// Give access to root node
root 
: TPTP_file { drv.ast = std::move($1); }
;

// <TPTP_file>            ::= <TPTP_input>*
// <TPTP_input>           ::= <annotated_formula> | <include>
// 
// %----Formula records
// <annotated_formula>    ::= <thf_annotated> | <tff_annotated> | <tcf_annotated> |
//                           <fof_annotated> | <cnf_annotated> | <tpi_annotated>
// %----Future languages may include ...  english | efof | tfof | mathml | ...
// <tpi_annotated>        ::= tpi(<name>,<formula_role>,<tpi_formula><annotations>).
// <tpi_formula>          ::= <fof_formula>
// <thf_annotated>        ::= thf(<name>,<formula_role>,<thf_formula>
//                            <annotations>).
// <tff_annotated>        ::= tff(<name>,<formula_role>,<tff_formula>
//                            <annotations>).
// <tcf_annotated>        ::= tcf(<name>,<formula_role>,<tcf_formula>
//                            <annotations>).
// <fof_annotated>        ::= fof(<name>,<formula_role>,<fof_formula>
//                            <annotations>).
// <cnf_annotated>        ::= cnf(<name>,<formula_role>,<cnf_formula>
//                            <annotations>).
// <annotations>          ::= ,<source><optional_info> | <null>

// TODO: introduce eps
TPTP_file 
: TPTP_input TPTP_file { $$ = $2.addLeft($1); }
| TPTP_input           { $$ = N(SEQUENCE, TPTP_file, $1); }
;
TPTP_input
: annotated_formula { $$ = N(SINGLE, TPTP_input, $1); }
| include           { $$ = N(SINGLE, TPTP_input, $1); }
;

annotated_formula
: thf_annotated { $$ = N(SINGLE, annotated_formula, $1); }
//| tff_annotated { $$ = N(annotated_formula, $1); }
//| tcf_annotated { $$ = N(annotated_formula, $1); }
//| fof_annotated { $$ = N(annotated_formula, $1); }
//| cnf_annotated { $$ = N(annotated_formula, $1); }
//| tpi_annotated { $$ = N(annotated_formula, $1); }
;

thf_annotated
: DefinitionTHF name Comma formula_role Comma thf_formula annotations DefinitionEnd { $$ = N(ANNONTATED, thf_annotated, $1, $2, $3, $4, $5, $6, $7, $8); }
;

annotations
: Comma source optional_info { $$ = N(ANNONTATED_OPTION, annotations, $1, $2, $3); }
| %empty {}
;

// %----In derivations the annotated formulae names must be unique, so that
// %----parent references (see <inference_record>) are unambiguous.// 

// %----Types for problems.
// %----Note: The previous <source_type> from ...
// %----   <formula_role> ::= <user_role>-<source>
// %----... is now gone. Parsers may choose to be tolerant of it for backwards
// %----compatibility.
// <formula_role>         ::= <lower_word>
// <formula_role>         :== axiom | hypothesis | definition | assumption |
//                            lemma | theorem | corollary | conjecture |
//                            negated_conjecture | plain | type |
//                            fi_domain | fi_functors | fi_predicates | unknown
formula_role
: Lower_word { $$ = N(SINGLE, formula_role, $1); }
;

// %----"axiom"s are accepted, without proof. There is no guarantee that the
// %----axioms of a problem are consistent.
// %----"hypothesis"s are assumed to be true for a particular problem, and are
// %----used like "axiom"s.
// %----"definition"s are intended to define symbols. They are either universally
// %----quantified equations, or universally quantified equivalences with an
// %----atomic lefthand side. They can be treated like "axiom"s.
// %----"assumption"s can be used like axioms, but must be discharged before a
// %----derivation is complete.
// %----"lemma"s and "theorem"s have been proven from the "axiom"s. They can be
// %----used like "axiom"s in problems, and a problem containing a non-redundant
// %----"lemma" or theorem" is ill-formed. They can also appear in derivations.
// %----"theorem"s are more important than "lemma"s from the user perspective.
// %----"conjecture"s are to be proven from the "axiom"(-like) formulae. A problem
// %----is solved only when all "conjecture"s are proven.
// %----"negated_conjecture"s are formed from negation of a "conjecture" (usually
// %----in a FOF to CNF conversion).
// %----"plain"s have no specified user semantics.
// %----"fi_domain", "fi_functors", and "fi_predicates" are used to record the
// %----domain, interpretation of functors, and interpretation of predicates, for
// %----a finite interpretation.
// %----"type" defines the type globally for one symbol; treat as $true.
// %----"unknown"s have unknown role, and this is an error situation.
// %------------------------------------------------------------------------------
// %----THF formulae.
// <thf_formula>          ::= <thf_logic_formula> | <thf_atom_typing> |
//                            <thf_subtype> | <thf_sequent>
// <thf_logic_formula>    ::= <thf_unitary_formula> | <thf_unary_formula> |
//                            <thf_binary_formula> | <thf_defined_infix>
// <thf_binary_formula>   ::= <thf_binary_nonassoc> | <thf_binary_assoc> |
//                            <thf_binary_type>
// %----There's no precedence among binary connectives
// <thf_binary_nonassoc>  ::= <thf_unit_formula> <nonassoc_connective>
//                            <thf_unit_formula>
// <thf_binary_assoc>     ::= <thf_or_formula> | <thf_and_formula> |
//                            <thf_apply_formula>
// <thf_or_formula>       ::= <thf_unit_formula> <vline> <thf_unit_formula> |
//                            <thf_or_formula> <vline> <thf_unit_formula>
// <thf_and_formula>      ::= <thf_unit_formula> & <thf_unit_formula> |
//                            <thf_and_formula> & <thf_unit_formula>
// %----@ (denoting apply) is left-associative and lambda is right-associative.
// %----^ [X] : ^ [Y] : f @ g (where f is a <thf_apply_formula> and g is a
// %----<thf_unitary_formula>) should be parsed as: (^ [X] : (^ [Y] : f)) @ g.
// %----That is, g is not in the scope of either lambda.
// <thf_apply_formula>    ::= <thf_unit_formula> @ <thf_unit_formula> |
//                            <thf_apply_formula> @ <thf_unit_formula>
thf_formula
: thf_logic_formula { $$ = N(SINGLE, thf_formula, $1); }
| thf_atom_typing   { $$ = N(SINGLE, thf_formula, $1); }
| thf_subtype       { $$ = N(SINGLE, thf_formula, $1); }
| thf_sequent       { $$ = N(SINGLE, thf_formula, $1); }
;

thf_logic_formula
// @solved shift/reduce conflict
// "thf_unary_formula := thf_prefix_unary | thf_infix_unary"
// "thf_infix_unary   := .. Infix_inequality ..""
// we got an anbiguty with "thf_binary_formula Infix_inequality thf_binary_formula"
// solved by removing "thf_unary_formula" and replacing it with "thf_prefix_unary"
// 
//| thf_unary_formula   { $$ = N(thf_logic_formula, $1); }
: thf_prefix_unary    { $$ = N(SINGLE, thf_logic_formula, $1); }
// @solved shift/reduce conflict
// removed thf_unitary_formula since its a subrule of our new thf_binary_formula
//| thf_unitary_formula { $$ = N(thf_logic_formula, $1); }
| thf_binary_formula  { $$ = N(SINGLE, thf_logic_formula, $1); }
// @solved shift/reduce conflict
// "thf_defined_infix  := .. defined_infix_pred .."
// "defined_infix_pred := Infix_equality"
// we got an anbiguty with "thf_binary_formula Infix_equality thf_binary_formula"
// solved by removing "thf_defined_infix" and relaying on thf_binary_formula
//| thf_defined_infix   { $$ = N(thf_logic_formula, $1); }
;

// @speedup
// merged "thf_or_formula, thf_and_formula, thf_app_formula, thf_binary_pair, thf_binary_tuple" to "thf_binary_formula"
thf_binary_formula
: thf_binary_formula App              thf_binary_formula { $$ = N(OPERATOR, thf_binary_formula, $1, $2, $3); }
| thf_binary_formula Assignment       thf_binary_formula { $$ = N(OPERATOR, thf_binary_formula, $1, $2, $3); }
| thf_binary_formula Infix_equality   thf_binary_formula { $$ = N(OPERATOR, thf_binary_formula, $1, $2, $3); }
| thf_binary_formula Infix_inequality thf_binary_formula { $$ = N(OPERATOR, thf_binary_formula, $1, $2, $3); }
| thf_binary_formula And              thf_binary_formula { $$ = N(OPERATOR, thf_binary_formula, $1, $2, $3); }
| thf_binary_formula Or               thf_binary_formula { $$ = N(OPERATOR, thf_binary_formula, $1, $2, $3); }
| thf_binary_formula Nand             thf_binary_formula { $$ = N(OPERATOR, thf_binary_formula, $1, $2, $3); }
| thf_binary_formula Nor              thf_binary_formula { $$ = N(OPERATOR, thf_binary_formula, $1, $2, $3); }
| thf_binary_formula Impl             thf_binary_formula { $$ = N(OPERATOR, thf_binary_formula, $1, $2, $3); }
| thf_binary_formula If               thf_binary_formula { $$ = N(OPERATOR, thf_binary_formula, $1, $2, $3); }
| thf_binary_formula Iff              thf_binary_formula { $$ = N(OPERATOR, thf_binary_formula, $1, $2, $3); }
| thf_binary_formula Niff             thf_binary_formula { $$ = N(OPERATOR, thf_binary_formula, $1, $2, $3); }
| thf_unitary_formula                                    { $$ = N(OPERATOR, thf_binary_formula, $1); }
| thf_binary_type                                        { $$ = N(OPERATOR, thf_binary_formula, $1); }
;

// <thf_unit_formula>     ::= <thf_unitary_formula> | <thf_unary_formula> |
//                            <thf_defined_infix>
// <thf_preunit_formula>  ::= <thf_unitary_formula> | <thf_prefix_unary>
// <thf_unitary_formula>  ::= <thf_quantified_formula> | <thf_atomic_formula> | 
//                            <variable> | (<thf_logic_formula>)
thf_unit_formula
: thf_unitary_formula { $$ = N(SINGLE, thf_unit_formula, $1); }
// @solved shift/reduce conflict
// "thf_unary_formula  := thf_prefix_unary | thf_infix_unary"
// "thf_infix_unary    := thf_unitary_term Infix_inequality thf_unitary_term"
// "thf_defined_infix  := thf_unitary_term defined_infix_pred thf_unitary_term"
// "defined_infix_pred := Infix_equality"
//| thf_unary_formula   { $$ = N(thf_unit_formula, $1); }
//| thf_defined_infix   { $$ = N(thf_unit_formula, $1); }
| thf_prefix_unary { $$ = N(SINGLE, thf_unit_formula, $1); }
| thf_unitary_term Infix_equality thf_unitary_term   { $$ = N(OPERATOR, thf_unit_formula, $1, $2, $3); }
| thf_unitary_term Infix_inequality thf_unitary_term { $$ = N(OPERATOR, thf_unit_formula, $1, $2, $3); }
;

thf_preunit_formula
: thf_unitary_formula thf_prefix_unary { $$ = N(SUFFIX, thf_preunit_formula, $1, $2); }
;

thf_unitary_formula
: thf_quantified_formula { $$ = N(SINGLE, thf_unitary_formula, $1); }
// @solved reduce/reduce conflict
// used thf_unitary_term instead of the following rules since the rules are a subset of thf_unitary_formula
| thf_unitary_term { $$ = N(SINGLE, thf_unitary_formula, $1); }
//| thf_atomic_formula { $$ = N(thf_atomic_formula, $1); }
//| variable { $$ = N(thf_unitary_formula, $1); }
//| LParen thf_logic_formula RParen { $$ = N(thf_unitary_formula, $1); }
;

thf_apply_formula
: thf_apply_formula App thf_unit_formula { $$ = N(OPERATOR, thf_apply_formula, $1, $2, $3); }
| thf_unit_formula App thf_unit_formula  { $$ = N(OPERATOR, thf_apply_formula, $1, $2, $3); }
;

// %----All variables must be quantified
// <thf_quantified_formula> ::= <thf_quantification> <thf_unit_formula>
// <thf_quantification>   ::= <thf_quantifier> [<thf_variable_list>] :
// <thf_variable_list>    ::= <thf_typed_variable> | 
//                            <thf_typed_variable>,<thf_variable_list>
// <thf_typed_variable>   ::= <variable> : <thf_top_level_type>
// <thf_unary_formula>    ::= <thf_prefix_unary> | <thf_infix_unary>
// <thf_prefix_unary>     ::= <thf_unary_connective> <thf_preunit_formula>
// <thf_infix_unary>      ::= <thf_unitary_term> <infix_inequality>
//                            <thf_unitary_term>
// <thf_atomic_formula>   ::= <thf_plain_atomic> | <thf_defined_atomic> |
//                            <thf_system_atomic> | <thf_fof_function>
// <thf_plain_atomic>     ::= <constant> | <thf_tuple> 
// %----Tuples can't be formulae. See TFF. FIX HERE.
// <thf_defined_atomic>   ::= <defined_constant> | <thf_conditional> | <thf_let> |
//                            (<thf_conn_term>) | <defined_term>
// <thf_defined_infix>    ::= <thf_unitary_term> <defined_infix_pred>
//                            <thf_unitary_term>
// %----Defined terms can't be formulae. See TFF. FIX HERE.
// <thf_system_atomic>    ::= <system_constant>
// %----Allows first-order style in THF.
// <thf_fof_function>     ::= <functor>(<thf_arguments>) |
//                            <defined_functor>(<thf_arguments>) |
//                            <system_functor>(<thf_arguments>)
thf_quantified_formula
: thf_quantification thf_unit_formula { N(PREFIX, thf_quantified_formula, $1, $2); }
;

thf_quantification
: thf_quantifier LBrkt thf_variable_list RBrkt Colon { N(BINDER, thf_quantification, $1, $2, $3, $4, $5); }
;

// allow an empty list but not "," or ",x" and such
// equivalent to "thf_variable_list?", "[thf_variable_list]" or "thf_typed_variable*"
thf_variable_list
: thf_variable_list__HELPER0 { $$ = $1; }
| %empty                     { $$ = N(SEPERATED_SEQUENCE, thf_variable_list); }
;
thf_variable_list__HELPER0
: thf_typed_variable Comma thf_variable_list__HELPER0 { $$ = $3.addLeft($2).addLeft($1); }
| thf_typed_variable                                  { $$ = N(SEPERATED_SEQUENCE, thf_variable_list, $1); }
;

thf_typed_variable
: variable Colon thf_top_level_type { $$ = N(OPERATOR, thf_typed_variable, $1, $2, $3); }
;

// @removed by solving ambigulty
//thf_unary_formula
//: thf_prefix_unary { $$ = N(thf_unary_formula, $1); }
//| thf_infix_unary  { $$ = N(thf_unary_formula, $1); }
//;

thf_prefix_unary
: thf_unary_connective { $$ = N(SINGLE, thf_prefix_unary, $1); }
| thf_preunit_formula  { $$ = N(SINGLE, thf_prefix_unary, $1); }
;

// @removed by solving ambigulty
//thf_infix_unary
//: thf_unitary_term Infix_inequality thf_unitary_term { $$ = N(thf_infix_unary, $1, $2, $3); }
//;

thf_atomic_formula
: thf_plain_atomic   { $$ = N(SINGLE, thf_atomic_formula, $1); }
| thf_defined_atomic { $$ = N(SINGLE, thf_atomic_formula, $1); }
| thf_system_atomic  { $$ = N(SINGLE, thf_atomic_formula, $1); }
//| thf_fof_function   { $$ = N(thf_atomic_formula, $1); }
;

thf_plain_atomic
: constant  { $$ = N(SINGLE, thf_plain_atomic, $1); }
| thf_tuple { $$ = N(SINGLE, thf_plain_atomic, $1); }
;

thf_defined_atomic
: defined_constant { $$ = N(SINGLE, thf_defined_atomic, $1); }
| thf_conditional  { $$ = N(SINGLE, thf_defined_atomic, $1); }
| thf_let          { $$ = N(SINGLE, thf_defined_atomic, $1); }
| defined_term     { $$ = N(SINGLE, thf_defined_atomic, $1); }
| LCurly thf_conn_term RCurly { $$ = N(BRACKET, thf_defined_atomic, $1, $2, $3); }
;

// @removed by solving ambigulty
//thf_defined_infix
//: thf_unitary_term defined_infix_pred thf_unitary_term { $$ = N(thf_defined_infix, $1, $2, $3); }
//;

thf_system_atomic
: system_constant { $$ = N(SINGLE, thf_system_atomic, $1); }
;

// <thf_conditional>      ::= $ite(<thf_logic_formula>,<thf_logic_formula>,
//                            <thf_logic_formula>)
// <thf_let>              ::= $let(<thf_let_types>,<thf_let_defns>,<thf_formula>)
// <thf_let_types>        ::= <thf_atom_typing> | [<thf_atom_typing_list>]
// <thf_atom_typing_list> ::= <thf_atom_typing> |
//                            <thf_atom_typing>,<thf_atom_typing_list>
// <thf_let_defns>        ::= <thf_let_defn> | [<thf_let_defn_list>]
// <thf_let_defn>         ::= <thf_logic_formula> <assignment> <thf_logic_formula>
// <thf_let_defn_list>    ::= <thf_let_defn> | <thf_let_defn>,<thf_let_defn_list>

// <thf_unitary_term>     ::= <thf_atomic_formula> | <variable> |
//                            (<thf_logic_formula>)
// <thf_tuple>            ::= [] | [<thf_formula_list>]
// <thf_formula_list>     ::= <thf_logic_formula> |
//                            <thf_logic_formula>,<thf_formula_list>
// <thf_conn_term>        ::= <nonassoc_connective> | <assoc_connective> |
//                            <infix_equality> | <thf_unary_connective>
// %----Note that syntactically this allows (p @ =), but for = the first
// %----argument must be known to infer the type of =, so that's not
// %----allowed, i.e., only (= @ p). 

thf_conditional
: Dollar_ite LParen thf_logic_formula Comma thf_logic_formula Comma thf_logic_formula RParen { $$ = N(NAMED_LIST, thf_conditional, $1, $2, $3, $4, $5, $6, $7, $8); }
;

thf_let
: Dollar_let LParen thf_let_types Comma thf_let_defns Comma thf_formula RParen { $$ = N(NAMED_LIST, thf_let, $1, $2, $3, $4, $5, $6, $7, $8); }
;

thf_let_types
: LBrkt thf_let_types_list RBrkt { $$ = N(BRACKET, thf_let_types, $1, $2, $3); }
| thf_atom_typing                { $$ = N(SINGLE, thf_let_types, $1); }
;

thf_let_types_list
: thf_atom_typing Comma thf_let_types { $$ = $3.addLeft($2).addLeft($1); }
| thf_atom_typing                     { $$ = N(SEPERATED_SEQUENCE, thf_let_types_list, $1); }
;

thf_let_defns
: LBrkt thf_let_defns_list RBrkt { $$ = N(BRACKET, thf_let_defns, $1, $2, $3); }
| thf_let_defn                   { $$ = N(SINGLE, thf_let_defns, $1); }
;

thf_let_defns_list
: thf_let_defn Comma thf_let_defns { $$ = $3.addLeft($2).addLeft($1); }
| thf_let_defn                     { $$ = N(SEPERATED_SEQUENCE, thf_let_defns_list, $1); }
;

thf_let_defn
: thf_logic_formula Assignment thf_logic_formula { $$ = N(OPERATOR, thf_let_defn, $1, $2, $3); }
; 

thf_unitary_term
: thf_atomic_formula { $$ = N(SINGLE, thf_unitary_term, $1); }
| variable           { $$ = N(SINGLE, thf_unitary_term, $1); }
| LParen thf_logic_formula RParen { $$ = N(BRACKET, thf_unitary_term, $1, $2, $3); }
;

thf_tuple
: LBrkt RBrkt                  { $$ = N(BRACKET, thf_tuple, $1, $2); }
| LBrkt thf_formula_list RBrkt { $$ = N(BRACKET, thf_tuple, $1, $2, $3); }

thf_formula_list
: thf_logic_formula Comma thf_formula_list { $$ = $3.addLeft($2).addLeft($1); }
| thf_logic_formula                        { $$ = N(SEPERATED_SEQUENCE, thf_formula_list, $1); }
;

thf_conn_term
: nonassoc_connective  { $$ = N(SINGLE, thf_conn_term, $1); }
| assoc_connective     { $$ = N(SINGLE, thf_conn_term, $1); }
| Infix_equality       { $$ = N(SINGLE, thf_conn_term, $1); }
| thf_unary_connective { $$ = N(SINGLE, thf_conn_term, $1); }
;

// %----Arguments recurse back up to formulae (this is the THF world here)
// <thf_arguments>        ::= <thf_formula_list>

// %----<thf_top_level_type> appears after ":", where a type is being specified
// %----for a term or variable. <thf_unitary_type> includes <thf_unitary_formula>,
// %----so the syntax is very loose, but trying to be more specific about 
// %----<thf_unitary_type>s (ala the semantic rule) leads to reduce/reduce 
// %----conflicts.
// <thf_atom_typing>      ::= <untyped_atom> : <thf_top_level_type> |
//                            (<thf_atom_typing>)
// <thf_top_level_type>   ::= <thf_unitary_type> | <thf_mapping_type> |
//                            <thf_apply_type>
// %----Removed along with adding <thf_binary_type> to <thf_binary_formula>, for
// %----TH1 polymorphic types with binary after quantification.
// %----      | (<thf_binary_type>)
// <thf_unitary_type>     ::= <thf_unitary_formula>
// <thf_unitary_type>     :== <thf_atomic_type> | <th1_quantified_type>
// <thf_atomic_type>      :== <type_constant> | <defined_type> | <variable> |
//                            <thf_mapping_type> | ( <thf_atomic_type> )
// <th1_quantified_type>  :== !> [<thf_variable_list>] : <thf_unitary_type>

thf_atom_typing
: untyped_atom Colon thf_top_level_type { $$ = N(OPERATOR, thf_atom_typing, $1, $2, $3); }
| LParen thf_atom_typing RParen         { $$ = N(BRACKET, thf_atom_typing, $1, $2, $3); }
;

thf_top_level_type
: thf_unitary_type { $$ = N(SINGLE, thf_top_level_type, $1); }
| thf_mapping_type { $$ = N(SINGLE, thf_top_level_type, $1); }
| thf_apply_type   { $$ = N(SINGLE, thf_top_level_type, $1); }
;

thf_unitary_type
: thf_unitary_formula { $$ = N(SINGLE, thf_unitary_type, $1); }
;

// <thf_apply_type>       ::= <thf_apply_formula>
// <thf_binary_type>      ::= <thf_mapping_type> | <thf_xprod_type> |
//                            <thf_union_type> 
// %----Mapping is right-associative: o > o > o means o > (o > o).
// <thf_mapping_type>     ::= <thf_unitary_type> <arrow> <thf_unitary_type> |
//                            <thf_unitary_type> <arrow> <thf_mapping_type>
// %----Xproduct is left-associative: o * o * o means (o * o) * o. Xproduct
// %----can be replaced by tuple types.
// <thf_xprod_type>       ::= <thf_unitary_type> <star> <thf_unitary_type> |
//                            <thf_xprod_type> <star> <thf_unitary_type>
// %----Union is left-associative: o + o + o means (o + o) + o.
// <thf_union_type>       ::= <thf_unitary_type> <plus> <thf_unitary_type> |
//                            <thf_union_type> <plus> <thf_unitary_type>
// %----Tuple types, e.g., [a,b,c], are allowed (by the loose syntax) as tuples.
// <thf_subtype>          ::= <untyped_atom> <subtype_sign> <atom>

// <thf_sequent>          ::= <thf_tuple> <gentzen_arrow> <thf_tuple> |
//                            (<thf_sequent>)
thf_apply_type
: thf_apply_formula { $$ = N(SINGLE, thf_apply_type, $1); }
;

thf_binary_type
: thf_mapping_type { $$ = N(SINGLE, thf_binary_type, $1); }
| thf_xprod_type   { $$ = N(SINGLE, thf_binary_type, $1); }
| thf_union_type   { $$ = N(SINGLE, thf_binary_type, $1); }
;

thf_mapping_type
: thf_unitary_type Arrow thf_unitary_type { $$ = N(OPERATOR, thf_mapping_type, $1, $2, $3); }
| thf_unitary_type Arrow thf_mapping_type { $$ = N(OPERATOR, thf_mapping_type, $1, $2, $3); }
;

thf_xprod_type
: thf_unitary_type Star thf_unitary_type { $$ = N(OPERATOR, thf_xprod_type, $1, $2, $3); }
| thf_xprod_type Star thf_unitary_type   { $$ = N(OPERATOR, thf_xprod_type, $1, $2, $3); }
;

thf_union_type
: thf_unitary_type Plus thf_unitary_type { $$ = N(OPERATOR, thf_union_type, $1, $2, $3); }
| thf_union_type Plus thf_unitary_type   { $$ = N(OPERATOR, thf_union_type, $1, $2, $3); }
;

thf_subtype
: untyped_atom Subtype_sign atom { $$ = N(OPERATOR, thf_subtype, $1, $2, $3); }
;

thf_sequent
: thf_tuple Gentzen_arrow thf_tuple { $$ = N(OPERATOR, thf_sequent, $1, $2, $3); }
| LParen thf_sequent RParen         { $$ = N(BRACKET, thf_sequent, $1, $2, $3); }

// %----New material for modal logic semantics, not integrated yet
// <logic_defn_rule>      :== <logic_defn_LHS> <assignment> <logic_defn_RHS>
// <logic_defn_LHS>       :== <logic_defn_value> | <thf_top_level_type>  | <name>
// <logic_defn_LHS>       :== $constants | $quantification | $consequence |
//                            $modalities
// %----The $constants, $quantification, and $consequence apply to all of the
// %----$modalities. Each of these may be specified only once, but not necessarily
// %----all in a single annotated formula.
// <logic_defn_RHS>       :== <logic_defn_value> | <thf_unitary_formula>
// <logic_defn_value>     :== <defined_constant>
// <logic_defn_value>     :== $rigid | $flexible |
//                            $constant | $varying | $cumulative | $decreasing |
//                            $local | $global |
//                            $modal_system_K | $modal_system_T | $modal_system_D |
//                            $modal_system_S4 | $modal_system_S5 |
//                            $modal_axiom_K | $modal_axiom_T | $modal_axiom_B |
//                            $modal_axiom_D | $modal_axiom_4 | $modal_axiom_5

// %------------------------------------------------------------------------------
// %----TFF formulae.
// <tff_formula>          ::= <tff_logic_formula> | <tff_atom_typing> |
//                            <tff_subtype> | <tfx_sequent>
// <tff_logic_formula>    ::= <tff_unitary_formula> | <tff_unary_formula> | 
//                            <tff_binary_formula> | <tff_defined_infix>
// %----<tff_defined_infix> up here to avoid confusion in a = b | p, for TFX.
// %----For plain TFF it can be in <tff_defined_atomic>

// <tff_binary_formula>   ::= <tff_binary_nonassoc> | <tff_binary_assoc>
// <tff_binary_nonassoc>  ::= <tff_unit_formula> <nonassoc_connective>
//                            <tff_unit_formula>
// <tff_binary_assoc>     ::= <tff_or_formula> | <tff_and_formula>
// <tff_or_formula>       ::= <tff_unit_formula> <vline> <tff_unit_formula> |
//                            <tff_or_formula> <vline> <tff_unit_formula>
// <tff_and_formula>      ::= <tff_unit_formula> & <tff_unit_formula> |
//                            <tff_and_formula> & <tff_unit_formula>
// <tff_unit_formula>     ::= <tff_unitary_formula> | <tff_unary_formula> | 
//                            <tff_defined_infix>
// <tff_preunit_formula>  ::= <tff_unitary_formula> | <tff_prefix_unary>
// <tff_unitary_formula>  ::= <tff_quantified_formula> | <tff_atomic_formula> |
//                            <tfx_unitary_formula> | (<tff_logic_formula>)
// <tfx_unitary_formula>  ::= <variable>
// <tff_quantified_formula> ::= <fof_quantifier> [<tff_variable_list>] :
//                            <tff_unit_formula>
// %----Quantified formulae bind tightly, so cannot include infix formulae

// <tff_variable_list>    ::= <tff_variable> | <tff_variable>,<tff_variable_list>
// <tff_variable>         ::= <tff_typed_variable> | <variable>
// <tff_typed_variable>   ::= <variable> : <tff_atomic_type>
// <tff_unary_formula>    ::= <tff_prefix_unary> | <tff_infix_unary>
// %FOR PLAIN TFF <fof_infix_unary>
// <tff_prefix_unary>     ::= <unary_connective> <tff_preunit_formula>
// <tff_infix_unary>      ::= <tff_unitary_term> <infix_inequality> 
//                            <tff_unitary_term>

// %FOR PLAIN TFF <tff_atomic_formula>   ::= <fof_atomic_formula>
// <tff_atomic_formula>   ::= <tff_plain_atomic> | <tff_defined_atomic> |
//                            <tff_system_atomic>
// <tff_plain_atomic>     ::= <constant> | <functor>(<tff_arguments>)
// <tff_plain_atomic>     :== <proposition> | <predicate>(<tff_arguments>)
// <tff_defined_atomic>   ::= <tff_defined_plain> 
// %---To avoid confusion in TFX mode a = b | p   | <tff_defined_infix>
// <tff_defined_plain>    ::= <defined_constant> |
//                            <defined_functor>(<tff_arguments>) |
//                            <tfx_conditional> | <tfx_let>
// <tff_defined_plain>    :== <defined_proposition> |
//                            <defined_predicate>(<tff_arguments>) |
//                            <tfx_conditional> | <tfx_let>
// %----This is the only one that is strictly a formula, type $o
// <tff_defined_infix>    ::= <tff_unitary_term> <defined_infix_pred> 
//                            <tff_unitary_term>
// <tff_system_atomic>    ::= <system_constant> | 
//                            <system_functor>(<tff_arguments>)
// <tff_system_atomic>    :== <system_proposition> | 
//                            <system_predicate>(<tff_arguments>)
// <tfx_conditional>      ::= $ite(<tff_logic_formula>,<tff_term>,<tff_term>)
// <tfx_let>              ::= $let(<tfx_let_types>,<tfx_let_defns>,<tff_term>)
// <tfx_let_types>        ::= <tff_atom_typing> | [<tff_atom_typing_list>]
// <tff_atom_typing_list> ::= <tff_atom_typing> | 
//                            <tff_atom_typing>,<tff_atom_typing_list>
// <tfx_let_defns>        ::= <tfx_let_defn> | [<tfx_let_defn_list>]
// <tfx_let_defn>         ::= <tfx_let_LHS> <assignment> <tff_term>
// <tfx_let_LHS>          ::= <tff_plain_atomic> | <tfx_tuple>
// <tfx_let_defn_list>    ::= <tfx_let_defn> | <tfx_let_defn>,<tfx_let_defn_list>

// <tff_term>             ::= <tff_logic_formula> | <defined_term> | <tfx_tuple>
// <tff_unitary_term>     ::= <tff_atomic_formula> | <defined_term> | 
//                            <tfx_tuple> | <variable> | (<tff_logic_formula>)
// <tfx_tuple>            ::= [] | [<tff_arguments>]

// <tff_arguments>        ::= <tff_term> | <tff_term>,<tff_arguments>

// %----<tff_atom_typing> can appear only at top level.
// <tff_atom_typing>      ::= <untyped_atom> : <tff_top_level_type> |
//                            (<tff_atom_typing>)
// <tff_top_level_type>   ::= <tff_atomic_type> | <tff_mapping_type> |
//                            <tf1_quantified_type> | (<tff_top_level_type>)
// <tf1_quantified_type>  ::= !> [<tff_variable_list>] : <tff_monotype>
// <tff_monotype>         ::= <tff_atomic_type> | (<tff_mapping_type>)
// <tff_unitary_type>     ::= <tff_atomic_type> | (<tff_xprod_type>)
// <tff_atomic_type>      ::= <type_constant> | <defined_type> | 
//                            <type_functor>(<tff_type_arguments>) | <variable> |
//                            <tfx_tuple_type>
// <tff_type_arguments>   ::= <tff_atomic_type> |
//                            <tff_atomic_type>,<tff_type_arguments>
// <tff_mapping_type>     ::= <tff_unitary_type> <arrow> <tff_atomic_type>
// <tff_xprod_type>       ::= <tff_unitary_type> <star> <tff_atomic_type> |
//                            <tff_xprod_type> <star> <tff_atomic_type>
// %----For TFX only
// <tfx_tuple_type>       ::= [<tff_type_list>]
// <tff_type_list>        ::= <tff_top_level_type> |
//                            <tff_top_level_type>,<tff_type_list>

// <tff_subtype>          ::= <untyped_atom> <subtype_sign> <atom> 

// <tfx_sequent>          ::= <tfx_tuple> <gentzen_arrow> <tfx_tuple> | 
//                            (<tfx_sequent>)

// %------------------------------------------------------------------------------
// %----TCF formulae.
// <tcf_formula>          ::= <tcf_logic_formula> | <tff_atom_typing>
// <tcf_logic_formula>    ::= <tcf_quantified_formula> | <cnf_formula>
// <tcf_quantified_formula> ::= ! [<tff_variable_list>] : <cnf_formula>

// %------------------------------------------------------------------------------
// %----FOF formulae.
// <fof_formula>          ::= <fof_logic_formula> | <fof_sequent>
// <fof_logic_formula>    ::= <fof_binary_formula> | <fof_unary_formula> |
//                            <fof_unitary_formula>
// %----Future answer variable ideas | <answer_formula>
// <fof_binary_formula>   ::= <fof_binary_nonassoc> | <fof_binary_assoc>
// %----Only some binary connectives are associative
// %----There's no precedence among binary connectives
// <fof_binary_nonassoc>  ::= <fof_unit_formula> <nonassoc_connective>
//                            <fof_unit_formula>
// %----Associative connectives & and | are in <binary_assoc>
// <fof_binary_assoc>     ::= <fof_or_formula> | <fof_and_formula>
// <fof_or_formula>       ::= <fof_unit_formula> <vline> <fof_unit_formula> |
//                            <fof_or_formula> <vline> <fof_unit_formula>
// <fof_and_formula>      ::= <fof_unit_formula> & <fof_unit_formula> |
//                            <fof_and_formula> & <fof_unit_formula>
// <fof_unary_formula>    ::= <unary_connective> <fof_unit_formula> |
//                            <fof_infix_unary>
// %----<fof_term> != <fof_term> is equivalent to ~ <fof_term> = <fof_term>
// <fof_infix_unary>      ::= <fof_term> <infix_inequality> <fof_term>
// %----<fof_unitary_formula> are in ()s or do not have a connective
// <fof_unit_formula>     ::= <fof_unitary_formula> | <fof_unary_formula>
// <fof_unitary_formula>  ::= <fof_quantified_formula> | <fof_atomic_formula> | 
//                            (<fof_logic_formula>)
// %----All variables must be quantified
// <fof_quantified_formula> ::= <fof_quantifier> [<fof_variable_list>] :
//                            <fof_unit_formula>
// <fof_variable_list>    ::= <variable> | <variable>,<fof_variable_list>
// <fof_atomic_formula>   ::= <fof_plain_atomic_formula> | 
//                            <fof_defined_atomic_formula> |
//                            <fof_system_atomic_formula>
// <fof_plain_atomic_formula> ::= <fof_plain_term>
// <fof_plain_atomic_formula> :== <proposition> | <predicate>(<fof_arguments>)
// <fof_defined_atomic_formula> ::= <fof_defined_plain_formula> | 
//                            <fof_defined_infix_formula>
// <fof_defined_plain_formula> ::= <fof_defined_plain_term>
// <fof_defined_plain_formula> :== <defined_proposition> | 
//                            <defined_predicate>(<fof_arguments>)
// <fof_defined_infix_formula> ::= <fof_term> <defined_infix_pred> <fof_term>
// %----System terms have system specific interpretations
// <fof_system_atomic_formula> ::= <fof_system_term>
// %----<fof_system_atomic_formula>s are used for evaluable predicates that are
// %----available in particular tools. The predicate names are not controlled by 
// %----the TPTP syntax, so use with due care. Same for <fof_system_term>s.

// %----FOF terms.
// <fof_plain_term>       ::= <constant> | <functor>(<fof_arguments>)
// %----Defined terms have TPTP specific interpretations
// <fof_defined_term>     ::= <defined_term> | <fof_defined_atomic_term>
// <fof_defined_atomic_term>  ::= <fof_defined_plain_term>
// %----None yet             | <defined_infix_term>
// %----None yet <defined_infix_term> ::= <fof_term> <defined_infix_func> <fof_term>
// %----None yet <defined_infix_func> ::=
// <fof_defined_plain_term>   ::= <defined_constant> | 
//                            <defined_functor>(<fof_arguments>)
// %----System terms have system specific interpretations
// <fof_system_term>      ::= <system_constant> | <system_functor>(<fof_arguments>)
// %----Arguments recurse back to terms (this is the FOF world here)
// <fof_arguments>        ::= <fof_term> | <fof_term>,<fof_arguments>
// %----These are terms used as arguments. Not the entry point for terms because
// %----<fof_plain_term> is also used as <fof_plain_atomic_formula>. The <tff_
// %----options are for only TFF, but are here because <fof_plain_atomic_formula> 
// %----is used in <fof_atomic_formula>, which is also used as 
// %----<tff_atomic_formula>.
// <fof_term>             ::= <fof_function_term> | <variable>
// <fof_function_term>    ::= <fof_plain_term> | <fof_defined_term> | 
//                            <fof_system_term>

// %------------------------------------------------------------------------------
// %----This section is the FOFX syntax. Not yet in use.
// <fof_sequent>          ::= <fof_formula_tuple> <gentzen_arrow>
//                            <fof_formula_tuple> | (<fof_sequent>)// 

// <fof_formula_tuple>    ::= {} | {<fof_formula_tuple_list>}
// <fof_formula_tuple_list> ::= <fof_logic_formula> |
//                            <fof_logic_formula>,<fof_formula_tuple_list>

// %------------------------------------------------------------------------------
// %----CNF formulae (variables implicitly universally quantified)
// <cnf_formula>          ::= <disjunction> | (<disjunction>)
// <disjunction>          ::= <literal> | <disjunction> <vline> <literal>
// <literal>              ::= <fof_atomic_formula> | ~ <fof_atomic_formula> |
//                            <fof_infix_unary>

// %------------------------------------------------------------------------------
// %----Connectives - THF
// <thf_quantifier>       ::= <fof_quantifier> | <th0_quantifier> |
//                            <th1_quantifier>
// %----TH0 quantifiers are also available in TH1
// <th1_quantifier>       ::= !> | ?*
// <th0_quantifier>       ::= ^ | @+ | @-
// <thf_unary_connective> ::= <unary_connective> | <th1_unary_connective>
// <th1_unary_connective> ::= !! | ?? | @@+ | @@- | @=
// %----Connectives - THF and TFF
// <subtype_sign>         ::= <<
// %----Connectives - TFF
// %----Connectives - FOF
// <fof_quantifier>       ::= ! | ?
// <nonassoc_connective>  ::= <=> | => | <= | <~> | ~<vline> | ~&
// <assoc_connective>     ::= <vline> | &
// <unary_connective>     ::= ~
// %----The seqent arrow
// <gentzen_arrow>        ::= -->
// <assignment>           ::= :=
thf_quantifier
: fof_quantifier { $$ = N(SINGLE, thf_quantifier, $1); }
| th0_quantifier { $$ = N(SINGLE, thf_quantifier, $1); }
| th1_quantifier { $$ = N(SINGLE, thf_quantifier, $1); }
;

th1_quantifier
: TyForall { $$ = N(SINGLE, th1_quantifier, $1); }
| TyExists { $$ = N(SINGLE, th1_quantifier, $1); }
;

th0_quantifier
: Lambda      { $$ = N(SINGLE, th0_quantifier, $1); }
| Choice      { $$ = N(SINGLE, th0_quantifier, $1); }
| Description { $$ = N(SINGLE, th0_quantifier, $1); }
;

thf_unary_connective
: unary_connective     { $$ = N(SINGLE, thf_unary_connective, $1); }
| th1_unary_connective { $$ = N(SINGLE, thf_unary_connective, $1); }
; 

th1_unary_connective
: ForallComb      { $$ = N(SINGLE, th1_unary_connective, $1); }
| ExistsComb      { $$ = N(SINGLE, th1_unary_connective, $1); }
| ChoiceComb      { $$ = N(SINGLE, th1_unary_connective, $1); }
| DescriptionComb { $$ = N(SINGLE, th1_unary_connective, $1); }
| EqComb          { $$ = N(SINGLE, th1_unary_connective, $1); }
;

fof_quantifier
: Forall { $$ = N(SINGLE, fof_quantifier, $1); }
| Exists { $$ = N(SINGLE, fof_quantifier, $1); }
;

nonassoc_connective
: Iff  { $$ = N(SINGLE, nonassoc_connective, $1); }
| Impl { $$ = N(SINGLE, nonassoc_connective, $1); }
| If   { $$ = N(SINGLE, nonassoc_connective, $1); }
| Niff { $$ = N(SINGLE, nonassoc_connective, $1); }
| Nor  { $$ = N(SINGLE, nonassoc_connective, $1); }
| Nand { $$ = N(SINGLE, nonassoc_connective, $1); }
;

assoc_connective
: Or  { $$ = N(SINGLE, assoc_connective, $1); }
| And { $$ = N(SINGLE, assoc_connective, $1); }
;

unary_connective
: Not { $$ = N(SINGLE, unary_connective, $1); }
;

// %----Types for THF and TFF
// <type_constant>        ::= <type_functor>
// <type_functor>         ::= <atomic_word>
// <defined_type>         ::= <atomic_defined_word>
// <defined_type>         :== $oType | $o | $iType | $i | $tType |
//                            $real | $rat | $int
// %----$oType/$o is the Boolean type, i.e., the type of $true and $false.
// %----$iType/$i is non-empty type of individuals, which may be finite or
// %----infinite. $tType is the type of all types. $real is the type of <real>s.
// %----$rat is the type of <rational>s. $int is the type of <signed_integer>s
// %----and <unsigned_integer>s.
// <system_type>          :== <atomic_system_word>

// %----For all language types
// <atom>                 ::= <untyped_atom> | <defined_constant>
// <untyped_atom>         ::= <constant> | <system_constant>

// <proposition>          :== <predicate>
// <predicate>            :== <atomic_word>
// <defined_proposition>  :== <defined_predicate>
// <defined_proposition>  :== $true | $false
// <defined_predicate>    :== <atomic_defined_word>
// <defined_predicate>    :== $distinct |
//                            $less | $lesseq | $greater | $greatereq |
//                            $is_int | $is_rat |
//                            $box_P | $box_i | $box_int | $box |
//                            $dia_P | $dia_i | $dia_int | $dia
// %----$distinct means that each of it's constant arguments are pairwise !=. It
// %----is part of the TFF syntax. It can be used only as a fact in an axiom (not
// %----a conjecture), and not under any connective.
// <defined_infix_pred>   ::= <infix_equality>
// <system_proposition>   :== <system_predicate>
// <system_predicate>     :== <atomic_system_word>
// <infix_equality>       ::= =
// <infix_inequality>     ::= !=
atom
: untyped_atom     { $$ = N(SINGLE, atom, $1); }
| defined_constant { $$ = N(SINGLE, atom, $1); }
;

untyped_atom
: constant        { $$ = N(SINGLE, untyped_atom, $1); }
| system_constant { $$ = N(SINGLE, untyped_atom, $1); }
;

// @removed by solving ambigulty
//defined_infix_pred
//: Infix_equality { $$ = N(defined_infix_pred, $1); }
//;

// <constant>             ::= <functor>
// <functor>              ::= <atomic_word>
// <system_constant>      ::= <system_functor>
// <system_functor>       ::= <atomic_system_word>
// <defined_constant>     ::= <defined_functor>
// <defined_functor>      ::= <atomic_defined_word>
// <defined_functor>      :== $uminus | $sum | $difference | $product |
//                            $quotient | $quotient_e | $quotient_t | $quotient_f |
//                            $remainder_e | $remainder_t | $remainder_f |
//                            $floor | $ceiling | $truncate | $round |
//                            $to_int | $to_rat | $to_real
// <defined_term>         ::= <number> | <distinct_object>
// <variable>             ::= <upper_word>
constant
: functor { $$ = N(SINGLE, constant, $1); }
; 

functor
: atomic_word { $$ = N(SINGLE, functor, $1); }
; 

system_constant
: system_functor { $$ = N(SINGLE, system_constant, $1); }
;

system_functor
: atomic_system_word { $$ = N(SINGLE, system_functor, $1); }
;

defined_constant
: defined_functor { $$ = N(SINGLE, defined_constant, $1); }
;

defined_functor
: atomic_defined_word { $$ = N(SINGLE, defined_functor, $1); }
;

defined_term
: number          { $$ = N(SINGLE, defined_term, $1); }
| distinct_object { $$ = N(SINGLE, defined_term, $1); }
;

variable 
: Upper_word { $$ = N(SINGLE, variable, $1); }
;

// %------------------------------------------------------------------------------
// %----Formula sources
// <source>               ::= <general_term>
// <source>               :== <dag_source> | <internal_source> |
//                            <external_source> | unknown | [<sources>]
// %----Alternative sources are recorded like this, thus allowing representation
// %----of alternative derivations with shared parts.
// <sources>              :== <source> | <source>,<sources>
// %----Only a <dag_source> can be a <name>, i.e., derived formulae can be
// %----identified by a <name> or an <inference_record>
// <dag_source>           :== <name> | <inference_record>
// <inference_record>     :== inference(<inference_rule>,<useful_info>,
//                            <inference_parents>)
// <inference_rule>       :== <atomic_word>
// %----Examples are          deduction | modus_tollens | modus_ponens | rewrite |
// %                          resolution | paramodulation | factorization |
// %                          cnf_conversion | cnf_refutation | ...
// %----<inference_parents> can be empty in cases when there is a justification
// %----for a tautologous theorem. In case when a tautology is introduced as
// %----a leaf, e.g., for splitting, then use an <internal_source>.
// <inference_parents>    :== [] | [<parent_list>]
// <parent_list>          :== <parent_info> | <parent_info>,<parent_list>
// <parent_info>          :== <source><parent_details>
// <parent_details>       :== :<general_list> | <null>
// <internal_source>      :== introduced(<intro_type><optional_info>)
// <intro_type>           :== definition | axiom_of_choice | tautology | assumption
// %----This should be used to record the symbol being defined, or the function
// %----for the axiom of choice
// <external_source>      :== <file_source> | <theory> | <creator_source>
// <file_source>          :== file(<file_name><file_info>)
// <file_info>            :== ,<name> | <null>
// <theory>               :== theory(<theory_name><optional_info>)
// <theory_name>          :== equality | ac
// %----More theory names may be added in the future. The <optional_info> is
// %----used to store, e.g., which axioms of equality have been implicitly used,
// %----e.g., theory(equality,[rst]). Standard format still to be decided.
// <creator_source>       :== creator(<creator_name><optional_info>)
// <creator_name>         :== <atomic_word>
source
: general_term { $$ = N(SINGLE, source, $1); }

// %----Useful info fields
// <optional_info>        ::= ,<useful_info> | <null>
// <useful_info>          ::= <general_list>
// <useful_info>          :== [] | [<info_items>]
// <info_items>           :== <info_item> | <info_item>,<info_items>
// <info_item>            :== <formula_item> | <inference_item> |
//                            <general_function>
// %----Useful info for formula records
// <formula_item>         :== <description_item> | <iquote_item>
// <description_item>     :== description(<atomic_word>)
// <iquote_item>          :== iquote(<atomic_word>)
// %----<iquote_item>s are used for recording exactly what the system output about
// %----the inference step. In the future it is planned to encode this information
// %----in standardized forms as <parent_details> in each <inference_record>.
// %----Useful info for inference records
// <inference_item>       :== <inference_status> | <assumptions_record> |
//                            <new_symbol_record> | <refutation>
// <inference_status>     :== status(<status_value>) | <inference_info>
// %----These are the success status values from the SZS ontology. The most
// %----commonly used values are:
// %----  thm - Every model of the parent formulae is a model of the inferred
// %----        formula. Regular logical consequences.
// %----  cth - Every model of the parent formulae is a model of the negation of
// %----        the inferred formula. Used for negation of conjectures in FOF to
// %----        CNF conversion.
// %----  esa - There exists a model of the parent formulae iff there exists a
// %----        model of the inferred formula. Used for Skolemization steps.
// %----For the full hierarchy see the SZSOntology file distributed with the TPTP.
// <status_value>         :== suc | unp | sap | esa | sat | fsa | thm | eqv | tac |
//                            wec | eth | tau | wtc | wth | cax | sca | tca | wca |
//                            cup | csp | ecs | csa | cth | ceq | unc | wcc | ect |
//                            fun | uns | wuc | wct | scc | uca | noc
// %----<inference_info> is used to record standard information associated with an
// %----arbitrary inference rule. The <inference_rule> is the same as the
// %----<inference_rule> of the <inference_record>. The <atomic_word> indicates
// %----the information being recorded in the <general_list>. The <atomic_word>
// %----are (loosely) set by TPTP conventions, and include esplit, sr_split, and
// %----discharge.
// <inference_info>       :== <inference_rule>(<atomic_word>,<general_list>)
// %----An <assumptions_record> lists the names of assumptions upon which this
// %----inferred formula depends. These must be discharged in a completed proof.
// <assumptions_record>   :== assumptions([<name_list>])
// %----A <refutation> record names a file in which the inference recorded here
// %----is recorded as a proof by refutation.
// <refutation>           :== refutation(<file_source>)
// %----A <new_symbol_record> provides information about a newly introduced symbol.
// <new_symbol_record>    :== new_symbols(<atomic_word>,[<new_symbol_list>])
// <new_symbol_list>      :== <principal_symbol> |
//                            <principal_symbol>,<new_symbol_list>
// %----Principal symbols are predicates, functions, variables
// <principal_symbol>   :== <functor> | <variable>

// %----Include directives
// <include>              ::= include(<file_name><formula_selection>).
// <formula_selection>    ::= ,[<name_list>] | <null>
// <name_list>            ::= <name> | <name>,<name_list>
optional_info
: Comma useful_info { $$ = N(PREFIX, optional_info, $1, $2); }
;

useful_info
: general_list { $$ = N(SINGLE, useful_info, $1); }
;

include
: DefinitionInclude file_name formula_selection DefinitionEnd { $$ = N(BRACKET, include, $1, $2, $3, $4); }
;

formula_selection
: Comma LBrkt name_list RBrkt { $$ = N(BRACKET, formula_selection, $1, $2, $3, $4); }
| %empty {}
;

name_list
: name                 { $$ = N(SINGLE, name_list, $1); }
| name Comma name_list { $$ = N(OPERATOR, name_list, $1, $2, $3); }
;

// %----Non-logical data
// <general_term>         ::= <general_data> | <general_data>:<general_term> |
//                            <general_list>
// <general_data>         ::= <atomic_word> | <general_function> |
//                            <variable> | <number> | <distinct_object> |
//                            <formula_data>
// <general_function>     ::= <atomic_word>(<general_terms>)
// %----A <general_data> bind() term is used to record a variable binding in an
// %----inference, as an element of the <parent_details> list.
// <general_data>         :== bind(<variable>,<formula_data>)
// <formula_data>         ::= $thf(<thf_formula>) | $tff(<tff_formula>) |
//                            $fof(<fof_formula>) | $cnf(<cnf_formula>) |
//                            $fot(<fof_term>)
// <general_list>         ::= [] | [<general_terms>]
// <general_terms>        ::= <general_term> | <general_term>,<general_terms>
general_term
: general_data                    { $$ = N(SINGLE, general_term, $1); }
| general_list                    { $$ = N(SINGLE, general_term, $1); }
| general_data Colon general_term { $$ = N(OPERATOR, general_term, $1, $2, $3); }
;

general_function
: atomic_word LParen general_terms RParen { $$ = N(NAMED_BRACKET, general_function, $1, $2, $3, $4); }

general_data
: atomic_word      { $$ = N(SINGLE, general_data, $1); }
| general_function { $$ = N(SINGLE, general_data, $1); }
| variable         { $$ = N(SINGLE, general_data, $1); }
| number           { $$ = N(SINGLE, general_data, $1); }
| distinct_object  { $$ = N(SINGLE, general_data, $1); }
| formula_data     { $$ = N(SINGLE, general_data, $1); }
;

formula_data
: Dollar_thf LParen thf_formula RParen   { $$ = N(NAMED_BRACKET, formula_data, $1, $2, $3, $4); }
//| Dollar_tff LParen tff_formula RParen { $$ = N(formula_data, $1, $2, $3, $4); }
//| Dollar_fof LParen fof_formula RParen { $$ = N(formula_data, $1, $2, $3, $4); }
//| Dollar_cnf LParen cnf_formula RParen { $$ = N(formula_data, $1, $2, $3, $4); }
//| Dollar_fot LParen fot_formula RParen { $$ = N(formula_data, $1, $2, $3, $4); }
;

general_list
: LBrkt RBrkt               { $$ = N(BRACKET, general_list, $1, $2); }
| LBrkt general_terms RBrkt { $$ = N(BRACKET, general_list, $1, $2, $3); }
;

general_terms
: general_term Comma general_terms { $$ = $3.addLeft($2).addLeft($1); }
| general_term                     { $$ = N(SEPERATED_SEQUENCE, general_terms, $1); }
;

// %----General purpose
// <name>                 ::= <atomic_word> | <integer>
// %----Integer names are expected to be unsigned
// <atomic_word>          ::= <lower_word> | <single_quoted>
name
: atomic_word { $$ = N(SINGLE, name, $1);}
| Integer     { $$ = N(SINGLE, name, $1); }
;

atomic_word
: Lower_word    { $$ = N(SINGLE, atomic_word, $1);}
| single_quoted { $$ = N(SINGLE, atomic_word, $1); }
; 

// %----<single_quoted> tokens do not include their outer quotes, therefore the
// %----<lower_word> <atomic_word> cat and the <single_quoted> <atomic_word> 'cat'
// %----are the same. Quotes must be removed from a <single_quoted> <atomic_word>
// %----if doing so produces a <lower_word> <atomic_word>. Note that <numbers>s
// %----and <variable>s are not <lower_word>s, so '123' and 123, and 'X' and X,
// %----are different.
// <atomic_defined_word>  ::= <dollar_word>
// <atomic_system_word>   ::= <dollar_dollar_word>
// <number>               ::= <integer> | <rational> | <real>
// %----Numbers are always interpreted as themselves, and are thus implicitly
// %----distinct if they have different values, e.g., 1 != 2 is an implicit axiom.
// %----All numbers are base 10 at the moment.
// <file_name>            ::= <single_quoted>
// <null>                 ::=
// %------------------------------------------------------------------------------
// %----Rules from here on down are for defining tokens (terminal symbols) of the
// %----grammar, assuming they will be recognized by a lexical scanner.
// %----A ::- rule defines a token, a ::: rule defines a macro that is not a
// %----token. Usual regexp notation is used. Single characters are always placed
// %----in []s to disable any special meanings (for uniformity this is done to
// %----all characters, not only those with special meanings).
// %----These are tokens that appear in the syntax rules above. No rules
// %----defined here because they appear explicitly in the syntax rules,
// %----except that <vline>, <star>, <plus> denote "|", "*", "+", respectively.
// %----Keywords:    fof cnf thf tff include
// %----Punctuation: ( ) , . [ ] :
// %----Operators:   ! ? ~ & | <=> => <= <~> ~| ~& * +
// %----Predicates:  = != $true $false
atomic_defined_word
: Dollar_word { $$ = N(SINGLE, atomic_defined_word, $1); }
;

atomic_system_word
: Dollar_dollar_word { $$ = N(SINGLE, atomic_system_word, $1); }
;

number
: Integer  { $$ = N(SINGLE, number, $1); }
| Rational { $$ = N(SINGLE, number, $1); }
| Real     { $$ = N(SINGLE, number, $1); }
;

file_name
: single_quoted { $$ = N(SINGLE, file_name, $1); }
;

// %----For lex/yacc there cannot be spaces on either side of the | here
// <comment>              ::- <comment_line>|<comment_block>
// <comment_line>         ::- [%]<printable_char>*
// <comment_block>        ::: [/][*]<not_star_slash>[*][*]*[/]
// <not_star_slash>       ::: ([^*]*[*][*]*[^/*])*[^*]*
// %----Defined comments are a convention used for annotations that are used as
// %----additional input for systems. They look like comments, but start with %$
// %----or /*$. A wily user of the syntax can notice the $ and extract information
// %----from the "comment" and pass that on as input to the system. They are
// %----analogous to pragmas in programming languages. To extract these separately
// %----from regular comments, the rules are:
// %----  <defined_comment>    ::- <def_comment_line>|<def_comment_block>
// %----  <def_comment_line>   ::: [%]<dollar><printable_char>*
// %----  <def_comment_block>  ::: [/][*]<dollar><not_star_slash>[*][*]*[/]
// %----A string that matches both <defined_comment> and <comment> should be
// %----recognized as <defined_comment>, so put these before <comment>.
// %----Defined comments that are in use include:
// %----    TO BE ANNOUNCED
// %----System comments are a convention used for annotations that may used as
// %----additional input to a specific system. They look like comments, but start
// %----with %$$ or /*$$. A wily user of the syntax can notice the $$ and extract
// %----information from the "comment" and pass that on as input to the system.
// %----The specific system for which the information is intended should be
// %----identified after the $$, e.g., /*$$Otter 3.3: Demodulator */
// %----To extract these separately from regular comments, the rules are:
// %----  <system_comment>     ::- <sys_comment_line>|<sys_comment_block>
// %----  <sys_comment_line>   ::: [%]<dollar><dollar><printable_char>*
// %----  <sys_comment_block>  ::: [/][*]<dollar><dollar><not_star_slash>[*][*]*[/]
// %----A string that matches both <system_comment> and <defined_comment> should
// %----be recognized as <system_comment>, so put these before <defined_comment>.

// <single_quoted>        ::- <single_quote><sq_char><sq_char>*<single_quote>
// %----<single_quoted>s contain visible characters. \ is the escape character for
// %----' and \, i.e., \' is not the end of the <single_quoted>.
// %----The token does not include the outer quotes, e.g., 'cat' and cat are the
// %----same. See <atomic_word> for information about stripping the quotes.
single_quoted
: Single_quote Sq_string Single_quote { $$ = N(BRACKET, single_quoted, $1, $2, $3); }
;

// <distinct_object>      ::- <double_quote><do_char>*<double_quote>
// %---Space and visible characters upto ~, except " and \
// %----<distinct_object>s contain visible characters. \ is the escape character
// %----for " and \, i.e., \" is not the end of the <distinct_object>.
// %----<distinct_object>s are different from (but may be equal to) other tokens,
// %----e.g., "cat" is different from 'cat' and cat. Distinct objects are always
// %----interpreted as themselves, so if they are different they are unequal,
// %----e.g., "Apple" != "Microsoft" is implicit.
distinct_object
: Double_quote Do_string Double_quote { $$ = N(BRACKET, distinct_object, $1, $2, $3); }
;

// <dollar_word>          ::- <dollar><lower_word>
// <dollar_dollar_word>   ::- <dollar><dollar><lower_word>
// <upper_word>           ::- <upper_alpha><alpha_numeric>*
// <lower_word>           ::- <lower_alpha><alpha_numeric>*

// %----Tokens used in syntax, and cannot be character classes
// <vline>                ::- [|]
// <star>                 ::- [*]
// <plus>                 ::- [+]
// <arrow>                ::- [>]
// <less_sign>            ::- [<]

// %----Numbers. Signs are made part of the same token here.
// <real>                 ::- (<signed_real>|<unsigned_real>)
// <signed_real>          ::- <sign><unsigned_real>
// <unsigned_real>        ::- (<decimal_fraction>|<decimal_exponent>)
// <rational>             ::- (<signed_rational>|<unsigned_rational>)
// <signed_rational>      ::- <sign><unsigned_rational>
// <unsigned_rational>    ::- <decimal><slash><positive_decimal>
// <integer>              ::- (<signed_integer>|<unsigned_integer>)
// <signed_integer>       ::- <sign><unsigned_integer>
// <unsigned_integer>     ::- <decimal>
// <decimal>              ::- (<zero_numeric>|<positive_decimal>)
// <positive_decimal>     ::- <non_zero_numeric><numeric>*
// <decimal_exponent>     ::- (<decimal>|<decimal_fraction>)<exponent><exp_integer>
// <decimal_fraction>     ::- <decimal><dot_decimal>
// <dot_decimal>          ::- <dot><numeric><numeric>*
// <exp_integer>          ::- (<signed_exp_integer>|<unsigned_exp_integer>)
// <signed_exp_integer>   ::- <sign><unsigned_exp_integer>
// <unsigned_exp_integer> ::- <numeric><numeric>*

// %----Character classes
// <percentage_sign>      ::: [%]
// <double_quote>         ::: ["]
// <do_char>              ::: ([\40-\41\43-\133\135-\176]|[\\]["\\])
// <single_quote>         ::: [']
// %---Space and visible characters upto ~, except ' and \
// <sq_char>              ::: ([\40-\46\50-\133\135-\176]|[\\]['\\])
// <sign>                 ::: [+-]
// <dot>                  ::: [.]
// <exponent>             ::: [Ee]
// <slash>                ::: [/]
// <zero_numeric>         ::: [0]
// <non_zero_numeric>     ::: [1-9]
// <numeric>              ::: [0-9]
// <lower_alpha>          ::: [a-z]
// <upper_alpha>          ::: [A-Z]
// <alpha_numeric>        ::: (<lower_alpha>|<upper_alpha>|<numeric>|[_])
// <dollar>               ::: [$]
// <printable_char>       ::: .
// %----<printable_char> is any printable ASCII character, codes 32 (space) to 126
// %----(tilde). <printable_char> does not include tabs, newlines, bells, etc. The
// %----use of . does not not exclude tab, so this is a bit loose.
// <viewable_char>        ::: [.\n]
// %------------------------------------------------------------------------------
%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
    std::cerr << l << ": " << m << '\n';
}
