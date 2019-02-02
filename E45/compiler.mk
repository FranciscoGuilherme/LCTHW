#---------------------------------------------------
# GNUCC PARAMETERS
#---------------------------------------------------

CFLAGS := -Wall -g -Wextra -rdynamic -fPIC -DNDEBUG

#---------------------------------------------------
# REGEX TO FIND FUNCTIONS THAT CAN BE A PROBLEM
#---------------------------------------------------

BADFUNCS := '[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)'

#---------------------------------------------------
# BUILD STATIC LIBRARY
#---------------------------------------------------

STATIC_LIBRARY_TARGET := build/static_lib.a
STATIC_LIBRARY_ENDING := $(patsubst %.a, %.so, $(STATIC_LIBRARY_TARGET))
STATIC_LIBRARY_SOURCES := $(wildcard libraries/*.c)
STATIC_LIBRARY_OBJECTS := $(patsubst %.c, %.o, $(STATIC_LIBRARY_SOURCES))