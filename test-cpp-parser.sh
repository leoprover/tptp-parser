#!/bin/sh

tptp-parser-cpp/tptp problems/thf.p
tptp-parser-cpp/tptp problems/SYN036^7.p
(cd python3; python3 -m tptp_parser ../problems/SYN036^7.p )
