#!/bin/sh

# - configure modules -
if [ ! -e mf_mods.py ]
then
  echo "configure modules"
  python configure.py > mf_mods.py
fi

# - compile base library -
echo "compile base library"
python mf_gen.py LIB_BASE > Makefile
make -s -j $(nproc) $(pwd)/tmp_files/libbase_ucll/libbase_ucll.so 2> /dev/null
cp tmp_files/libbase_ucll/libbase_ucll.so ../uclang/libs/libbase_ucll/ 2> /dev/null

# - compile libraries -
echo "compile libraries"
python mf_gen.py LIB_FTGL LIB_NODE > Makefile
make -s -j $(nproc) $(pwd)/tmp_files/libftgl_ucll/libftgl_ucll.so 2> /dev/null
make -s -j $(nproc) $(pwd)/tmp_files/libnode_ucll/libnode_ucll.so 2> /dev/null
cp tmp_files/libftgl_ucll/libftgl_ucll.so ../uclang/libs/libftgl_ucll/ 2> /dev/null
cp tmp_files/libnode_ucll/libnode_ucll.so ../uclang/libs/libnode_ucll/ 2> /dev/null

# - compile executables and modules -
echo "compile executables and modules"
python mf_gen.py > Makefile
make -s -j $(nproc)

