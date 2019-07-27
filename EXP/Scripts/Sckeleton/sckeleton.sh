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

source /home/francisco/Projects/Personal/LCTHW/EXP/Scripts/Common/dbg.sh
source /home/francisco/Projects/Personal/LCTHW/EXP/Scripts/Sckeleton/parameters.sh

function build_sckeleton()
{
    local DIRECTORIES_LENGTT=${#DIRECTORIES[@]}
    local SUBDIR_TEST_LENGTH=${#SUBDIR_TEST[@]}
    local FILES_LENGTH=${#FILES[@]}

    for ((i = 0; i < DIRECTORIES_LENGTT; i++)); do
        mkdir "${DIRECTORIES[$i]}"
    done

    for ((i = 0; i < FILES_LENGTH; i++)); do
        touch "${FILES[$i]}" || return
    done

    cd tests

    for ((i = 0; i < SUBDIR_TEST_LENGTH; i++)); do
        mkdir "${SUBDIR_TEST[$i]}"
    done

    cd ..
}

function get_target_directory()
{
    local path=$1

    while [ -z "$path" ]
    do
        printf "%s" "I need the pull path to build C sckeleton: "
        read -r path
    done

    __=$path
}

function main()
{
    get_target_directory "$1"; path=${__}

    if [ "$(pwd)" != "$path" ]; then
        cd "$path" || return
    fi

    build_sckleton && cd ..

    bash "$PERMISSIONS_SCRIPT_DIRECTORY" "$path"
}

main "$1"
