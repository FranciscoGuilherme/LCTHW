#---------------------------------------------------
# GNUCC PARAMETERS
#---------------------------------------------------

PREFIX ?= /usr/local
CFLAGS := -Wall -g -I${PREFIX}/apr/include/apr-1 -I${PREFIX}/apr/include/apr-util-1 -D_LARGEFILE64_SOURCE=1
LDLIBS := -L${PREFIX}/apr/lib -lapr-1 -pthread -laprutil-1
BINARY := ./bin/E26

#---------------------------------------------------
# SOURCE FILES (*.c, *.o)
#---------------------------------------------------

SOURCES := $(wildcard src/**/*.c src/*.c)
OBJECTS := $(patsubst %.c, %.o, $(SOURCES))