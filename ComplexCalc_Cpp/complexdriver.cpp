//driver file for assignment 3 part b
//complexdriver.cpp
//Joseph Hilland
//ECE 231
//Spring 12


#include "complexclass.h"
#include "classfunctions.cpp"

using namespace std;

int main(int argc, char *argv[])
{
    int h;
    int compAmount, mroot, npower, form, i, j;
    double tempRorM, tempIorP, userInp1, userInp2;
    complex secondnumber, atemp, stemp, mtemp, dtemp, ptemp, rtemp, ctemp;

    //read from input and write to output
    //FILE *inputf;
    //FILE *outputf;
    ifstream indata;
    ofstream outdata;

    switch (argc)
    {
        case 2:
            cerr<< endl << "Error: Please provide an input and output filenames.";
            cout << endl << endl;
            return (1);
        case 3:
            break;
        default:
            cerr << endl << "Error: Please provide input and output filenames respectively as command line arguments";
            cout << endl << endl;
            return(1);
    }

//make sure input and output files open

    if (argv[1]) {
        indata.open(argv[1], ios::in);
        if (!indata) {
            cout << "Cant open file " << argv[1] << endl;
            return (1);
        }
    }

    if (argv[2]) {
        outdata.open(argv[2]);
        if (!outdata) {
        cout << "Cant open file " << argv[2] << endl;
        return (1);
        } else
        cout << argv[2] << "Output Created" << endl;
    }
        

    //read first four numbers from input

    indata >> compAmount;
    indata >> form;
    indata >> npower;
    indata >> mroot;

//first # pos integer
//second # 0 or 1 for car or polar
//third # for power
//fourth # for root

    assignment3 myClass;
    complex myCPParray[compAmount];

    for ( i = 0; i < compAmount; i++)
    {
        indata >> tempRorM;
        indata >> tempIorP;
        myCPParray[i].real = tempRorM;
        myCPParray[i].imaginary = tempIorP;
    }
    indata.close();
 

//enter the second complex number in cartesian or polar

//cartesian format

    if (form == 0)
    {
        cout << "\nEnter real part: ";
        cin >> userInp1;
        cout << "\nEnter imaginary part: ";
        cin >> userInp2;
        secondnumber.real = userInp1;
        secondnumber.imaginary = userInp2;
    }

//polar format

    if (form ==1)
    {
        cout << "\nEnter magnitude: ";
        cin >> userInp1;
        cout << "\nEnter phase: ";
        cin >> userInp2;
        secondnumber.real = userInp1;
        secondnumber.imaginary = userInp2;
    }

//writing results to output file
//cartesian format

    if(form == 0)
    {
        outdata << "This will be in cartesian format, the order of results:";
        outdata << "Real part\n";
        outdata << "Imaginary part\n";
        outdata << "Magnitude\n";
        outdata << "Phase\n";
        outdata << "Power\n";
        outdata << "Root\n";
        outdata << "Conjugate\n";
        outdata << "Addition\n";
        outdata << "Subtraction\n";
        outdata << "Multiplication\n";
        outdata << "Division\n" << endl;
    }

//polar format

    if(form ==1)
    {
        outdata << "This will be in polar format, the order of restults are:\n";
        outdata << "Real part\n";
        outdata << "Imaginary part\n";
        outdata << "Magnitude\n";
        outdata << "Phase\n";
        outdata << "Power\n";
        outdata << "Root\n";
        outdata << "Conjugate\n";
        outdata << "Addition\n";
        outdata << "Subtraction\n";
        outdata << "Multiplication\n";
        outdata << "Division\n\n";
    }

//number crunching part

    for ( j = 0; j < compAmount; j++ )
    {
        outdata << myClass.print_real(myCPParray[j], form) << endl;
        outdata << myClass.print_imag(myCPParray[j], form) << endl;
        outdata << myClass.print_magnitude(myCPParray[j], form) << endl;
        outdata << myClass.print_phase(myCPParray[j], form) << endl;

        ptemp = myClass.print_power(npower, myCPParray[j], form);
        rtemp = myClass.print_root(mroot, myCPParray[j], form);
        ctemp = myClass.print_conj(myCPParray[j]);

        outdata << ptemp.real << "\t" << ptemp.imaginary << endl;
        outdata << rtemp.real << "\t" << rtemp.imaginary << endl;
        outdata << ctemp.real << "\t" << ctemp.imaginary << endl;

// Addition, subtraction, mult, division w/ second number entered by user

        atemp = myClass.add(myCPParray[j], secondnumber, form);
        stemp = myClass.subtract(myCPParray[j], secondnumber, form);
        mtemp = myClass.multiply(myCPParray[j], secondnumber, form);
        dtemp = myClass.divide(myCPParray[j], secondnumber, form);

        outdata << atemp.real << "\t" << atemp.imaginary << endl;
        outdata << stemp.real << "\t" << stemp.imaginary << endl;
        outdata << mtemp.real << "\t" << mtemp.imaginary << endl;
        outdata << dtemp.real << "\t" << dtemp.imaginary << endl;

    }
    outdata.close();

}
