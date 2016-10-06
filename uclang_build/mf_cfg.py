
import os;
from mf_mods import *

C_UCLANG_DIR = os.sep.join(os.getcwd().split(os.sep)[:-1] + ["uclang" + os.sep])

index = 0
C_LIBRARY_BASE      = index; index += 1
C_LIBRARY_FTGL      = index; index += 1
C_LIBRARY_NODE      = index; index += 1
C_UCLANG_PROG       = index; index += 1
C_NODE_PROG         = index; index += 1
C_ENCIPHER_PROG     = index; index += 1
C_MODULE_BASE       = index; index += 1
C_MODULE_SYS        = index; index += 1
C_MODULE_INOTIFY    = index; index += 1
C_MODULE_TIME       = index; index += 1
C_MODULE_LANG       = index; index += 1
C_MODULE_PACK       = index; index += 1
C_MODULE_CIPHER     = index; index += 1
C_MODULE_PARSER     = index; index += 1
C_MODULE_MATH       = index; index += 1
C_MODULE_GSL        = index; index += 1
C_MODULE_PSQL       = index; index += 1
C_MODULE_SQLITE     = index; index += 1
C_MODULE_HTTP       = index; index += 1
C_MODULE_WEBSOCKET  = index; index += 1
C_MODULE_CURL       = index; index += 1
C_MODULE_UCF        = index; index += 1
C_MODULE_UCTCN      = index; index += 1
C_MODULE_UCMM       = index; index += 1
C_MODULE_ADAPTRAIN  = index; index += 1
C_MODULE_FTP        = index; index += 1
C_MODULE_SSH2       = index; index += 1
C_MODULE_GCRYPT     = index; index += 1
C_MODULE_ICONV      = index; index += 1
C_MODULE_JIT        = index; index += 1
C_MODULE_LIGHTNING  = index; index += 1
C_MODULE_LLVM       = index; index += 1
C_MODULE_GA         = index; index += 1
C_MODULE_AV         = index; index += 1
C_MODULE_AO         = index; index += 1
C_MODULE_MPG        = index; index += 1
C_MODULE_PORTAUDIO  = index; index += 1
C_MODULE_GSTREAMER  = index; index += 1
C_MODULE_IMAGE      = index; index += 1
C_MODULE_OPENCV     = index; index += 1
C_MODULE_DOCU       = index; index += 1
C_MODULE_GLUT       = index; index += 1
C_MODULE_GLEW       = index; index += 1
C_MODULE_GL         = index; index += 1
C_MODULE_FTGL       = index; index += 1
C_MODULE_VG         = index; index += 1
C_MODULE_IMXEGL     = index; index += 1
C_MODULE_SNMP       = index; index += 1
C_MODULE_COMELM     = index; index += 1
C_MODULE_DLMS       = index; index += 1
C_MODULE_UCPAS      = index; index += 1
C_MODULE_FGETTOOLS  = index; index += 1
C_MODULE_NODE       = index; index += 1
C_MODULE_DDB        = index; index += 1
C_MODULE_CONTAINERS = index; index += 1
C_MODULE_ALGORITHMS = index; index += 1
C_MODULE_BINBITS    = index; index += 1
C_MODULE_GRAPH      = index; index += 1
C_MODULE_JSON       = index; index += 1
C_MODULE_XML        = index; index += 1
C_MODULE_SOAPCL     = index; index += 1
C_MODULE_SOAPSRV    = index; index += 1
C_MODULE_PYTHON     = index; index += 1
C_MODULE_V8         = index; index += 1
C_MODULE_LUA        = index; index += 1
C_MODULE_MONO       = index; index += 1
C_MODULE_PERL       = index; index += 1
C_MODULE_UV         = index; index += 1
C_MODULE_ZLIB       = index; index += 1
C_MODULE_PIGPIO     = index; index += 1
C_MODULE_FUSE       = index; index += 1
C_MODULE_ANDROID    = index; index += 1
C_MODULE_NACL       = index; index += 1

index = 0
CFG_NAME   = index; index += 1
CFG_TARGET = index; index += 1
CFG_DIR    = index; index += 1
CFG_MODULE = index; index += 1

c_cfg = [
    ["LIB_BASE"      ,c_enabled[C_LIBRARY_BASE]     ,C_UCLANG_DIR + "libs/libbase_ucll"     ,None],
    ["LIB_FTGL"      ,c_enabled[C_LIBRARY_FTGL]     ,C_UCLANG_DIR + "libs/libftgl_ucll"     ,None],
    ["LIB_NODE"      ,c_enabled[C_LIBRARY_NODE]     ,C_UCLANG_DIR + "libs/libnode_ucll"     ,None],
    ["UCLANG"        ,c_enabled[C_UCLANG_PROG]      ,C_UCLANG_DIR + "progs/uclang"          ,None],
    ["NODE"          ,c_enabled[C_NODE_PROG]        ,C_UCLANG_DIR + "progs/node"            ,None],
    ["ENCIPHER"      ,c_enabled[C_ENCIPHER_PROG]    ,C_UCLANG_DIR + "progs/encipher"        ,None],
    ["MOD_BASE"      ,c_enabled[C_MODULE_BASE]      ,C_UCLANG_DIR + "mods/base_uclm"        ,None],
    ["MOD_SYS"       ,c_enabled[C_MODULE_SYS]       ,C_UCLANG_DIR + "mods/sys_uclm"         ,None],
    ["MOD_INOTIFY"   ,c_enabled[C_MODULE_INOTIFY]   ,C_UCLANG_DIR + "mods/inotify_uclm"     ,None],
    ["MOD_TIME"      ,c_enabled[C_MODULE_TIME]      ,C_UCLANG_DIR + "mods/time_uclm"        ,None],
    ["MOD_LANG"      ,c_enabled[C_MODULE_LANG]      ,C_UCLANG_DIR + "mods/lang_uclm"        ,None],
    ["MOD_PACK"      ,c_enabled[C_MODULE_PACK]      ,C_UCLANG_DIR + "mods/pack_uclm"        ,None],
    ["MOD_CIPHER"    ,c_enabled[C_MODULE_CIPHER]    ,C_UCLANG_DIR + "mods/cipher_uclm"      ,None],
    ["MOD_PARSER"    ,c_enabled[C_MODULE_PARSER]    ,C_UCLANG_DIR + "mods/parser_uclm"      ,None],
    ["MOD_MATH"      ,c_enabled[C_MODULE_MATH]      ,C_UCLANG_DIR + "mods/math_uclm"        ,None],
    ["MOD_GSL"       ,c_enabled[C_MODULE_GSL]       ,C_UCLANG_DIR + "mods/gsl_uclm"         ,None],
    ["MOD_PSQL"      ,c_enabled[C_MODULE_PSQL]      ,C_UCLANG_DIR + "mods/psql_uclm"        ,None],
    ["MOD_SQLITE"    ,c_enabled[C_MODULE_SQLITE]    ,C_UCLANG_DIR + "mods/sqlite_uclm"      ,None],
    ["MOD_HTTP"      ,c_enabled[C_MODULE_HTTP]      ,C_UCLANG_DIR + "mods/http_uclm"        ,None],
    ["MOD_WEBSOCKET" ,c_enabled[C_MODULE_WEBSOCKET] ,C_UCLANG_DIR + "mods/websocket_uclm"   ,None],
    ["MOD_CURL"      ,c_enabled[C_MODULE_CURL]      ,C_UCLANG_DIR + "mods/curl_uclm"        ,None],
    ["MOD_UCF"       ,c_enabled[C_MODULE_UCF]       ,C_UCLANG_DIR + "mods/ucf_uclm"         ,None],
    ["MOD_UCTCN"     ,c_enabled[C_MODULE_UCTCN]     ,C_UCLANG_DIR + "mods/uctcn_uclm"       ,None],
    ["MOD_UCMM"      ,c_enabled[C_MODULE_UCMM]      ,C_UCLANG_DIR + "mods/ucmm_uclm"        ,None],
    ["MOD_ADAPTRAIN" ,c_enabled[C_MODULE_ADAPTRAIN] ,C_UCLANG_DIR + "mods/adaptrain_uclm"   ,None],
    ["MOD_FTP"       ,c_enabled[C_MODULE_FTP]       ,C_UCLANG_DIR + "mods/ftp_uclm"         ,None],
    ["MOD_SSH2"      ,c_enabled[C_MODULE_SSH2]      ,C_UCLANG_DIR + "mods/ssh2_uclm"        ,None],
    ["MOD_GCRYPT"    ,c_enabled[C_MODULE_GCRYPT]    ,C_UCLANG_DIR + "mods/gcrypt_uclm"      ,None],
    ["MOD_ICONV"     ,c_enabled[C_MODULE_ICONV]     ,C_UCLANG_DIR + "mods/iconv_uclm"       ,None],
    ["MOD_JIT"       ,c_enabled[C_MODULE_JIT]       ,C_UCLANG_DIR + "mods/jit_uclm"         ,None],
    ["MOD_LIGHTNING" ,c_enabled[C_MODULE_LIGHTNING] ,C_UCLANG_DIR + "mods/lightning_uclm"   ,None],
    ["MOD_LLVM"      ,c_enabled[C_MODULE_LLVM]      ,C_UCLANG_DIR + "mods/llvm_uclm"        ,None],
    ["MOD_GA"        ,c_enabled[C_MODULE_GA]        ,C_UCLANG_DIR + "mods/ga_uclm"          ,None],
    ["MOD_AV"        ,c_enabled[C_MODULE_AV]        ,C_UCLANG_DIR + "mods/av_uclm"          ,None],
    ["MOD_AO"        ,c_enabled[C_MODULE_AO]        ,C_UCLANG_DIR + "mods/ao_uclm"          ,None],
    ["MOD_MPG"       ,c_enabled[C_MODULE_MPG]       ,C_UCLANG_DIR + "mods/mpg_uclm"         ,None],
    ["MOD_PORTAUDIO" ,c_enabled[C_MODULE_PORTAUDIO] ,C_UCLANG_DIR + "mods/portaudio_uclm"   ,None],
    ["MOD_GSTREAMER" ,c_enabled[C_MODULE_GSTREAMER] ,C_UCLANG_DIR + "mods/gstreamer_uclm"   ,None],
    ["MOD_IMAGE"     ,c_enabled[C_MODULE_IMAGE]     ,C_UCLANG_DIR + "mods/image_uclm"       ,None],
    ["MOD_OPENCV"    ,c_enabled[C_MODULE_OPENCV]    ,C_UCLANG_DIR + "mods/opencv_uclm"      ,None],
    ["MOD_DOCU"      ,c_enabled[C_MODULE_DOCU]      ,C_UCLANG_DIR + "mods/docu_uclm"        ,None],
    ["MOD_GLUT"      ,c_enabled[C_MODULE_GLUT]      ,C_UCLANG_DIR + "mods/glut_uclm"        ,None],
    ["MOD_GLEW"      ,c_enabled[C_MODULE_GLEW]      ,C_UCLANG_DIR + "mods/glew_uclm"        ,None],
    ["MOD_GL"        ,c_enabled[C_MODULE_GL]        ,C_UCLANG_DIR + "mods/gl_uclm"          ,None],
    ["MOD_FTGL"      ,c_enabled[C_MODULE_FTGL]      ,C_UCLANG_DIR + "mods/ftgl_uclm"        ,None],
    ["MOD_VG"        ,c_enabled[C_MODULE_VG]        ,C_UCLANG_DIR + "mods/vg_uclm"          ,None],
    ["MOD_IMXEGL"    ,c_enabled[C_MODULE_IMXEGL]    ,C_UCLANG_DIR + "mods/imxegl_uclm"      ,None],
    ["MOD_SNMP"      ,c_enabled[C_MODULE_SNMP]      ,C_UCLANG_DIR + "mods/snmp_uclm"        ,None],
    ["MOD_COMELM"    ,c_enabled[C_MODULE_COMELM]    ,C_UCLANG_DIR + "mods/comelm_uclm"      ,None],
    ["MOD_DLMS"      ,c_enabled[C_MODULE_DLMS]      ,C_UCLANG_DIR + "mods/dlms_uclm"        ,None],
    ["MOD_UCPAS"     ,c_enabled[C_MODULE_UCPAS]     ,C_UCLANG_DIR + "mods/ucpas_uclm"       ,None],
    ["MOD_FGETTOOLS" ,c_enabled[C_MODULE_FGETTOOLS] ,C_UCLANG_DIR + "mods/fgettools_uclm"   ,None],
    ["MOD_NODE"      ,c_enabled[C_MODULE_NODE]      ,C_UCLANG_DIR + "mods/node_uclm"        ,None],
    ["MOD_DDB"       ,c_enabled[C_MODULE_DDB]       ,C_UCLANG_DIR + "mods/ddb_uclm"         ,None],
    ["MOD_CONTAINERS",c_enabled[C_MODULE_CONTAINERS],C_UCLANG_DIR + "mods/containers_uclm"  ,None],
    ["MOD_ALGORITHMS",c_enabled[C_MODULE_ALGORITHMS],C_UCLANG_DIR + "mods/algorithms_uclm"  ,None],
    ["MOD_BINBITS"   ,c_enabled[C_MODULE_BINBITS]   ,C_UCLANG_DIR + "mods/binbits_uclm"     ,None],
    ["MOD_GRAPH"     ,c_enabled[C_MODULE_GRAPH]     ,C_UCLANG_DIR + "mods/graph_uclm"       ,None],
    ["MOD_JSON"      ,c_enabled[C_MODULE_JSON]      ,C_UCLANG_DIR + "mods/json_uclm"        ,None],
    ["MOD_XML"       ,c_enabled[C_MODULE_XML]       ,C_UCLANG_DIR + "mods/xml_uclm"         ,None],
    ["MOD_SOAPCL"    ,c_enabled[C_MODULE_SOAPCL]    ,C_UCLANG_DIR + "mods/soap/soapcl_uclm" ,None],
    ["MOD_SOAPSRV"   ,c_enabled[C_MODULE_SOAPSRV]   ,C_UCLANG_DIR + "mods/soap/soapsrv_uclm",None],
    ["MOD_PYTHON"    ,c_enabled[C_MODULE_PYTHON]    ,C_UCLANG_DIR + "mods/python_uclm"      ,None],
    ["MOD_V8"        ,c_enabled[C_MODULE_V8]        ,C_UCLANG_DIR + "mods/v8_uclm"          ,None],
    ["MOD_LUA"       ,c_enabled[C_MODULE_LUA]       ,C_UCLANG_DIR + "mods/lua_uclm"         ,None],
    ["MOD_MONO"      ,c_enabled[C_MODULE_MONO]      ,C_UCLANG_DIR + "mods/mono_uclm"        ,None],
    ["MOD_PERL"      ,c_enabled[C_MODULE_PERL]      ,C_UCLANG_DIR + "mods/perl_uclm"        ,None],
    ["MOD_UV"        ,c_enabled[C_MODULE_UV]        ,C_UCLANG_DIR + "mods/uv_uclm"          ,None],
    ["MOD_ZLIB"      ,c_enabled[C_MODULE_ZLIB]      ,C_UCLANG_DIR + "mods/zlib_uclm"        ,None],
    ["MOD_PIGPIO"    ,c_enabled[C_MODULE_PIGPIO]    ,C_UCLANG_DIR + "mods/pigpio_uclm"      ,None],
    ["MOD_FUSE"      ,c_enabled[C_MODULE_FUSE]      ,C_UCLANG_DIR + "mods/fuse_uclm"        ,None],
    ["MOD_ANDROID"   ,c_enabled[C_MODULE_ANDROID]   ,C_UCLANG_DIR + "mods/android_uclm"     ,None],
    ["MOD_NACL"      ,c_enabled[C_MODULE_NACL]      ,C_UCLANG_DIR + "mods/nacl_uclm"        ,None],
]

