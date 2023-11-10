#!/bin/bash

set -ex
gcc -Wall -Werror -ansi -masm=intel -o app.bin src/$1.c
./app.bin