#!/usr/bin/env bash
gcc -c count_args.S
ld -o count_args count_args.o
