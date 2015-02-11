/*  ECE231 


Cited Code:
Vectors - http://www.cplusplus.com/reference/stl/vector/vector/
Vectors - http://www.daniweb.com/forums/thread120258.html
*/


#include "stats.h"

int STATS::InputData(char *argv[])
{
    double dTemp;
//    vector <double> numberList;

    if (argv[1])  { //  Checks if there is a filename on the command line
        inFile.open(argv[1], ios::in);
        if (!inFile) {
            cout << "Can't open Input file " << argv[1] << endl;
            return 1; // Exits program
        } else
            cout << "\n\n\a\aFile Open Successfull - End of Program!!!!\n\n\a\a" << endl;
    }
    
    for (arraysize = -1; !inFile.eof(); arraysize++)
    {
        inFile >> dTemp;
    }
    
/*    while (inFile >> dTemp)  { // Counts the numbers in the input file
        numberList.push_back(dTemp);
        arraysize++; // Counter to track the total numbers in the input
    }
 */
    
    inFile.close(); // Closes input file
    inFile.open(argv[1], ios::in);  // Reopens input file for reading
    array = new double[arraysize];  // Dynamically allocates and array to hold the numbers
    for (int i = 0;i < arraysize; i++)    {
        inFile >> array[i];
    }
    inFile.close();
    // for debugging purposes
    // cout << "\nI am in InputData; arraysize = " << arraysize << endl;
    
} //end of InputData




int STATS::ProcessDataOutput()
{

    ofstream outFile1;  // Declaring output stream for statistical info
    ofstream outFile2;  // Declaring output stream for sorted list
    
    outFile1.open ("out1.txt");  // opens and names output file
    outFile2.open ("out2.txt");  // opens and names output file
    
    STATS::bubbleSort();  // Sorts input in ascending order
    minimum = STATS::minPart();
    maximum = STATS::maxPart();
    average = STATS::meanPart();
    var = STATS::variance();
    stddev = STATS::stdDeviation();
    
    // Output for out1.txt
    outFile1 << "MIN = " << minimum << endl;
    outFile1 << "MAX = " << maximum << endl;
    outFile1 << "MEAN = " << average << endl;
    outFile1 << "Variance = " << var << endl;
    outFile1 << "Std Deviation = " << stddev << endl;
    
    // Outputs sorted array to out2.txt
    for (int i = 0; i < arraysize; i++)    {
        outFile2 << setiosflags(ios::fixed) << setprecision(5) << array[i] << endl;
    }
   
    STATS::histogram(); // Builds out3.txt

    outFile1.close();
    outFile2.close();
    delete array;
    // for debugging purposes
    // cout << "\nI am in ProcessDataOutput; arraysize = " << arraysize << endl;
   
    return 0;
    
} // end of ProcessDataOutput

 


//  Bubble sorting function. Traverses the arary and moves larger numbers
//  to the end of the array until no swaps are made.  Once no swaps are
//  done, the array is sorted in ascending order.
void STATS::bubbleSort() 
{
    bool swapped = true;
    int j = 0;
    double temp;
    while (swapped) {
        swapped = false;
        j++;
        for (int i = 0; i < arraysize - j; i++) {
            if (array[i] > array[i + 1]) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = true;
            }
        }
    }
} // end of bubbleSort


 

//  The function takes the sorted array and returns the first number
double STATS::minPart()
{
    return array[0];
}

//  The functtion takes the sorted array and returns the last number
double STATS::maxPart()
{
    return array[arraysize-1];
}

//  The function takes the array and its length as input.
//  It takes the sum of of all numbers and then returns the sum
//  divided by the array length.
double STATS::meanPart()
 {
	double sum;
	sum = 0;
	for (int i = 0;i < arraysize;i++)	{
		sum += array[i];
	}
	return (double(sum/arraysize));
 }

//  The funtion takes the array and array length as input.
//  It goes through the array and subtracts the mean from each
//  number and they squares it.  Adds the result to sum.  Returns
//  sum divided by the array lenght minus 1.
double STATS::variance()
{
	double sum = 0, temp;
	for (int i = 0; i < arraysize; i++)
		sum += (pow((array[i] - STATS::meanPart()), 2));

	return (double(sum / (arraysize - 1)));
}

//  Takes the array of number and its length as input.
//  Calls variance() and returns the square root of the variance of
//  the numbers.
double STATS::stdDeviation()
{
	return (double(sqrt(STATS::variance())));
}





// Finds the Histogram of the numbers in the array
void STATS::histogram()
{
    ofstream outFile3;  // Declaring output stream for histogram
    outFile3.open ("out3.txt"); // opens and names output file
    double min, max, binsize, n;
    min=floor(array[0]);
    max=ceil(array[arraysize-1]);
    
//    cout << "\nfloor = " << min;
//    cout << "\nceiling = " << max << "\n";
    
    int numbin = ceil(sqrt(arraysize));   //Calculates number of bins
//    cout << "\nNumber of bins = " << numbin << "\n";
    
    binsize=(abs(max-min)/numbin); //Calculates size of the bins
//    cout << "\nBin size (width) = " << binsize << "\n";
    
    double bin[numbin]; //Creates an array to store the histogram information
    int index=0;
    bin[index] = 0;
    double binedge=min;
//    cout <<"\nBinedge = " << binedge << "\n";
    
    for (int i = 0; i < arraysize; i++)
    { //loop to go through array
        if ( array[i] < (binedge+binsize) )
        { //compare the value in array to the bin edges
            bin[index]+=1;  //increases number in bin if value fits in bin edges
//            cout << "array[" << i << "] = " << array[i] << "\n";
//            cout << "binedge + binsize = " << (binedge + binsize) << "\n";
//            cout << "bin[" << index << "] = " << bin[index] << "\n";
//            cin >> n;
        }
        else  
        {
            binedge+=binsize;   //if value isn't in bin, changes bin edges
//            cout << "binedge = " << binedge << "\n";
            index++;            //shifts to next bin
            bin[index]=0;       //initiate the value in bin to 0
            i--;                //makes up for offset of a value not in bin of loop
        }
    } // end of for loop
    
    // Outputs histogram to out3.txt
    for (int l = 0; l < numbin; l++)    {
       outFile3 << setiosflags(ios::fixed) << setprecision(5) << bin[l] << endl;
    }
    outFile3 << "MIN = " << min << "\n";
    outFile3 << "MAX = " << max << "\n";
    outFile3 << "Number of Bins = " << numbin << "\n";
    outFile3 << "Bin size (width) = " << binsize << "\n";
    outFile3.close();
} // end of histogram















