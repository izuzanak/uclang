
@echo off

REM replace %TODO% tags before use

set BUILD_CMAKE_PATH=%TODO%\cmake.exe
set BUILD_GENERATOR="Visual Studio 14 2015"
set BUILD_VCREDIST_PATH="%ProgramFiles%\Microsoft Visual Studio 14.0\VC\redist\x86"
set BUILD_TYPE=Release
set BUILD_DIR=%~dp0\win32

%BUILD_CMAKE_PATH% -E make_directory %BUILD_DIR%
%BUILD_CMAKE_PATH% -E chdir %BUILD_DIR% ^
  %BUILD_CMAKE_PATH% ^
    -G %BUILD_GENERATOR% ^
    -D CMAKE_BUILD_TYPE=%BUILD_TYPE% ^
    -D BUILD_VCREDIST_PATH=%BUILD_VCREDIST_PATH% ^
    --warn-uninitialized ^
    --no-warn-unused-cli ^
    %~dp0\..

pause

