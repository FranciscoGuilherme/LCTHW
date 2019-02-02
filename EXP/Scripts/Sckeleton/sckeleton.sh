#!/bin/bash

: '
|----------------------------------------------
| SHELL SCRIPT FOR BUILD BASIC C STRUCTURE
|----------------------------------------------
|
| Project  : Default permissions
| Filename : sckeleton.sh
| Version  : 0.0.0
| Date     : January 23, 2019
|
|----------------------------------------------
|
| Copyright (c) 2019, Francisco G. A. S. Bessa
| All rights reserved.
|
|----------------------------------------------
'

source ~/Learning/Code/Refactor/C/EXP/Scripts/Sckeleton/dbg.sh
source ~/Learning/Code/Refactor/C/EXP/Scripts/Sckeleton/parameters.sh

build_sckleton()
{
	local DIRECTORIES_LENGTT=${#DIRECTORIES[@]}
	local SUBDIR_TEST_LENGTH=${#SUBDIR_TEST[@]}
	local FILES_LENGTH=${#FILES[@]}

	for ((i = 0; i < DIRECTORIES_LENGTT; i++)); do
		mkdir "${DIRECTORIES[$i]}"
	done

	for ((i = 0; i < FILES_LENGTH; i++)); do
		touch "${FILES[$i]}"
	done

	cd tests

	for ((i = 0; i < SUBDIR_TEST_LENGTH; i++)); do
		mkdir "${SUBDIR_TEST[$i]}"
	done

	cd ..
}

get_target_directory()
{
	local path=$1

	while [ -z "$path" ]
		do
			printf "%s" "I need the pull path to build C sckeleton: "
			read -r path
		done

	__=$path
}

main()
{
	get_target_directory "$1"; path=${__}

	if [ "$(pwd)" != "$path" ]; then
		cd "$path"
	fi

	build_sckleton && cd ..

	bash ~/Learning/Code/Refactor/C/EXP/Scripts/Permissions/permissions.sh "$path"
}

main "$1"
