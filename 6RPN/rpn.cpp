/*
 Joseph Hilland
 ECE 231
 Spring 2012
 */

#include "complex.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	string input = "";
	stack<Complex> CompStack;
	cout << "Welcome to the RPN complex calculator. Please enter Cartesian numbers " << endl;
	cout << "in the form of REAL,IMAG. Please enter Polar numbers in the form MAG<PHASE. " << endl;
	cout << "Operations are +, -, *, /, p (for power), r (for root), and s (for size). Size returns the size of the stack." << endl;
	cout << "Type q to quit." << endl;
	while (input.compare("q") != 0)
	{
		cin >> input; //Take an input
		
		
		// Cartesian Input
		
		string comma (",");
		size_t found;
		
		found=input.find(comma);
		if (found!=string::npos)
		{
			
			char * CInput;
			
			CInput = new char [input.size()+1];
			strcpy (CInput, input.c_str());
			
			
			Complex CartInput;
			int CommaIndex = int(found);
			double real = atof(CInput);
			CartInput.setReal(real);
			double imaginary = atof(&CInput[CommaIndex+1]);
			CartInput.setImag(imaginary);
			CompStack.push(CartInput);
		}
		
		else 
		{
			
			//Polar Input
			
			string angle ("<");
			size_t found1;
			
			found1=input.find(angle);
			if (found1!=string::npos)
			{
				
				char * CInput;
				
				CInput = new char [input.size()+1];
				strcpy (CInput, input.c_str());
				
				
				Complex PolarInput;
				int AngleIndex = int(found1);
				double Mag = atof(CInput);
				double Phase = M_PI/180*atof(&CInput[AngleIndex+1]);
				PolarInput.setReal(Mag*cos(Phase));
				PolarInput.setImag(Mag*sin(Phase));
				CompStack.push(PolarInput);
			}
			
			else
			{
				char inputchar = input[0];
				//Operators
				switch (inputchar)
				{
					case 's':
						cout << CompStack.size()<< endl;
						break;
					case '+':
						if (CompStack.size() >= 2) 
						{
							Complex Complex2 = CompStack.top();
							CompStack.pop();
							Complex Complex1 = CompStack.top();
							CompStack.pop();
							Complex Complex3 = Complex1 + Complex2;
							CompStack.push(Complex3);
							cout << Complex1 << " + " << Complex2 << endl;
							cout << Complex3 << endl; 
						}
						else 
						{
							cout << "Please enter more numbers first." << endl;
						}
						break;
					case '-':
						if (CompStack.size() >= 2) 
						{
							Complex Complex2 = CompStack.top();
							CompStack.pop();
							Complex Complex1 = CompStack.top();
							CompStack.pop();
							Complex Complex3 = Complex1 - Complex2;
							CompStack.push(Complex3);
							cout << Complex1 << " - " << Complex2 << endl;
							cout << Complex3 << endl; 
						}
						else 
						{
							cout << "Please enter more numbers first." << endl;
						}
						break;
					case '*':
						if (CompStack.size() >= 2) 
						{
							Complex Complex2 = CompStack.top();
							CompStack.pop();
							Complex Complex1 = CompStack.top();
							CompStack.pop();
							Complex Complex3 = Complex1 * Complex2;
							CompStack.push(Complex3);
							cout << Complex1 << " * " << Complex2 << endl;
							cout << Complex3 << endl; 
						}
						else 
						{
							cout << "Please enter more numbers first." << endl;
						}
						break;
					case '/':
						if (CompStack.size() >= 2) 
						{
							Complex Complex2 = CompStack.top();
							CompStack.pop();
							Complex Complex1 = CompStack.top();
							CompStack.pop();
							Complex Complex3 = Complex1 / Complex2;
							CompStack.push(Complex3);
							cout << Complex1 << " / " << Complex2 << endl;
							cout << Complex3 << endl; 
						}
						else 
						{
							cout << "Please enter more numbers first." << endl;
						}
						break;
						
					case 'p':
						if (CompStack.size() >= 2) 
						{
							Complex Complex2 = CompStack.top();
							CompStack.pop();
							Complex Complex1 = CompStack.top();
							CompStack.pop();
							int power = ceil(Complex2.getReal());
							Complex Complex3 = Complex1.power(power);
							CompStack.push(Complex3);
							cout << Complex1 << " ^ " << power << endl;
							cout << Complex3 << endl; 
						}
						else 
						{
							cout << "Please enter more numbers first." << endl;
						}
						break;
					case 'r':
						if (CompStack.size() >= 2) 
						{
							Complex Complex2 = CompStack.top();
							CompStack.pop();
							Complex Complex1 = CompStack.top();
							CompStack.pop();
							int root = ceil(Complex2.getReal());
							Complex Complex3 = Complex1.root(root);
							CompStack.push(Complex3);
							cout << Complex1 << " ^ 1/" << root << endl;
							cout << Complex3 << endl; 
						}
						else 
						{
							cout << "Please enter more numbers first." << endl;
						}
						break;
					case 'q':
						break;
					default:
						cout << "Please enter another complex number or an operation." << endl;
						break;
				} // End Switch
			}
				
		}
		 
	}
	return 0;
}
