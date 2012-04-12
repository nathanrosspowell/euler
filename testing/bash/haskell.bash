#!/bin/bash
pushd $1 1>/dev/null 
ghc -O $2 1>/dev/null
./$2
popd 1>/dev/null
