#!/usr/bin/env bash

set -e
{
	cat <<-'EOH'
	# This file shows all the individuals contributing to the  content of this repository.
	EOH
	echo
	git log --format='%aN <%aE>' | LC_ALL=C.UTF-8 sort -uf
} > AUTHORS
