include compiler.mk

SUPPRESS_WARN = 2> /dev/null

#===================================================
# BUILDING A STATIC LIBRARY
#===================================================
#
# 1. Defined Rules
#      1.1. build.library
#      1.2. build.library.initial
#      1.3. build.library.sckeleton
#      1.4. $(LIBLIBRARY_TARGET)
#      1.5. $(LIBRARY_ENDING)
#      1.6. build.final.configuration
#      1.7. clean
#      1.8. check
#
#===================================================

build.library: build.library.initial build.final.configuration tests

#---------------------------------------------------
# INITILIZING THE BASIC STRUCTURE
#---------------------------------------------------

build.library.initial: clean build.library.sckeleton $(STATIC_LIBRARY_TARGET) $(STATIC_LIBRARY_ENDING)

build.library.sckeleton:
	@mkdir -p bin/tests/libraries
	@mkdir objects
	@mkdir report
	@mkdir build

#---------------------------------------------------
# MAKE THE .so FILE
#---------------------------------------------------

$(STATIC_LIBRARY_TARGET): $(STATIC_LIBRARY_OBJECTS)
	ar rcs $@ $^
	ranlib $@

$(STATIC_LIBRARY_ENDING): $(STATIC_LIBRARY_OBJECTS)
	$(CC) -shared -o $@ $^

#---------------------------------------------------
# FINAL EXTRA CONFIGURATION FOR THE PROJECT
#---------------------------------------------------

build.final.configuration:
	@mv $(filter %.o, $(STATIC_LIBRARY_OBJECTS)) objects/ $(SUPPRESS_WARN) || true

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