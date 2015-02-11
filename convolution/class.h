/*
 * Joseph Hilland
 * ECE 231
 * Assignment 5
 * class.h
*/



#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

class linear 
{
public:

    int InputData(char *argv[]);
    int OutputData();
    void convolution(double *in1, int in1size, double *in2, int in2size, double out[], int outsize);

    void convolutionflip(double *in1, int in1size, double *in2, int in2size, double out[], int outsize);

private:
    double *insequence, *respsequence, *outsignal;
    double cTemp;
    vector<double> input1, input2;
    int arraylength1, arraylength2, outsize;
};

