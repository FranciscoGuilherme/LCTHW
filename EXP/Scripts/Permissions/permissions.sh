#!/bin/bash

: '
|----------------------------------------------
| SHELL SCRIPT FOR ALTER PERMISSIONS
|----------------------------------------------
|
| Project  : Permissions
| Filename : permissions.sh
| Version  : 0.0.0
| Date     : January 13, 2019
|
|----------------------------------------------
|
| Copyright (c) 2019, Francisco G. A. S. Bessa
| All rights reserved.
|
|----------------------------------------------

|----------------------------------------------
| HOW TO EXECUTE THIS SCRIPT
|----------------------------------------------
|
| Command : ./{your_path}/permissions.sh {arg}
| {arg}   : Absolute path directory that
|           you want to reset the permissions
|
|----------------------------------------------

|----------------------------------------------
| BEFORE THE SCRIPT EXECUTION
|----------------------------------------------
|
| Warning 00 : Do not accept duplicate names
| Warning 01 : You do not need to execute this
|              script as root in your home dir
| Warning 02 : Do not accept names with spaces
|			   like "My images"
|
|----------------------------------------------
'

source /home/francisco/Projects/Personal/LCTHW/EXP/Scripts/Common/dbg.sh
source /home/francisco/Projects/Personal/LCTHW/EXP/Scripts/Permissions/parameters.sh

apply_permissions()
{
	local directory=$1

	__ERRNO__=$(cd "$directory" 2>&1) || check $? "$__ERRNO__"

	for item in $directory/*; do
		if [ -d "$item" ]; then
			chmod "${PERMISSIONS[DIRECTORY]}" "$item"
			apply_permissions "$item"
		fi

		chmod "${PERMISSIONS[FILE]}" "$item"
	done

	return 0
}

get_directory_path()
{
	local path=$1

	while [ -z "$path" ]; do
		printf "%s" "Input the absolute path of the directory: "
		read -r path
	done

	__ERRNO__=$(apply_permissions "$path" 2>&1) || check $? "$__ERRNO__"
	__ERRNO__=$(chmod "${PERMISSIONS[DIRECTORY]}" "$path" 2>&1) || check $? "$__ERRNO__"

	return 0
}

main()
{
	__ERRNO__=$(get_directory_path "$1" 2>&1) || check $? "$__ERRNO__"

	printf "%s\n" "All directories and files have been updated."
}

main "$1"
