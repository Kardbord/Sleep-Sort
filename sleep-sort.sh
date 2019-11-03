#!/bin/bash
#set -x

FACTOR=0.05

if [ $# -eq 0 ]; then
    echo -e "No arguments supplied. Provide a list of positive numbers to sort.\n"
    echo -e "$0\n"
    echo -e "Usage:\n"
    echo -e "  $0 [number1] [number2] ..."
    echo -e "  Example: $0 0 2 1 6 3 8 1"
    exit 1
fi

container=( "$@" )
integer_check='^[0-9]+$'

for i in "${container[@]}"; do
    if [[ $i =~ $integer_check ]] && [ "$i" -ge 0 ]; then
        sleep "$(echo "$i*$FACTOR" | bc -l)" && echo "$i" &
    else
        echo "skipping invalid input..."
    fi
done

wait
