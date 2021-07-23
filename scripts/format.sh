#!/bin/bash

cd $(dirname $0)/..

clang-format -i *.h *.c
