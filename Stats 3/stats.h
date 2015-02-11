/*  ECE231 

Cited Code:
Vectors - http://www.cplusplus.com/reference/stl/vector/vector/
Vectors - http://www.daniweb.com/forums/thread120258.html
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include<cmath>

using namespace std;

class STATS
{
public:
    int InputData(char *argv[]);
    int ProcessDataOutput();
    void bubbleSort();
    double minPart();
    double maxPart();
    double meanPart();
    double variance();
    double stdDeviation();
    void histogram();
private:
    int arraysize, numbin;
    double *array, *bin, minimum, maximum, average, var, stddev;
    ifstream inFile;
    ofstream outFile1;
    ofstream outFile2;
    ofstream outfile3;
};  // end of class STATS

