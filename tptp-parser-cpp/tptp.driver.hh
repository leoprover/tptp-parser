#ifndef DRIVER_HH
# define DRIVER_HH
# include <string>
# include "tptp.parser.hh"
# include "tptp.ast.hh"

using namespace std;
using namespace tptp::ast;

// Give Flex the prototype of yylex we want ...
# define YY_DECL \
  yy::parser::symbol_type yylex(driver& drv)
YY_DECL;

class driver
{
public:
    driver();

    node ast;
    
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
#endif // ! DRIVER_HH
