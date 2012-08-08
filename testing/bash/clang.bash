#!/bin/bash
pushd $1 1>/dev/null 
clang++ -O $2 1>/dev/null
./a.out
popd 1>/dev/null
