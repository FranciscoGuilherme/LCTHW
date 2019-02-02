#---------------------------------------------------
# GNUCC PARAMETERS
#---------------------------------------------------

CFLAGS := -Wall -g -Wextra
BINARY := ./bin/E03

#---------------------------------------------------
# SOURCE FILES (*.c, *.o)
#---------------------------------------------------

SOURCES := $(wildcard src/**/*.c src/*.c)
OBJECTS := $(patsubst %.c, %.o, $(SOURCES))