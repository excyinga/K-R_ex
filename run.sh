#!/bin/bash

set -ex
gcc -Wall -ansi -masm=intel -O0 -o app.bin src/$1.c
./app.bin