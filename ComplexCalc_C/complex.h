//file complex.h

#ifndef COMPLEX_H
#define COMPLEX_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef enum {cartesian, polar} format;

typedef struct {
    double real, imaginary;
} complex;

//Function Prototypes
double print_real(complex n, int form);
double print_imag(complex n, int form);
double print_magnitude(complex n, int form);
double print_phase(complex n, int form);

complex add(complex n, complex m, int form);
complex subtract(complex n, complex m, int form);
complex multiply(complex n, complex m, int form);
complex divide(complex n, complex m, int form);
complex print_conj(complex n);
complex print_power(int npower, complex n, int form);
complex print_root(int mroot, complex n, int form);
complex poltocart(complex n);
complex carttopol(complex n);

#endif


