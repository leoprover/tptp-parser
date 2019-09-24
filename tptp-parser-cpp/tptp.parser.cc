#include "tptp.parser.hh"
#include "tptp.grammar.hh"

tptp::parser::parser ()
    : trace_parsing (false), trace_scanning (false)
{
}

int
tptp::parser::parse (const std::string &f)
{
    file = f;
    location.initialize (&file);
    scan_begin();
    yy::parser parser(*this);
    parser.set_debug_level(trace_parsing);
    int res = parser.parse();
    scan_end();
    return res;
}

tptp::ast::node& parse(const string& f) {
    tptp::parser *prs = (tptp::parser*) malloc(sizeof(tptp::parser));
    prs->parse(f);
    return prs->ast;
}