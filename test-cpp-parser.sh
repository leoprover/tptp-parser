#!/bin/sh

tptp-parser/tptp problems/thf.p
tptp-parser/tptp problems/SYN036^7.p
(cd python3; python3 -m tptp_parser ../problems/SYN036^7.p )
