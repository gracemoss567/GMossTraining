# Parallel Computing Challenges

## Overview

- [Parallel Computing Challenges](#parallel-computing-challenges)
  - [Overview](#overview)
  - [Task 1 - Parallise `for` Loop](#task-1---parallise-for-loop)
  - [Task 2 - Run task 1 on HPC cluster](#task-2---run-task-1-on-hpc-cluster)
  - [Task 3 - Reduction Clause](#task-3---reduction-clause)
  - [Task 4 - Private clause](#task-4---private-clause)
  - [Task 5 - Calculate Pi using "Monte Carlo Algorithm"](#task-5---calculate-pi-using-monte-carlo-algorithm)
  - [Bonus - Laplace equation to calculate the temperature of a square plane](#bonus---laplace-equation-to-calculate-the-temperature-of-a-square-plane)

## Task 1 - Parallise `for` Loop

Goal: To to create an array `[0,1,2………...19]`

1. Compile array.c and execute it. Check the run time of the serial code
2. Add `#pragma<>`
3. Compile the code again
4. Run parallel code and check the improved run time

## Task 2 - Run task 1 on HPC cluster

1. Check the available partitions with `show_cluster`
2. Modify `RunHello.sh`
3. `sbatch RunHello.sh`
4. `cat slurm<>.out` and check the run time

> You can also use [strudel web](https://beta.desktop.cvl.org.au/login) to run the script without sbatch.

## Task 3 - Reduction Clause

Goal: To find the sum of the array elements

1. Compile `reduction.c` and execute it. Check the run time
2. Add `#pragma<>`
3. Compile `reduction.c` again
4. Run parallel code and check the improved run time. Make sure you got the same result as the serial code

> `module load gcc` to use newer version of gcc if you have error with something like `-std=c99`

## Task 4 - Private clause

The goal of this task is to square each value in array and find the sum of them

1. Compile private.c and execute it. Check the run time. `#include` the default library `<math.h>` and link it
2. Add `#pragma<>`
3. Compile `private.c` again
4. Run parallel code and check the improved run time

## Task 5 - Calculate Pi using "Monte Carlo Algorithm"

Goal:  To estimate the value of pi from simulation

- No instructions on this task. Use what you have learnt in previous tasks to run a parallel code!
- You should get a result close to pi(3.1415…….)

Short explanation of Monte Carlo algorithm:

[https://www.youtube.com/watch?v=7ESK5SaP-bc&ab_channel=MarbleScience](https://www.youtube.com/watch?v=7ESK5SaP-bc&ab_channel=MarbleScience)

## Bonus - Laplace equation to calculate the temperature of a square plane

- Modify `laplace2d.c`
- Use Makefile to compile the code
- Make the program as fast as you can

Brief Algorithm of Laplace equation:
