#!/usr/bin/env bash

cd ./ext/T-SPLINE/build
make -j4
sudo make install

cd ../../..
make
