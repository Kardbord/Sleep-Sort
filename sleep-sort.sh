#!/bin/bash
#set -x

container=( 2 5 4 6 8 10 7 9 3 1 )
offset=0.05

for i in "${container[@]}"; do
    if (( i >= 0 )); then
        sleep "$(echo "$i*$offset" | bc -l)" &&  echo "$i" &
    fi
done

wait
