#!/bin/bash
pushd $1 1>/dev/null 
erlc $2 1>/dev/null
erl -noshell -s $3 start -s init stop
popd 1>/dev/null
