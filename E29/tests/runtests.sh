#!/bin/bash

runing_tests()
{
	local CFLAGS='-Wall -g -Wextra -rdynamic -fPIC -DNDEBUG'

	for file in $1; do
		gcc $CFLAGS "$file" -ldl -o "bin/${file%.c}" && "bin/${file%.c}"
	done
}

runing_tests "$1"