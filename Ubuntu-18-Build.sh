#!/bin/bash

BUILDDIR=build

mkdir $BUILDDIR

cd $BUILDDIR/

cmake -DCMAKE_BUILD_TYPE=Debug ../.

cmake --build .