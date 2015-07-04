
UCLANG_DIR=../..
UCLANG_BUILD_DIR=${UCLANG_DIR}/uclang_build
LIBS_DIR=${UCLANG_DIR}/uclang/libs

CC_FLAGS=-O2 -DLINUX -fno-strict-aliasing -Wall
CC_LIBS=-L${UCLANG_BUILD_DIR} -lbase_ucll -lnode_ucll

all: dict json jit

# - preprocess ucl libnode header -
p.ucl_libnode.h: 
	process \
	${LIBS_DIR}/libnode_ucll/header_files/ucl_libnode.h \
	${LIBS_DIR}/libnode_ucll/header_files/ \
	${LIBS_DIR}/libbase_ucll/header_files/ > p.ucl_libnode.h

# - compile examples -
dict: p.ucl_libnode.h dict.cc
	g++ dict.cc -o dict ${CC_FLAGS} ${CC_LIBS}

json: p.ucl_libnode.h json.cc
	g++ json.cc -o json ${CC_FLAGS} ${CC_LIBS}

jit: p.ucl_libnode.h jit.cc
	g++ jit.cc -o jit ${CC_FLAGS} ${CC_LIBS}

clean:
	rm -f p.ucl_libnode.h
	rm -f dict dict.o
	rm -f json json.o
	rm -f jit jit.o

