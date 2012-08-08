#!/bin/bash
pushd $1 1>/dev/null 
ghc -v0 -O -o program $2 1>/dev/null
./program
popd 1>/dev/null
