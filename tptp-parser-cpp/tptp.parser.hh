#ifndef DRIVER_HH
# define DRIVER_HH
# include <string>
# include "tptp.grammar.hh"
# include "tptp.ast.hh"

using namespace std;

// Give Flex the prototype of yylex we want ...
# define YY_DECL \
  yy::parser::symbol_type yylex(tptp::parser& drv)
YY_DECL;

namespace tptp {

class parser
{
public:
    parser();

    tptp::ast::node ast;
    
    // Whether to generate parser debug traces.
    bool trace_parsing;

    // Whether to generate scanner debug traces.
    bool trace_scanning;

    // Run the parser on file F.  Return 0 on success.
    int parse(const string& f);
    // The name of the file being parsed.
    string file;

    // Handling the scanner.
    void scan_begin();
    void scan_end();

    // The token's location used by the scanner.
    yy::location location;
};

tptp::ast::node& parse(const string& f);

} // ! namespace tptp
#endif // ! DRIVER_HH
