include compiler.mk
include valgrind.mk

SUPPRESS_WARN = 2> /dev/null

#===================================================
# BUILDING A DEFAULT PROJECT
#===================================================
#
# 1. Defined Rules
#      1.1. build.program
#      1.2. build.program.initial
#      1.3. build.program.sckeleton
#      1.4. build.program.executable
#      1.5. build.program.report
#      1.6. performance.analysis
#      1.7. build.program.final.configuration
#      1.8. clean
#
#===================================================

build.program: build.program.report build.program.final.configuration

#---------------------------------------------------
# MAKE THE BASIC STRUCTURE
#---------------------------------------------------

build.program.initial: build.program.sckeleton $(OBJECTS)

build.program.sckeleton:
	@mkdir objects
	@mkdir report
	@mkdir bin

#---------------------------------------------------
# MAKE THE EXECUTABLE FILE
#---------------------------------------------------

build.program.executable: clean build.program.initial
	$(CC) $(OBJECTS) -o $(BINARY)

#---------------------------------------------------
# MAKE A DETAIL REPORT (MEMORY & PROGRAM STATUS)
#---------------------------------------------------

build.program.report: build.program.executable
	valgrind $(MEMORY_LEAKS) $(BINARY) db.dat c

performance.analysis:
	valgrind $(CALLGRIND) $(BINARY) db.dat s 1 Nome1 Email1
	valgrind $(CACHEGRIND) $(BINARY) db.dat s 2 Nome2 Email2

#---------------------------------------------------
# FINAL EXTRA CONFIGURATION FOR THE PROJECT
#---------------------------------------------------

build.program.final.configuration:
	@mv $(filter %.o, $(OBJECTS)) objects/

#---------------------------------------------------
# CLEANING THE PROJECT
#---------------------------------------------------

clean:
	@rm -R bin objects report $(SUPPRESS_WARN) || true