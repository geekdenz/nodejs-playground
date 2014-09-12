#!/bin/bash
if [[ -z $1 ]] 
then
  node-gyp configure
fi
node-gyp build
