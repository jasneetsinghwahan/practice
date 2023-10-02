#!/bin/bash

# Declare an array with the names of the source files
source_files=(
  "dfswithsinglepathtraversal.cc"  
)

# Iterate over each source file and compile it
for source in "${source_files[@]}"; do
  # Extract the filename without extension for the output file
  output_name="${source%.cc}"

  echo "Running $output_name ..."
  ./build/"$output_name"
  echo "-------------------------------------------"

done
echo "Done!"