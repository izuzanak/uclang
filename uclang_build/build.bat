
::
:: Windows porting problems to solve:
:: * pkg-config not present
:: * ucl_var static constant names: ERROR_BUSY, stdin, stdout, stderr
:: * program node use disabled (Windows) UclVar classes
::

:: - configure modules -
echo "configure modules"
python configure.py > mf_mods.py

:: - compile base library -
echo "compile base library"
python mf_gen.py LIB_BASE > Makefile
make -s %CD%\tmp_files\libbase_ucll\libbase_ucll.dll
copy tmp_files\libbase_ucll\libbase_ucll.dll ..\uclang\libs\libbase_ucll\

:: - compile libraries -
echo "compile libraries"
python mf_gen.py LIB_NODE > Makefile
make -s %CD%\tmp_files\libnode_ucll\libnode_ucll.dll
copy tmp_files\libnode_ucll\libnode_ucll.dll ..\uclang\libs\libnode_ucll\

:: - compile executables and modules -
echo "compile executables and modules"
python mf_gen.py > Makefile
make -s

