#!/usr/bin/python

import os

index = 0
PKG_NAME      = index; index += 1
PKG_TEST_TYPE = index; index += 1
PKG_TEST_PROP = index; index += 1

c_packages = [
  ["LIB_BASE"      ,"true"      ,[]],
  ["LIB_FTGL"      ,"false"     ,[]],
  ["LIB_NODE"      ,"true"      ,[]],
  ["UCLANG"        ,"true"      ,[]],
  ["NODE"          ,"true"      ,[]],
  ["ENCIPHER"      ,"true"      ,[]],
  ["MOD_BASE"      ,"true"      ,[]],
  ["MOD_SYS"       ,"true"      ,[]],
  ["MOD_INOTIFY"   ,"files"     ,["/usr/include/sys/inotify.h"]],
  ["MOD_READLINE"  ,"files"     ,["/usr/include/readline/readline.h"]],
  ["MOD_TIME"      ,"true"      ,[]],
  ["MOD_LANG"      ,"true"      ,[]],
  ["MOD_PACK"      ,"true"      ,[]],
  ["MOD_CIPHER"    ,"true"      ,[]],
  ["MOD_PARSER"    ,"true"      ,[]],
  ["MOD_MATH"      ,"dirs"      ,["/usr/include/glm"]],
  ["MOD_GSL"       ,"pkg-config",["gsl >= 2.1"]],
  ["MOD_FFTW"      ,"pkg-config",["fftw3 >= 3.3.8"]],
  ["MOD_GMP"       ,"files"     ,["/usr/include/i386-linux-gnu/gmp.h"]],
  ["MOD_DATRIE"    ,"pkg-config",["datrie-0.2 >= 0.2.10"]],
  ["MOD_PSQL"      ,"pkg-config",["libpq >= 9.4.1"]],
  ["MOD_SQLITE"    ,"pkg-config",["sqlite3 >= 3.8.7.1"]],
  ["MOD_HTTP"      ,"pkg-config",["libmicrohttpd >= 0.9.37"]],
  ["MOD_WEBSOCKET" ,"pkg-config",["libwebsockets = 1.3"]],
  ["MOD_CURL"      ,"pkg-config",["libcurl >= 7.38.0"]],
  ["MOD_UCF"       ,"dirs"      ,["../ext_libs/ucframework/2.15"]],
  ["MOD_UCTCN"     ,"dirs"      ,["../ext_libs/ucframework/1.60","../ext_libs/uctcn/2.27"]],
  ["MOD_UCTCNMD"   ,"dirs"      ,["../ext_libs/ucframework/1.60","../ext_libs/uctcn/2.27"]],
  ["MOD_UCTRDP"    ,"dirs"      ,["../ext_libs/ucframework/2.15","../ext_libs/uctrdp/1.8"]],
  ["MOD_UCTRDPMD"  ,"dirs"      ,["../ext_libs/ucframework/2.15","../ext_libs/uctrdp/1.8"]],
  ["MOD_UCTRDPNS"  ,"dirs"      ,["../ext_libs/ucframework/2.15","../ext_libs/uctrdp/1.8"]],
  ["MOD_UCTRDPMSH" ,"true"      ,[]],
  ["MOD_UCTRNDB"   ,"dirs"      ,["../ext_libs/ucframework/2.15","../ext_libs/trndb/trunk","../ext_libs/astor/trunk"]],
  ["MOD_UCCAN"     ,"dirs"      ,["../ext_libs/ucframework/1.60","../ext_libs/uccanopen/1.14"]],
  ["MOD_UCMM"      ,"dirs"      ,["../ext_libs/ucmm/trunk"]],
  ["MOD_UCGCG"     ,"dirs"      ,["../ext_libs/ucframework/2.15"]],
  ["MOD_ADAPTRAIN" ,"dirs"      ,["../ext_libs/ucframework/1.60","../ext_libs/unicon","../ext_libs/adaptrain"]],
  ["MOD_FTP"       ,"files"     ,["/usr/include/ftplib.h"]],
  ["MOD_SSH2"      ,"pkg-config",["libssh2 >= 1.4.3"]],
  ["MOD_GCRYPT"    ,"files"     ,["/usr/include/gcrypt.h"]],
  ["MOD_CRYPTO"    ,"pkg-config",["libcrypto >= 1.0.2m"]],
  ["MOD_LOCALE"    ,"files"     ,["/usr/include/locale.h","/usr/include/libintl.h"]],
  ["MOD_ICONV"     ,"files"     ,["/usr/include/iconv.h"]],
  ["MOD_UTF8PROC"  ,"files"     ,["/usr/include/utf8proc.h"]],
  ["MOD_JIT"       ,"dirs"      ,["../ext_libs/libjit"]],
  ["MOD_LIGHTNING" ,"false"     ,[]],
  ["MOD_LLVM"      ,"false"     ,[]],
  ["MOD_GA"        ,"dirs",      ["../ext_libs/galib/galib247/ga"]],
  ["MOD_FANN"      ,"pkg-config",["fann >= 2.2.0"]],
  ["MOD_AV"        ,"pkg-config",["libavutil >= 54.3.0","libavformat >= 56.1.0","libavcodec >= 56.1.0","libswscale >= 3.0.0"]],
  ["MOD_AO"        ,"pkg-config",["ao >= 1.1.0"]],
  ["MOD_MPG"       ,"pkg-config",["libmpg123 >= 1.20.1"]],
  ["MOD_PORTAUDIO" ,"pkg-config",["portaudio-2.0 >= 19"]],
  ["MOD_GSTREAMER" ,"pkg-config",["gstreamer-1.0 >= 1.4.4"]],
  ["MOD_GTK"       ,"pkg-config",["gtk+-3.0 >= 3.18.9"]],
  ["MOD_IMAGE"     ,"pkg-config",["libpng >= 1.2.50","libjpeg"]],
  ["MOD_OPENCV"    ,"pkg-config",["opencv >= 2.4.9.1"]],
  ["MOD_DOCU"      ,"true"      ,[]],
  ["MOD_GLUT"      ,"false"     ,[]],
  ["MOD_GLEW"      ,"false"     ,[]],
  ["MOD_GL"        ,"false"     ,[]],
  ["MOD_FTGL"      ,"false"     ,[]],
  ["MOD_VG"        ,"false"     ,[]],
  ["MOD_SHIVAVG"   ,"false"     ,[]],
  ["MOD_AMANITHVG" ,"false"     ,[]],
  ["MOD_IMXEGL"    ,"false"     ,[]],
  ["MOD_SNMP"      ,"false"     ,[]], # test
  ["MOD_COMELM"    ,"false"     ,[]],
  ["MOD_DLMS"      ,"false"     ,[]],
  ["MOD_UCPAS"     ,"dirs"      ,["../ext_libs/ucpas/libpas"]],
  ["MOD_FGETTOOLS" ,"true"      ,[]],
  ["MOD_NODE"      ,"true"      ,[]],
  ["MOD_DDB"       ,"false"     ,[]],
  ["MOD_CONTAINERS","true"      ,[]],
  ["MOD_ALGORITHMS","true"      ,[]],
  ["MOD_VALIDATOR" ,"true"      ,[]],
  ["MOD_BINBITS"   ,"true"      ,[]],
  ["MOD_GRAPH"     ,"true"      ,[]],
  ["MOD_JSON"      ,"true"      ,[]],
  ["MOD_XML"       ,"pkg-config",["libxml-2.0 >= 2.9.1"]],
  ["MOD_INTELHEX"  ,"true",      []],
  ["MOD_SOAPCL"    ,"false"     ,[]],
  ["MOD_SOAPSRV"   ,"false"     ,[]],
  ["MOD_PYTHON"    ,"pkg-config",["python-2.7 >= 2.7"]],
  ["MOD_V8"        ,"files"     ,["/usr/include/v8.h"]],
  ["MOD_LUA"       ,"pkg-config",["lua5.2 >= 5.2.0"]],
  ["MOD_MONO"      ,"pkg-config",["mono-2 >= 3.2.8"]],
  ["MOD_PERL"      ,"false",     []],
  ["MOD_RUBY"      ,"pkg-config",["ruby-2.3 >= 2.3.0"]],
  ["MOD_PROLOG"    ,"pkg-config",["swipl >= 7.2.3"]],
  ["MOD_RUST"      ,"false",     []],
  ["MOD_UV"        ,"false"     ,[]],
  ["MOD_ZLIB"      ,"pkg-config",["zlib >= 1.2.8"]],
  ["MOD_ZIP"       ,"pkg-config",["libzip >= 1.1.2"]],
  ["MOD_SNAPPY"    ,"files",     ["/usr/include/snappy.h"]],
  ["MOD_PIGPIO"    ,"files"     ,["/usr/include/pigpio.h"]],
  ["MOD_FUSE"      ,"pkg-config",["fuse >= 2.9.3"]],
  ["MOD_ANDROID"   ,"false"     ,[]],
  ["MOD_NACL"      ,"false"     ,[]],
  ["MOD_EMSCRIPTEN","false"     ,[]],
]

# - print begin of array -
print 'c_enabled = ['

# - process packages -
for package in c_packages:

    test_type = package[PKG_TEST_TYPE];
    enabled = True

    if test_type == "true":
        pass

    elif test_type == "false":
        enabled = False

    elif test_type == "files":
        for file_path in package[PKG_TEST_PROP]:
            enabled &= os.path.isfile(file_path)

    elif test_type == "dirs":
        for dir_path in package[PKG_TEST_PROP]:
            enabled &= os.path.isdir(dir_path)

    elif test_type == "pkg-config":
        enabled &= os.system('pkg-config "' + '" "'.join(package[PKG_TEST_PROP]) + '"') == 0
    
    else:
        raise Exception("Unknown package presence test type: %s" % test_type)

    # - print module configuration -
    print "    %s # %s" % ("True, " if enabled else "False,",package[PKG_NAME])

# - print end of array -
print "]"

