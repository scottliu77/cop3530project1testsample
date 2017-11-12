# COP 3530 Project 1 Test Sample


## Description

This repository contains a sample test suite used to grade COP 3530 Project 1 for the Fall 2017 semester. This purpose of this suite is to allow students to verify that their code is compliant and working to ensure that there are no problems with the actual test suite.

Disclaimer: This sample test suite is in no way as comprehensive as the actual test suite nor is it a direct representation of how the actual tests will be.

## Directions

1. Clone or download the respository.
2. Add your `List.h` and `SSLL.h` files into the `/src` directory.
3. run `make` from the project root directory.

Note: Project 1 will be graded on the UF CISE Linux servers.

## Contributors

* Jennifer Cremer
* Scott Liu
* Konrad Pabjan
* Thomas Palmer
* Gavin Scheele

## Overview

### Interface Test

This test calls all the operations as defined in Part I of the project on a character SSLL.

### Test 1

1. Create a list of integers.
2. Insert the first 10 nonnegative integers into the list.
3. Verify the length is 10.
4. Verify peek front returns 9.
4. Verify peek back returns 0.
