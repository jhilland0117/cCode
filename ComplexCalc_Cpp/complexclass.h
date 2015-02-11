//header file for assignment 3 part b
//complexclass.h
//Joseph Hilland
//ECE 231
//Spring 12


#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <cassert>
#include <istream>
#include <cstdio>
typedef struct partb{
    double real, imaginary;
} complex;

class assignment3
{
private:
struct partb;
double real, imaginary;
public:
typedef enum {cartesian, polar} format;

//Function Prototypes
void initializer(double, double);
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
};
#endif
