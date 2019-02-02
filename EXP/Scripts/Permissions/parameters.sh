#!/bin/bash

: '
|----------------------------------------------
| PATH OF ERRO LOG FILE & PERMISSION NUMBERS
|----------------------------------------------
'

declare -A PERMISSIONS

readonly LOG_FILE=/tmp/error_permissions.log
readonly PERMISSIONS=([FILE]=664 [DIRECTORY]=755)