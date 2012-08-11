#!/bin/bash
pushd $1 1>/dev/null
ls * | grep -v -i -e $2 -e .txt | xargs rm -rf 1>/dev/null
popd 1>/dev/null
