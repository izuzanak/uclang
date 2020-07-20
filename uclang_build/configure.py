#!/usr/bin/python

import os

index = 0
PKG_NAME      = index; index += 1
PKG_DIR_NAME  = index; index += 1
PKG_TEST_TYPE = index; index += 1
PKG_TEST_PROP = index; index += 1

c_packages = [
  ["LIB_BASE"      ,"base_ucll"      ,"true"      ,[]],
  ["LIB_FTGL"      ,"ftgl_ucll"      ,"false"     ,[]],
  ["LIB_NODE"      ,"node_ucll"      ,"true"      ,[]],
  ["UCLANG"        ,"uclang"         ,"true"      ,[]],
  ["NODE"          ,"node"           ,"true"      ,[]],
  ["ENCIPHER"      ,"encipher"       ,"true"      ,[]],
  ["MOD_BASE"      ,"base_uclm"      ,"true"      ,[]],
  ["MOD_SYS"       ,"sys_uclm"       ,"true"      ,[]],
  ["MOD_LINUX"     ,"linux_uclm"     ,"true"      ,[]],
  ["MOD_SERIAL"    ,"serial_uclm"    ,"files"     ,["/usr/include/termios.h"]],
  ["MOD_LOGGER"    ,"logger_uclm"    ,"true"      ,[]],
  ["MOD_CHANNEL"   ,"channel_uclm"   ,"true"      ,[]],
  ["MOD_EPOLL"     ,"epoll_uclm"     ,"files"     ,["/usr/include/sys/epoll.h"]],
  ["MOD_INOTIFY"   ,"inotify_uclm"   ,"files"     ,["/usr/include/sys/inotify.h"]],
  ["MOD_PAM"       ,"pam_uclm"       ,"files"     ,["/usr/include/security/pam_appl.h"]],
  ["MOD_READLINE"  ,"readline_uclm"  ,"files"     ,["/usr/include/readline/readline.h"]],
  ["MOD_REGEX"     ,"regex_uclm"     ,"files"     ,["/usr/include/regex.h"]],
  ["MOD_PCRE"      ,"pcre_uclm"      ,"pkg-config",["libpcreposix"]],
  ["MOD_TIME"      ,"time_uclm"      ,"true"      ,[]],
  ["MOD_CHECKSUM"  ,"checksum_uclm"  ,"true"      ,[]],
  ["MOD_LANG"      ,"lang_uclm"      ,"true"      ,[]],
  ["MOD_PACK"      ,"pack_uclm"      ,"true"      ,[]],
  ["MOD_CIPHER"    ,"cipher_uclm"    ,"true"      ,[]],
  ["MOD_PARSER"    ,"parser_uclm"    ,"true"      ,[]],
  ["MOD_MATH"      ,"math_uclm"      ,"dirs"      ,["/usr/include/glm"]],
  ["MOD_GSL"       ,"gsl_uclm"       ,"pkg-config",["gsl >= 2.1"]],
  ["MOD_FFTW"      ,"fftw_uclm"      ,"pkg-config",["fftw3 >= 3.3.8"]],
  ["MOD_GMP"       ,"gmp_uclm"       ,"files"     ,["/usr/include/i386-linux-gnu/gmp.h"]],
  ["MOD_DATRIE"    ,"datrie_uclm"    ,"pkg-config",["datrie-0.2 >= 0.2.10"]],
  ["MOD_PSQL"      ,"psql_uclm"      ,"pkg-config",["libpq >= 9.4.1"]],
  ["MOD_SQLITE"    ,"sqlite_uclm"    ,"pkg-config",["sqlite3 >= 3.8.7.1"]],
  ["MOD_HTTP"      ,"http_uclm"      ,"pkg-config",["libmicrohttpd >= 0.9.37"]],
  ["MOD_WEBSOCKET" ,"websocket_uclm" ,"pkg-config",["libwebsockets = 1.3"]],
  ["MOD_CURL"      ,"curl_uclm"      ,"pkg-config",["libcurl >= 7.38.0"]],
  ["MOD_NANOMSG"   ,"nanomsg_uclm"   ,"pkg-config",["nanomsg >= 1.1.5"]],
  ["MOD_PROTOBUF"  ,"protobuf_uclm"  ,"pkg-config",["protobuf >= 1.3.1"]],
  ["MOD_UCF"       ,"ucf_uclm"       ,"dirs"      ,["../ext_libs/ucframework/2.15"]],
  ["MOD_UCTCN"     ,"uctcn_uclm"     ,"dirs"      ,["../ext_libs/ucframework/1.60","../ext_libs/uctcn/2.27"]],
  ["MOD_UCTCNMD"   ,"uctcnmd_uclm"   ,"dirs"      ,["../ext_libs/ucframework/1.60","../ext_libs/uctcn/2.27"]],
  ["MOD_UCTRDP"    ,"uctrdp_uclm"    ,"dirs"      ,["../ext_libs/ucframework/2.15","../ext_libs/uctrdp/1.8"]],
  ["MOD_UCTRDPMD"  ,"uctrdpmd_uclm"  ,"dirs"      ,["../ext_libs/ucframework/2.15","../ext_libs/uctrdp/1.8"]],
  ["MOD_UCTRDPNS"  ,"uctrdpns_uclm"  ,"dirs"      ,["../ext_libs/ucframework/2.15","../ext_libs/uctrdp/1.8"]],
  ["MOD_UCTRDPMSH" ,"uctrdpmsh_uclm" ,"true"      ,[]],
  ["MOD_UCTRNDB"   ,"uctrndb_uclm"   ,"dirs"      ,["../ext_libs/ucframework/2.15","../ext_libs/trndb/trunk","../ext_libs/astor/trunk"]],
  ["MOD_UCCAN"     ,"uccan_uclm"     ,"dirs"      ,["../ext_libs/ucframework/1.60","../ext_libs/uccanopen/1.14"]],
  ["MOD_UCMM"      ,"ucmm_uclm"      ,"dirs"      ,["../ext_libs/ucmm/trunk"]],
  ["MOD_UCGCG"     ,"ucgcg_uclm"     ,"dirs"      ,["../ext_libs/ucframework/2.15"]],
  ["MOD_ADAPTRAIN" ,"adaptrain_uclm" ,"dirs"      ,["../ext_libs/ucframework/1.60","../ext_libs/unicon","../ext_libs/adaptrain"]],
  ["MOD_FTP"       ,"ftp_uclm"       ,"files"     ,["/usr/include/ftplib.h"]],
  ["MOD_SSH2"      ,"ssh2_uclm"      ,"pkg-config",["libssh2 >= 1.4.3"]],
  ["MOD_GCRYPT"    ,"gcrypt_uclm"    ,"files"     ,["/usr/include/gcrypt.h"]],
  ["MOD_CRYPTO"    ,"crypto_uclm"    ,"pkg-config",["libcrypto >= 1.0.2m"]],
  ["MOD_OPENSSL"   ,"openssl_uclm"   ,"pkg-config",["openssl >= 1.0.2m"]],
  ["MOD_LOCALE"    ,"locale_uclm"    ,"files"     ,["/usr/include/locale.h","/usr/include/libintl.h"]],
  ["MOD_ICONV"     ,"iconv_uclm"     ,"files"     ,["/usr/include/iconv.h"]],
  ["MOD_UTF8PROC"  ,"utf8proc_uclm"  ,"files"     ,["/usr/include/utf8proc.h"]],
  ["MOD_JIT"       ,"jit_uclm"       ,"dirs"      ,["../ext_libs/libjit"]],
  ["MOD_LIGHTNING" ,"lightning_uclm" ,"false"     ,[]],
  ["MOD_LLVM"      ,"llvm_uclm"      ,"false"     ,[]],
  ["MOD_GA"        ,"ga_uclm"        ,"dirs",      ["../ext_libs/galib/galib247/ga"]],
  ["MOD_QUIRC"     ,"quirc_uclm"     ,"dirs",      ["../ext_libs/quirc/quirc-1.0"]],
  ["MOD_FANN"      ,"fann_uclm"      ,"pkg-config",["fann >= 2.2.0"]],
  ["MOD_AV"        ,"av_uclm"        ,"pkg-config",["libavutil >= 54.3.0","libavformat >= 56.1.0","libavcodec >= 56.1.0","libswscale >= 3.0.0"]],
  ["MOD_AO"        ,"ao_uclm"        ,"pkg-config",["ao >= 1.1.0"]],
  ["MOD_MPG"       ,"mpg_uclm"       ,"pkg-config",["libmpg123 >= 1.20.1"]],
  ["MOD_VLC"       ,"vlc_uclm"       ,"pkg-config",["libvlc >= 3.0.6"]],
  ["MOD_VA"        ,"va_uclm"        ,"pkg-config",["libva >= 1.3.0"]],
  ["MOD_PORTAUDIO" ,"portaudio_uclm" ,"pkg-config",["portaudio-2.0 >= 19"]],
  ["MOD_GSTREAMER" ,"gstreamer_uclm" ,"pkg-config",["gstreamer-1.0 >= 1.4.4"]],
  ["MOD_GTK"       ,"gtk_uclm"       ,"pkg-config",["gtk+-3.0 >= 3.18.9"]],
  ["MOD_IMAGE"     ,"image_uclm"     ,"pkg-config",["libpng >= 1.2.50","libjpeg"]],
  ["MOD_RAW"       ,"raw_uclm"       ,"pkg-config",["libraw"]],
  ["MOD_OPENCV"    ,"opencv_uclm"    ,"pkg-config",["opencv >= 2.4.9.1"]],
  ["MOD_DOCU"      ,"docu_uclm"      ,"true"      ,[]],
  ["MOD_GLUT"      ,"glut_uclm"      ,"false"     ,[]],
  ["MOD_GLEW"      ,"glew_uclm"      ,"false"     ,[]],
  ["MOD_GL"        ,"gl_uclm"        ,"false"     ,[]],
  ["MOD_FTGL"      ,"ftgl_uclm"      ,"false"     ,[]],
  ["MOD_VG"        ,"vg_uclm"        ,"false"     ,[]],
  ["MOD_SHIVAVG"   ,"shivavg_uclm"   ,"false"     ,[]],
  ["MOD_AMANITHVG" ,"amanithvg_uclm" ,"false"     ,[]],
  ["MOD_IMXEGL"    ,"imxegl_uclm"    ,"false"     ,[]],
  ["MOD_SNMP"      ,"snmp_uclm"      ,"files"     ,["/usr/include/net-snmp/net-snmp-config.h","/usr/include/net-snmp/utilities.h","/usr/include/net-snmp/net-snmp-includes.h","/usr/include/net-snmp/agent/net-snmp-agent-includes.h"]], # test
  ["MOD_COMELM"    ,"comelm_uclm"    ,"false"     ,[]],
  ["MOD_DLMS"      ,"dlms_uclm"      ,"false"     ,[]],
  ["MOD_UCPAS"     ,"ucpas_uclm"     ,"dirs"      ,["../ext_libs/ucpas/libpas"]],
  ["MOD_FGETTOOLS" ,"fgettools_uclm" ,"true"      ,[]],
  ["MOD_NODE"      ,"node_uclm"      ,"true"      ,[]],
  ["MOD_DDB"       ,"ddb_uclm"       ,"false"     ,[]],
  ["MOD_CONTAINERS","containers_uclm","true"      ,[]],
  ["MOD_ALGORITHMS","algorithms_uclm","true"      ,[]],
  ["MOD_VALIDATOR" ,"validator_uclm" ,"true"      ,[]],
  ["MOD_BINBITS"   ,"binbits_uclm"   ,"true"      ,[]],
  ["MOD_GRAPH"     ,"graph_uclm"     ,"true"      ,[]],
  ["MOD_JSON"      ,"json_uclm"      ,"true"      ,[]],
  ["MOD_XML"       ,"xml_uclm"       ,"pkg-config",["libxml-2.0 >= 2.9.1"]],
  ["MOD_INTELHEX"  ,"intelhex_uclm"  ,"true",      []],
  ["MOD_SHAPE"     ,"shape_uclm"     ,"pkg-config",["shapelib >= 1.4.1"]],
  ["MOD_SOAPCL"    ,"soapcl_uclm"    ,"false"     ,[]],
  ["MOD_SOAPSRV"   ,"soapsrv_uclm"   ,"false"     ,[]],
  ["MOD_PYTHON"    ,"python_uclm"    ,"pkg-config",["python-2.7 >= 2.7"]],
  ["MOD_V8"        ,"v8_uclm"        ,"files"     ,["/usr/include/v8.h"]],
  ["MOD_LUA"       ,"lua_uclm"       ,"pkg-config",["lua5.2 >= 5.2.0"]],
  ["MOD_MONO"      ,"mono_uclm"      ,"pkg-config",["mono-2 >= 3.2.8"]],
  ["MOD_PERL"      ,"perl_uclm"      ,"false",     []],
  ["MOD_RUBY"      ,"ruby_uclm"      ,"pkg-config",["ruby >= 2.3.0"]],
  ["MOD_PROLOG"    ,"prolog_uclm"    ,"pkg-config",["swipl >= 7.2.3"]],
  ["MOD_RUST"      ,"rust_uclm"      ,"false",     []],
  ["MOD_UV"        ,"uv_uclm"        ,"false"     ,[]],
  ["MOD_ZLIB"      ,"zlib_uclm"      ,"pkg-config",["zlib >= 1.2.8"]],
  ["MOD_ZIP"       ,"zip_uclm"       ,"pkg-config",["libzip >= 1.1.2"]],
  ["MOD_SNAPPY"    ,"snappy_uclm"    ,"pkg-config",["snappy >= 1.0.0"]],
  ["MOD_PIGPIO"    ,"pigpio_uclm"    ,"files"     ,["/usr/include/pigpio.h"]],
  ["MOD_FUSE"      ,"fuse_uclm"      ,"pkg-config",["fuse >= 2.9.3"]],
  ["MOD_ANDROID"   ,"android_uclm"   ,"false"     ,[]],
  ["MOD_NACL"      ,"nacl_uclm"      ,"false"     ,[]],
  ["MOD_EMSCRIPTEN","emscripten_uclm","false"     ,[]],
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
    print "    %s # %-15s - %s" % ("True, " if enabled else "False,",package[PKG_NAME],package[PKG_DIR_NAME])

# - print end of array -
print "]"

