#!/bin/bash

cd $(dirname $0)/..

clang-format -i include/*.h src/*.c src/*.h include/*.h test/*.c
