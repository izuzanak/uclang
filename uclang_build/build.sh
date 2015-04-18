#!/bin/sh

# - configure modules -
python configure.py > mf_mods.py

# - generate makefile -
python mf_gen.py > Makefile

# - compile libraries -
make -s -j 3 $(pwd)/tmp_files/libbase_ucll/libbase_ucll.so 2> /dev/null
make -s -j 3 $(pwd)/tmp_files/libftgl_ucll/libftgl_ucll.so 2> /dev/null
make -s -j 3 $(pwd)/tmp_files/libnode_ucll/libnode_ucll.so 2> /dev/null

# - copy libraries to source -
cp tmp_files/libbase_ucll/libbase_ucll.so ../uclang/libs/libbase_ucll/ 2> /dev/null
cp tmp_files/libftgl_ucll/libftgl_ucll.so ../uclang/libs/libftgl_ucll/ 2> /dev/null
cp tmp_files/libnode_ucll/libnode_ucll.so ../uclang/libs/libnode_ucll/ 2> /dev/null

# - generate makefile with libraries -
python mf_gen.py > Makefile

# - compile all modules -
make -s -j 3

