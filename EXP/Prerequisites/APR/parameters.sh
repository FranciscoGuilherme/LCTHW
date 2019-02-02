#!/bin/bash

readonly LOG_FILE='/tmp/error_apr_install.log'

: '
|----------------------------------------------
| APR FILE VERSIONS
|----------------------------------------------
'

readonly APR_FILE='apr-1.4.6.tar.gz'
readonly APR_UTIL_FILE='apr-util-1.4.1.tar.gz'

: '
|----------------------------------------------
| EXTERN URL POINTING TO RESOURCES BASE
|----------------------------------------------
'

readonly APR="http://archive.apache.org/dist/apr/$APR_FILE"
readonly APR_UTIL="http://archive.apache.org/dist/apr/$APR_UTIL_FILE"