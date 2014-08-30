#!/bin/bash
pushd $1 1>/dev/null 
rustc -O -o a $2 
./a
popd 1>/dev/null
