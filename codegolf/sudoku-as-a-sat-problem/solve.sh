#!/bin/sh

python3 sudoku_to_cnf.py
for i in *.cnf; do
	minisat $i $(basename $i .cnf).out
done
