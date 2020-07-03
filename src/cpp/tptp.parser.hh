#ifndef DRIVER_HH
# define DRIVER_HH
# include <string>
# include "tptp.grammar.hh"
# include "tptp.ast.hh"

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

    // Whether the type declaration in quantification-binder is optional, allowing local variables without an explicit type.
    bool optional_binder_types = false;

    // Run the parser on file F.  Return 0 on success.
    int parse(const std::string& f);
    // The name of the file being parsed.
    std::string file;

    // Handling the scanner.
    void scan_begin();
    void scan_end();

    // The token's location used by the scanner.
    yy::location location;
};

tptp::ast::node& parse(const std::string& f);

} // ! namespace tptp
#endif // ! DRIVER_HH
