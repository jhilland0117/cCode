/*
 Joseph Hilland
 ECE 231
 Spring 2012
*/

//This file contains the class for a complex number
#include <iostream>
using namespace std;

class Complex 
{
public: 
	//Construtors
	Complex ();
	Complex (double r, double i);
	Complex (istream & inR, istream & inI); //Not Used
	
	double getReal() const;
	double getImag() const;
	void get(ostream & out) const;
	void setReal(double);
	void setImag(double);
	double magnitude() const;
	double angle() const;
	
	Complex conjugate() const;
	Complex power(int n) const;
	Complex root(int n) const;
	
	//Overloaded operators
	Complex operator = (const Complex &);
	Complex operator + (const Complex &);
	Complex operator - (const Complex &);
	Complex operator * (const Complex &);
	Complex operator / (const Complex &);
	
	friend ostream & operator << (ostream & out, const Complex & c);
	friend istream & operator >> (istream & in, Complex & c); //Not Used
	 
private:
	//Data members
	double re,
		   im;
}; 
