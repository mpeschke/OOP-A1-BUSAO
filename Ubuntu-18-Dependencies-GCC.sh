#!/bin/bash

# Dependencies
sudo apt update
sudo apt install -y gcov lcov automake build-essential cmake g++ docker.io
sudo apt install -y libboost-filesystem-dev libboost-system-dev libboost-regex-dev libboost-test-dev

sudo systemctl enable docker
sudo systemctl start docker