#!/bin/bash

runing_tests()
{
	local CFLAGS='-Wall -g -Wextra -rdynamic -fPIC -DNDEBUG'
	
	local MEMORY_LEAKS='--leak-check=full'
	local CALLGRIND='--dsymutil=yes --tool=callgrind --callgrind-out-file=report/callgrind.out.%p'
	local CACHEGRIND='--tool=cachegrind --cachegrind-out-file=report/cachegrind.out.%p'

	for file in $1; do
		gcc $CFLAGS -o "bin/${file%.c}" "$file" build/static_lib.a && "bin/${file%.c}"

		valgrind "$MEMORY_LEAKS" "bin/${file%.c}"
		valgrind $CALLGRIND "bin/${file%.c}"
		valgrind $CACHEGRIND "bin/${file%.c}"
	done
}

runing_tests "$1"