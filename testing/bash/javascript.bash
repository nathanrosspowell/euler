#!/bin/bash
pushd $1 1>/dev/null 
rhino -f $2 
popd 1>/dev/null
