#include <iostream>
#include <sys/time.h>
#include "tptp.ast.hh"
#include "tptp.parser.hh"

long int getTimeInMs() { 
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return tp.tv_sec * 1000 + tp.tv_usec / 1000;
}

int main(int argc, char **argv) {
    long int t1 = getTimeInMs();

    std::cout << "# Parsing: " << argv[1] << "\n";
    tptp::ast::node& root = tptp::parse (argv[1]);

    std::cout << "# Parsed:" << "\n" << root.toString() << "\n";

    long int t2 = getTimeInMs();

    std::cout << (t2 - t1) << "ms";
}
