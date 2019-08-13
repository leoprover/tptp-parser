#!/bin/sh

cd tptp-parser-cpp
make -f Makefile.parser clean
make -f Makefile.parser $1
