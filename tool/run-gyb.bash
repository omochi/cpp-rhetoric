#!/bin/bash
set -ueo pipefail
cd "$(dirname "$0")"
cd ..
for file in $(find src -name "*.gyb"); do
	dest=${file%.*}
	echo "gyb: $file => $dest"
	gyb "$file" -o "$dest" --line-directive ""
done
