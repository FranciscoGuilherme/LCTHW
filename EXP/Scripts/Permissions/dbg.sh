#!/bin/bash

: '
|----------------------------------------------
| ERROR TREATMENT
|----------------------------------------------
'

build_error_file()
{
	__ERRNO__="$1"

	{
		printf "%s\n" "-------------------------------"
		printf "%s\n\n" "$(date)"
		printf "[ERROR] (%s)\n" "$__ERRNO__"
	} >> "$LOG_FILE"
}

check()
{
	__CODE__=$1
	__ERRNO__=$2

	if [ -z "$__CODE__" ] || [ "$__CODE__" != 0 ]; then
		build_error_file "$__ERRNO__"

		printf "%s\n\n" "Somenthing didn't work well. Error saved on $LOG_FILE"
		printf "[ERROR] (%s)\n" "$__ERRNO__"

		return 1
	fi
}