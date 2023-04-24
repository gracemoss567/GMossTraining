#!/bin/bash
#SBATCH --job-name=
#SBATCH --time=0:05:00
#SBATCH --ntasks=
#SBATCH --cpus-per-task=
#SBATCH --partition=

gcc -fopenmp -o hello hello.c
time ./hello


