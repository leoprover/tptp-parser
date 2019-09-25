%{
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <string>

#include <cstring> // strerror

#include "tptp.grammar.hh"
#include "tptp.parser.hh"

#define YY_TXT std::string(yytext, yyleng)

// Code run each time a pattern is matched.
# define YY_USER_ACTION  loc.columns (yyleng);

#define TOK(token) return yy::parser::make_ ## token (std::move(YY_TXT), loc);
#define END_OF_FILE return yy::parser::make_END_OF_FILE(loc);

// %option noyywrap nounput noinput batch debug
%}
%option noyywrap nounput noinput debug
%x COMMENT

%s DO_MODE
%s SQ_MODE
%s LINE_COMMENT

%%

%{
    // Code run each time yylex is called.
    yy::location& loc = drv.location;
    loc.step ();
%}

    /* explicit eof token, since we need to type it */
<<EOF>>              END_OF_FILE
    /* line comment */
"%".*
    /* ignore newlines, whitspaces and comments, register newlines to track the scanner position in the file */
[\n]                 loc.lines (yyleng); loc.step (); 
[ \t]

    /* " and ' quoted strings */
<DO_MODE>"\""        BEGIN INITIAL; TOK(Double_quote)
<DO_MODE>([\40-\41\43-\133\135-\176]|"\\"|"\"\\")+ TOK(Do_string)
"\""                 BEGIN DO_MODE; TOK(Double_quote)
<SQ_MODE>"'"         BEGIN INITIAL; TOK(Single_quote)
<SQ_MODE>([\40-\46\50-\133\135-\176]|"\\"|"'\\")+ TOK(Sq_string)
"'"                  BEGIN SQ_MODE; TOK(Single_quote)
    
    /* annontaions */
"include(" TOK(DefinitionInclude)
"thf(" TOK(DefinitionTHF)
")."   TOK(DefinitionEnd)

"$ite" TOK(Dollar_ite)
"$let" TOK(Dollar_let)
"$thf" TOK(Dollar_thf)
"$tff" TOK(Dollar_tff)
"$fof" TOK(Dollar_fof)
"$cnf" TOK(Dollar_cnf)
"$fot" TOK(Dollar_fot)

    /* unary and binary ops, sorted by length to ensure the correct token is parsed */
"-->"  TOK(Gentzen_arrow)
"<=>"  TOK(Iff)
"<~>"  TOK(Niff)
"@@+"  TOK(ChoiceComb)
"@@-"  TOK(DescriptionComb)

"<<"   TOK(Subtype_sign)
":="   TOK(Assignment)
"~&"   TOK(Nand)
"~|"   TOK(Nor)
"=>"   TOK(Impl)
"<="   TOK(If)
"!="   TOK(Infix_inequality)
"!!"   TOK(ForallComb)
"!>"   TOK(TyForall)
"??"   TOK(ExistsComb)
"?*"   TOK(TyExists)
"@+"   TOK(Choice)
"@-"   TOK(Description)
"@="   TOK(EqComb)

"="    TOK(Infix_equality)
"~"    TOK(Not)
"!"    TOK(Forall)
"&"    TOK(And)
"|"    TOK(Or)
"?"    TOK(Exists)
"^"    TOK(Lambda)
"@"    TOK(App)
">"    TOK(Arrow)
"<"    TOK(Less_sign)
"*"    TOK(Star)
"+"    TOK(Plus)

    /* signs */
"("    TOK(LParen)
")"    TOK(RParen)
"["    TOK(LBrkt)
"]"    TOK(RBrkt)
"{"    TOK(LCurly)
"}"    TOK(RCurly)
","    TOK(Comma)
":"    TOK(Colon)

[+-]?([0]|[1-9][0-9]*)                   TOK(Integer)
[+-]?(([0]|[1-9][0-9]*)[/]([1-9][0-9]*)) TOK(Rational)
[+-]?(([0]|[1-9][0-9]*)[.][0-9]+)|((([0]|[1-9][0-9]*)([.][0-9]+)?)[eE][+-]?([0]|[1-9][0-9]*)) TOK(Real)

"$"[a-z][a-zA-Z0-9_]*  TOK(Dollar_word)
"$$"[a-z][a-zA-Z0-9_]* TOK(Dollar_dollar_word)
[a-z][a-zA-Z0-9_]*     TOK(Lower_word)
[A-Z][a-zA-Z0-9_]*     TOK(Upper_word)

%%

void
tptp::parser::scan_begin ()
{
    yy_flex_debug = trace_scanning;
    if (file.empty () || file == "-")
    yyin = stdin;
    else if (!(yyin = fopen (file.c_str (), "r")))
    {
        std::cerr << "cannot open " << file << ": " << strerror(errno) << '\n';
        exit (EXIT_FAILURE);
    }
}

void
tptp::parser::scan_end ()
{
    fclose (yyin);
}