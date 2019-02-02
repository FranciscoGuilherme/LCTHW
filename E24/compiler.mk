#---------------------------------------------------
# GNUCC PARAMETERS
#---------------------------------------------------

CFLAGS := -Wall -g -Wextra -DNDEBUG
BINARY := ./bin/E24

#---------------------------------------------------
# SOURCE FILES (*.c, *.o)
#---------------------------------------------------

SOURCES := $(wildcard src/**/*.c src/*.c)
OBJECTS := $(patsubst %.c, %.o, $(SOURCES))