#!/bin/sh

rm -rf ./build
rm -rf ./bin

cmake -B./build -S./src/cpp
cd ./build
make
