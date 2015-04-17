
import os;

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
C_MODULE_TIME       = index; index += 1
C_MODULE_LANG       = index; index += 1
C_MODULE_PACK       = index; index += 1
C_MODULE_CIPHER     = index; index += 1
C_MODULE_PARSER     = index; index += 1
C_MODULE_MATH       = index; index += 1
C_MODULE_PSQL       = index; index += 1
C_MODULE_SQLITE     = index; index += 1
C_MODULE_HTTP       = index; index += 1
C_MODULE_WEBSOCKET  = index; index += 1
C_MODULE_CURL       = index; index += 1
C_MODULE_UCF        = index; index += 1
C_MODULE_UCTCN      = index; index += 1
C_MODULE_ADAPTRAIN  = index; index += 1
C_MODULE_FTP        = index; index += 1
C_MODULE_SSH2       = index; index += 1
C_MODULE_GCRYPT     = index; index += 1
C_MODULE_ICONV      = index; index += 1
C_MODULE_JIT        = index; index += 1
C_MODULE_LIGHTNING  = index; index += 1
C_MODULE_LLVM       = index; index += 1
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
C_MODULE_UCPAS      = index; index += 1
C_MODULE_NODE       = index; index += 1
C_MODULE_DDB        = index; index += 1
C_MODULE_CONTAINERS = index; index += 1
C_MODULE_GRAPH      = index; index += 1
C_MODULE_JSON       = index; index += 1
C_MODULE_XML        = index; index += 1
C_MODULE_SOAPCL     = index; index += 1
C_MODULE_SOAPSRV    = index; index += 1
C_MODULE_PYTHON     = index; index += 1
C_MODULE_V8         = index; index += 1
C_MODULE_UV         = index; index += 1
C_MODULE_FUSE       = index; index += 1
C_MODULE_ANDROID    = index; index += 1
C_MODULE_NACL       = index; index += 1

index = 0
CFG_NAME   = index; index += 1
CFG_TARGET = index; index += 1
CFG_DIR    = index; index += 1
CFG_MODULE = index; index += 1

c_cfg = [
    ["LIB_BASE"      ,True ,C_UCLANG_DIR + "libs/libbase_ucll"     ,None],
    ["LIB_FTGL"      ,True ,C_UCLANG_DIR + "libs/libftgl_ucll"     ,None],
    ["LIB_NODE"      ,True ,C_UCLANG_DIR + "libs/libnode_ucll"     ,None],
    ["UCLANG"        ,True ,C_UCLANG_DIR + "progs/uclang"          ,None],
    ["NODE"          ,True ,C_UCLANG_DIR + "progs/node"            ,None],
    ["ENCIPHER"      ,True ,C_UCLANG_DIR + "progs/encipher"        ,None],
    ["MOD_BASE"      ,True ,C_UCLANG_DIR + "mods/base_uclm"        ,None],
    ["MOD_SYS"       ,True ,C_UCLANG_DIR + "mods/sys_uclm"         ,None],
    ["MOD_TIME"      ,True ,C_UCLANG_DIR + "mods/time_uclm"        ,None],
    ["MOD_LANG"      ,True ,C_UCLANG_DIR + "mods/lang_uclm"        ,None],
    ["MOD_PACK"      ,True ,C_UCLANG_DIR + "mods/pack_uclm"        ,None],
    ["MOD_CIPHER"    ,True ,C_UCLANG_DIR + "mods/cipher_uclm"      ,None],
    ["MOD_PARSER"    ,True ,C_UCLANG_DIR + "mods/parser_uclm"      ,None],
    ["MOD_MATH"      ,True ,C_UCLANG_DIR + "mods/math_uclm"        ,None],
    ["MOD_PSQL"      ,True ,C_UCLANG_DIR + "mods/psql_uclm"        ,None],
    ["MOD_SQLITE"    ,True ,C_UCLANG_DIR + "mods/sqlite_uclm"      ,None],
    ["MOD_HTTP"      ,True ,C_UCLANG_DIR + "mods/http_uclm"        ,None],
    ["MOD_WEBSOCKET" ,True ,C_UCLANG_DIR + "mods/websocket_uclm"   ,None],
    ["MOD_CURL"      ,True ,C_UCLANG_DIR + "mods/curl_uclm"        ,None],
    ["MOD_UCF"       ,False,C_UCLANG_DIR + "mods/ucf_uclm"         ,None],
    ["MOD_UCTCN"     ,False,C_UCLANG_DIR + "mods/uctcn_uclm"       ,None],
    ["MOD_ADAPTRAIN" ,False,C_UCLANG_DIR + "mods/adaptrain_uclm"   ,None],
    ["MOD_FTP"       ,True ,C_UCLANG_DIR + "mods/ftp_uclm"         ,None],
    ["MOD_SSH2"      ,True ,C_UCLANG_DIR + "mods/ssh2_uclm"        ,None],
    ["MOD_GCRYPT"    ,True ,C_UCLANG_DIR + "mods/gcrypt_uclm"      ,None],
    ["MOD_ICONV"     ,True ,C_UCLANG_DIR + "mods/iconv_uclm"       ,None],
    ["MOD_JIT"       ,False,C_UCLANG_DIR + "mods/jit_uclm"         ,None],
    ["MOD_LIGHTNING" ,False,C_UCLANG_DIR + "mods/lightning_uclm"   ,None],
    ["MOD_LLVM"      ,True ,C_UCLANG_DIR + "mods/llvm_uclm"        ,None],
    ["MOD_AV"        ,True ,C_UCLANG_DIR + "mods/av_uclm"          ,None],
    ["MOD_AO"        ,True ,C_UCLANG_DIR + "mods/ao_uclm"          ,None],
    ["MOD_MPG"       ,True ,C_UCLANG_DIR + "mods/mpg_uclm"         ,None],
    ["MOD_PORTAUDIO" ,True ,C_UCLANG_DIR + "mods/portaudio_uclm"   ,None],
    ["MOD_GSTREAMER" ,True ,C_UCLANG_DIR + "mods/gstreamer_uclm"   ,None],
    ["MOD_IMAGE"     ,True ,C_UCLANG_DIR + "mods/image_uclm"       ,None],
    ["MOD_OPENCV"    ,True ,C_UCLANG_DIR + "mods/opencv_uclm"      ,None],
    ["MOD_DOCU"      ,True ,C_UCLANG_DIR + "mods/docu_uclm"        ,None],
    ["MOD_GLUT"      ,True ,C_UCLANG_DIR + "mods/glut_uclm"        ,None],
    ["MOD_GLEW"      ,True ,C_UCLANG_DIR + "mods/glew_uclm"        ,None],
    ["MOD_GL"        ,True ,C_UCLANG_DIR + "mods/gl_uclm"          ,None],
    ["MOD_FTGL"      ,True ,C_UCLANG_DIR + "mods/ftgl_uclm"        ,None],
    ["MOD_VG"        ,False,C_UCLANG_DIR + "mods/vg_uclm"          ,None],
    ["MOD_IMXEGL"    ,False,C_UCLANG_DIR + "mods/imxegl_uclm"      ,None],
    ["MOD_SNMP"      ,True ,C_UCLANG_DIR + "mods/snmp_uclm"        ,None],
    ["MOD_COMELM"    ,False,C_UCLANG_DIR + "mods/comelm_uclm"      ,None],
    ["MOD_UCPAS"     ,False,C_UCLANG_DIR + "mods/ucpas_uclm"       ,None],
    ["MOD_NODE"      ,True, C_UCLANG_DIR + "mods/node_uclm"        ,None],
    ["MOD_DDB"       ,False,C_UCLANG_DIR + "mods/ddb_uclm"         ,None],
    ["MOD_CONTAINERS",True ,C_UCLANG_DIR + "mods/containers_uclm"  ,None],
    ["MOD_GRAPH"     ,True ,C_UCLANG_DIR + "mods/graph_uclm"       ,None],
    ["MOD_JSON"      ,True ,C_UCLANG_DIR + "mods/json_uclm"        ,None],
    ["MOD_XML"       ,True ,C_UCLANG_DIR + "mods/xml_uclm"         ,None],
    ["MOD_SOAPCL"    ,True ,C_UCLANG_DIR + "mods/soap/soapcl_uclm" ,None],
    ["MOD_SOAPSRV"   ,True ,C_UCLANG_DIR + "mods/soap/soapsrv_uclm",None],
    ["MOD_PYTHON"    ,True ,C_UCLANG_DIR + "mods/python_uclm"      ,None],
    ["MOD_V8"        ,True ,C_UCLANG_DIR + "mods/v8_uclm"          ,None],
    ["MOD_UV"        ,True ,C_UCLANG_DIR + "mods/uv_uclm"          ,None],
    ["MOD_FUSE"      ,True ,C_UCLANG_DIR + "mods/fuse_uclm"        ,None],
    ["MOD_ANDROID"   ,False,C_UCLANG_DIR + "mods/android_uclm"     ,None],
    ["MOD_NACL"      ,False,C_UCLANG_DIR + "mods/nacl_uclm"        ,None],
]

