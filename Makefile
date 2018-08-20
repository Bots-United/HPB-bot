CC = gcc
CPP = g++
TARGET = hpb_bot_mm
ARCHFLAG = -m32
BASEFLAGS = -Dstricmp=strcasecmp -Dstrcmpi=strcasecmp
OPTFLAGS =
CPPFLAGS = ${BASEFLAGS} ${OPTFLAGS} ${ARCHFLAG} -O2 -w \
	-I"../metamod" \
	-I"../../hlsdk/public" \
	-I"../../hlsdk/common" \
	-I"../../hlsdk/dlls" \
	-I"../../hlsdk/engine" \
	-I"../../hlsdk/pm_shared"

OBJ = 	bot.o \
	bot_chat.o \
	bot_client.o \
	bot_combat.o \
	bot_models.o \
	bot_navigate.o \
	bot_start.o \
	dll.o \
	engine.o \
	h_export.o \
	util.o \
	waypoint.o

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
SO_SUFFIX = so
endif
ifeq ($(UNAME_S),Darwin)
SO_SUFFIX = dylib
endif

${TARGET}_i386.${SO_SUFFIX}: ${OBJ}
	${CPP} ${ARCHFLAG} -fPIC -shared -o $@ ${OBJ} -ldl
	-mkdir Release
	mv *.o Release
	mv $@ Release

clean:
	-rm -f Release/*.o

distclean:
	-rm -rf Release

%.o:	%.cpp
	${CPP} ${CPPFLAGS} -c $< -o $@

%.o:	%.c
	${CC} ${CPPFLAGS} -c $< -o $@
