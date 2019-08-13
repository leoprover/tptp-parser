#include <iostream>
#include "tptp.driver.hh"

#include <sys/time.h>

long int getTimeInMs() { 
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return tp.tv_sec * 1000 + tp.tv_usec / 1000;
}

int main(int argc, char **argv) {
    long int t1 = getTimeInMs();

    driver drv;
    //drv.trace_parsing = true;
    //drv.trace_scanning = true;

    std::cout << "# Parsing: " << argv[1] << "\n";
    drv.parse (argv[1]);

    std::cout << "# Parsed:" << "\n" << drv.ast << "\n";

    long int t2 = getTimeInMs();

    std::cout << (t2 - t1) << "ms";
}
