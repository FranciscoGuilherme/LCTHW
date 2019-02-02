include compiler.mk
include valgrind.mk

SUPPRESS_WARN = 2> /dev/null

#===================================================
# BUILDING A DYNAMIC LIBRARY
#===================================================
#
# 1. Defined Rules
#      1.1. build.library
#      1.2. build.library.initial
#      1.3. build.library.sckeleton
#      1.4. build.library.so
#      1.5. build.library.report
#      1.6. performance.analysis
#      1.7. build.final.configuration
#      1.8. tests
#      1.9. clean
#      2.0. check
#
#===================================================

build.library: build.library.report build.final.configuration tests

#---------------------------------------------------
# INITILIZING THE BASIC STRUCTURE
#---------------------------------------------------

build.library.initial: build.library.sckeleton build.library.so

build.library.sckeleton:
	@mkdir -p bin/tests/libraries
	@mkdir -p bin/tests/src
	@mkdir objects
	@mkdir report
	@mkdir build

#---------------------------------------------------
# MAKE THE .so FILE
#---------------------------------------------------

build.library.so: $(DYNAMIC_LIBRARY_OBJECTS)
	@for lib in $(DYNAMIC_LIBRARIES_NAMES); do\
		$(CC) -shared -o build/$$lib.so libraries/$$lib.o;\
	done

	$(CC) $(CFLAGS) src/main.c -ldl -o $(BINARY)

#---------------------------------------------------
# MAKE A DETAIL REPORT (MEMORY & PROGRAM STATUS)
#---------------------------------------------------

build.library.report: clean build.library.initial
	valgrind $(MEMORY_LEAKS) $(BINARY) build/string_formats.so print_a_message "Hello World!"

performance.analysis:
	valgrind $(CALLGRIND) $(BINARY) build/string_formats.so print_a_message "Hello World!"
	valgrind $(CACHEGRIND) $(BINARY) build/string_formats.so print_a_message "Hello World!"

#---------------------------------------------------
# FINAL EXTRA CONFIGURATION FOR THE PROJECT
#---------------------------------------------------

build.final.configuration:
	@mv $(filter %.o, $(OBJECTS)) objects/ $(SUPPRESS_WARN) || true
	@mv $(filter %.o, $(DYNAMIC_LIBRARY_OBJECTS)) objects/ $(SUPPRESS_WARN) || true

#---------------------------------------------------
# RUNING TESTS
#---------------------------------------------------

.PHONY: tests

tests:
	@bash tests/runtests.sh "$(LIB_FILES)"

#---------------------------------------------------
# CLEANING THE PROJECT
#---------------------------------------------------

clean:
	@rm -R objects report build bin $(SUPPRESS_WARN) || true

#---------------------------------------------------
# LOOKING FOR SECURITY PROBLEMS
#---------------------------------------------------

check:
	@egrep $(BADFUNCS) $(SOURCES) $(LIB_FILES) || true