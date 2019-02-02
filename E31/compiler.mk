#---------------------------------------------------
# GNUCC PARAMETERS
#---------------------------------------------------

CFLAGS := -Wall -g -Wextra
BINARY := ./bin/E31

#---------------------------------------------------
# SOURCE FILES (*.c, *.o)
#---------------------------------------------------

SOURCES := $(wildcard src/**/*.c src/*.c)
OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

#---------------------------------------------------
# REGEX TO FIND FUNCTIONS THAT CAN BE A PROBLEM
#---------------------------------------------------

BADFUNCS := '[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)'