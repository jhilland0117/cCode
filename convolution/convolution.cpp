/*
 * Joseph Hilland
 * ECE 231
 * Assignment 5
 * convolution.cpp
*/


#include "class.h"

int linear::InputData(char *argv[])
{
    //double *insequence, *respsequence, *outsignal;
    //double cTemp;
    //vector<double> input1, input2;
    arraylength1 = 0, arraylength2 = 0;
    ifstream infile1;
    ifstream infile2;
  //  ofstream outfile;

    if (argv[1]) {
        infile1.open(argv[1], ios::in);
        if (!infile1) {
            cout << "\nCant open input file " << argv[1] << endl;
            return 1;
        } else
            cout << endl << "Opened first file successfully " << endl;
            cout << endl;
    }
    else {
        cout << "\nNo First File input" << endl;
        return 1;
    }
    if (argv[2]) {
        infile2.open(argv[2], ios::in);
        if (!infile2) {
            cout << "\nCant open file " << argv[2] << endl;
            return 1;
        } else
        cout << endl << "Opened second file successfully " << endl;
    }
    else {
        cout << "\nNo Second file input" << endl;
        return 1;
    } 

    while (infile1 >> cTemp) {
        input1.push_back(cTemp);
        arraylength1++;
    }
    infile1.close();

    while (infile2 >> cTemp) {
        input2.push_back(cTemp);
        arraylength2++;
    }
    infile2.close();

    outsize = (arraylength1 + arraylength2 - 1);

    infile1.open(argv[1], ios::in);
    insequence = new double[outsize];
    for (int i = 0; i < arraylength1; i++) {
        infile1 >> insequence[i];
    }

    infile2.open(argv[2], ios::in);
    respsequence = new double[arraylength2];

    for (int i = 0; i < arraylength2; i++) {
        infile2 >> respsequence[i];
    }

    outsignal = new double[outsize];

    cout << "\n\nArray Length 1 = " << arraylength1 << "\n\n";
    cout << "\nArray Length 2 = " << arraylength2 << "\n\n";
    cout << "\nOutsize = " << outsize << "\n\n";

    infile1.close();
    infile2.close();

    //delete[] insequence, respsequence, outsignal;
    return 0;
}


int linear::OutputData()
{
    ofstream outfile;
    outfile.open("out.txt");

    linear::convolutionflip(insequence, arraylength1, respsequence, arraylength2, outsignal, outsize);
   
     for (int i = 0; i < outsize; i++) {
        outfile << setiosflags(ios::fixed) << setprecision(5) << outsignal[i];
        outfile << endl;
    }
    outfile.close();

    delete[] insequence, respsequence, outsignal;

}

void linear::convolution(double *in1, int in1size, double *in2, int in2size, double out[], int outsize)
{
    for (int t = 0; t < outsize; t++)
    {
        out[t] = 0;
        for (int k = 0; k <= t; k++)
        {
            if ((t-k) >= in1size)
            {
                in1[t-k] = 0;
            }
            if (t >= in2size)
            {
                in2[t] = 0;
            }
            out[t] = out[t] +in2[k] * in1[t - k];
        }
    }
}

void linear::convolutionflip(double *in1, int in1size, double *in2, int in2size, double out[], int outsize)
{
    double invh[in2size];

    for (int i = 0; i < in2size; i++)
    {
        invh[in2size - 1 - i] = in2[i];
    }

    for (int b = 0; b < outsize; b++)
    {
        out[b] = 0;
        for (int k = 0; k <= b; k++)
        {
            if (k >= in1size)
            {
                in1[k] = 0;
            }
            if (in2size - 1 - b + k < 0)
            {
                invh[in2size - 1 - b + k] = 0;
            }
            out[b] = out[b] + invh[in2size - 1 - b + k] * in1[k];
        }
    }
}
