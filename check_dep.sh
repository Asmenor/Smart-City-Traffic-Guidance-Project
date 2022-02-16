#!/bin/bash

dpkg -s $1 &> /dev/null

if [ $? -eq 0 ]; then
    echo "Package $1 is already installed!"
else
    echo "Package $1 is NOT installed! Installing..."
    sudo apt-get install $1
fi
