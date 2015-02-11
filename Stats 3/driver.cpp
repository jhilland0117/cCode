/*
 Basic Statistics of a file and its Histogram.
 */

#include "stats.h"
//#include "stats.cpp"

// ******BEGIN MAIN******
int main(int argc, char *argv[])
{ 
    // Creating object 'A3' as an instance of STATS to be used in main
    STATS A3;
    A3.InputData(argv);
    A3.ProcessDataOutput();
    return(0);
        
} // end of main
