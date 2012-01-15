#!/bin/bash
pushd $1 1>/dev/null 
python $2
popd 1>/dev/null
