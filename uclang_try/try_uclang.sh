#!/bin/bash

# Script will clone, compile and test uclang language interpreter.

# Usage example:
#   bash try_uclang.sh
#   bash try_uclang.sh python lua v8

# PREREQUISITES: bash, git, python2.7, pkg-config, ...

# In case of intention to test modules python, lua and v8, following packages
# are also required: libv8-dev, libpython2.7-dev, liblua5.2-dev, lua-json, ...

ROOT_DIR=$(pwd)

# - clone repositories -
if [ ! -d cont ]
then
  git clone https://github.com/izuzanak/cont.git
fi

if [ ! -d uclang ]
then
  git clone https://github.com/izuzanak/uclang.git
fi

# - compile container generator -
cd cont/cont_build
sh build.sh

CONT_DIR=$(pwd)
if [[ ":$PATH:" != *":$CONT_DIR:"* ]]
then
    export PATH="${PATH:+"$PATH:"}$CONT_DIR"
fi

cd $ROOT_DIR

# - compile uclang interpreter -
cd uclang/uclang_build
sh build.sh

UCLANG_DIR=$(pwd)
if [[ ":$LD_LIBRARY_PATH:" != *":$UCLANG_DIR:"* ]]
then
    export LD_LIBRARY_PATH="${LD_LIBRARY_PATH:+"$LD_LIBRARY_PATH:"}$UCLANG_DIR"
fi

cd $ROOT_DIR

# - compile node examples -
cd uclang/uclang_build/node_examples
make -s

cd $ROOT_DIR


# - run demo scripts -
UCL_BUILD_DIR=uclang/uclang_build

while true
do
  case $1 in
    python) SCRIPT_NAME=demo_python.ucl ;;
    lua)    SCRIPT_NAME=demo_lua.ucl ;;
    v8)     SCRIPT_NAME=demo_v8.ucl ;;
    *) exit ;;
  esac

  $UCL_BUILD_DIR/uclang $UCL_BUILD_DIR/scripts/examples/$SCRIPT_NAME

  shift
done

