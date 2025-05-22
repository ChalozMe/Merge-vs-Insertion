#!/bin/bash

N=$1
if [ -z "$N" ]; then
  echo "Usage: ./benchmarkWorst.sh <num_iterations>"
  exit 1
fi

./generateWorst $N | ./timeToSort insertionSort > insertion_worst.dat
./generateWorst $N | ./timeToSort mergeSort     > merge_worst.dat

gnuplot -persist <<EOF
set title "Worst Case: Insertion Sort vs Merge Sort"
plot "insertion_worst.dat" w lines title "Insertion Sort" lc 0, \
     "merge_worst.dat" w lines title "Merge Sort" lc 2
EOF

