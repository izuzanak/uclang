#!/bin/sh

# - generate makefile -
python mf_gen.py > Makefile

# - compile libraries -
make -s -j 3 $(pwd)/tmp_files/libbase_ucll/libbase_ucll.so
make -s -j 3 $(pwd)/tmp_files/libftgl_ucll/libftgl_ucll.so
make -s -j 3 $(pwd)/tmp_files/libnode_ucll/libnode_ucll.so

# - copy libraries to source -
cp tmp_files/libbase_ucll/libbase_ucll.so ../uclang/libs/libbase_ucll/
cp tmp_files/libftgl_ucll/libftgl_ucll.so ../uclang/libs/libftgl_ucll/
cp tmp_files/libnode_ucll/libnode_ucll.so ../uclang/libs/libnode_ucll/

# - generate makefile with libraries -
python mf_gen.py > Makefile

# - compile all modules -
make -s -j 3

