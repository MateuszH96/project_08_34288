#!/bin/bash

cmake ..

if [[ $? != 0 ]]; then
    # There was an error, display the error in $output
    echo -e "Error"
    exit 1
fi

make

if [[ $? != 0 ]]; then
    # There was an error, display the error in $output
    echo -e "Error"
else
    # Compilation successfull
    ./UnitTests
fi