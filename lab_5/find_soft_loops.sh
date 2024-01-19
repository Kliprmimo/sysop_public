#!/bin/bash

find_loop_symlinks() {
    local directory="$1"

    find "$directory" -type l -exec bash -c '
        source="$1"
        target=$(readlink "$source")
        if [[ "$target" == /* ]]; then
            target_path="$target"
        else
            target_path="$(dirname "$source")/$target"
        fi

        if [ -e "$target_path" ]; then
            echo "Loop detected: $source -> $target"
        fi
    ' _ {} \;
}

if [ $# -eq 0 ]; then
    echo "Usage: $0 <directory>"
    exit 1
fi

directory=$1
find_loop_symlinks "$directory"
