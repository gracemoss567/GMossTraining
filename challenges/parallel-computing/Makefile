
CC := gcc
FLAGS := -fopenmp

laplace_serial: jacobi.c laplace2d.c
	${CC}  -o laplace jacobi.c laplace2d.c -lm

laplace_parallel: jacobi.c laplace2d.c
	${CC} ${FLAGS} -o laplace jacobi.c laplace2d.c -lm

clean:
	rm laplace_serial rm laplace_parallel