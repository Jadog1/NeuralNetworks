﻿# CMakeList.txt : CMake project for FillerProject, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (NeuralNetworks "NeuralNetworks.cpp" "headers/NeuralNetworks.h" "headers/Levenshtein.h" "Levenshtein.cpp")

# TODO: Add tests and install targets if needed.
