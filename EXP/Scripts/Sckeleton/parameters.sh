#!/bin/bash

: '
|----------------------------------------------
| DEFINING ALL DIRECTORIES/FILES TO BE CREATE
|----------------------------------------------
'

readonly DIRECTORIES=(libraries shared src tests)
readonly SUBDIR_TEST=(libraries src)
readonly FILES=(Makefile compiler.mk valgrind.mk LICENSE README.md)
readonly PERMISSIONS_SCRIPT_DIRECTORY=/home/francisco/Projects/Personal/LCTHW/EXP/Scripts/Permissions/permissions.sh
