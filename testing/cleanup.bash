#!/bin/bash
pushd $1 1>/dev/null
ls * | grep -v $2 | xargs rm -rf 1>/dev/null
popd 1>/dev/null
