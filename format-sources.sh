#!/bin/bash

for f in $(find ./src -type f -name "*.hpp"); do
	echo $f
	clang-format $f > "$f~"
	diff "$f" "$f~"
	if [ $? == 0 ]; then
		mv "$f~" "$f"
	fi
	rm "$f~" -f
done
