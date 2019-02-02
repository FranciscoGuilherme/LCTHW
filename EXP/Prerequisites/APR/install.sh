#!/bin/bash

: '
|----------------------------------------------
| SHELL SCRIPT FOR INSTALL APR LYBRARI
|----------------------------------------------
|
| Project  : APR Lybrari install script
| Filename : apr.sh
| Version  : 0.0.0
| Date     : January 30, 2019
|
|----------------------------------------------
|
| Copyright (c) 2019, Francisco G. A. S. Bessa
| All rights reserved.
|
|----------------------------------------------
'

source dbg.sh
source parameters.sh

set -e

clean()
{
	rm -rf "${APR_FILE%.tar.gz}" "$APR_FILE"
	rm -rf "${APR_UTIL_FILE%.tar.gz}" "$APR_UTIL_FILE"

	return 0
}

get_apr_util_by_source_base()
{
	__ERRNO__=$(curl -L -O "$APR_UTIL" 2>&1) || check $? "$__ERRNO__"
	tar -xzvf "$APR_UTIL_FILE"

	cd "${APR_UTIL_FILE%.tar.gz}"

	./configure --with-apr=/usr/local/apr
	make && make install

	return 0
}

get_apr_by_source_base()
{
	__ERRNO__=$(curl -L -O "$APR" 2>&1) || check $? "$__ERRNO__"
	tar -xzvf "$APR_FILE"

	cd "${APR_FILE%.tar.gz}"

	./configure && make && make install

	return 0
}

main()
{
	cd /tmp

	__ERRNO__=$(get_apr_by_source_base 2>&1) || check $? "$__ERRNO__"

	cd /tmp

	__ERRNO__=$(get_apr_util_by_source_base 2>&1) || check $? "$__ERRNO__"

	cd /tmp

	__ERRNO__=$(clean 2>&1) || check $? "$__ERRNO__"
}

main