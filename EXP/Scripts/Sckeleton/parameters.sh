#!/bin/bash

: '
|----------------------------------------------
| DEFINING ALL DIRECTORIES/FILES TO BE CREATE
|----------------------------------------------
'

readonly DIRECTORIES=(libraries shared src tests)
readonly SUBDIR_TEST=(libraries src)
readonly FILES=(Makefile compiler.mk valgrind.mk LICENSE README.md)