#---------------------------------------------------
# GNUCC PARAMETERS
#---------------------------------------------------

CFLAGS := -Wall -g -Wextra -rdynamic -fPIC -DNDEBUG
BINARY := ./bin/E29

#---------------------------------------------------
# SOURCE FILES (*.c, *.o)
#---------------------------------------------------

SOURCES := $(wildcard src/**/*.c src/*.c)
OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

#---------------------------------------------------
# TESTS CONFIGURATION
#---------------------------------------------------

LIB_FILES := $(wildcard tests/libraries/*_tests.c)
LIB_TESTS := $(patsubst tests/libraries/%.c, %, $(LIB_FILES))

#---------------------------------------------------
# REGEX TO FIND FUNCTIONS THAT CAN BE A PROBLEM
#---------------------------------------------------

BADFUNCS := '[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)'

#---------------------------------------------------
# BUILD DYNAMIC LIBRARIES
#---------------------------------------------------

DYNAMIC_LIBRARY_SOURCES := $(wildcard libraries/*.c)
DYNAMIC_LIBRARY_OBJECTS := $(patsubst %.c, %.o, $(DYNAMIC_LIBRARY_SOURCES))
DYNAMIC_LIBRARIES_NAMES := $(patsubst libraries/%.c, %, $(DYNAMIC_LIBRARY_SOURCES))