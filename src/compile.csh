#!/bin/bash

# Declare an array with the names of the source files
source_files=(
    "dfswithsinglepathtraversal.cc"
    "mazetraversal.cc"
)

# Iterate over each source file and compile it
for source in "${source_files[@]}"; do
  # Extract the filename without extension for the output file
  output_name="${source%.cc}"
  # Compile the source file
  #g++ -g -fsanitize=address -fno-omit-frame-pointer -O0 -std=c++20 "$source" -o build/"$output_name" -mavx -lblas -fopenmp 
  g++ -g -std=c++20 "$source" -o build/"$output_name" 
  # Check if the compilation was successful
  if [[ $? -eq 0 ]]; then
    echo "Compiled $source successfully!"
  else
    echo "Error compiling $source!"

  fi
done

echo "All files compiled successfully!"