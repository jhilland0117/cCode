/*
 Joseph Hilland
 ECE 231
 Spring 2012
 */

//This file contains all the functions involved with complex Arithmetic

#include "complex.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

Complex::Complex () {re = im = 0.0;}
Complex::Complex (double r, double i) {re = r; im = i;}
Complex::Complex (istream & inR, istream & inI) {inR >> re; inI >> im;} //Not Used

double Complex::getReal() const //returns the real part
{
	return re;
}

double Complex::getImag() const //returns the imaginary part
{
	return im;
}

void Complex::get(ostream & out) const //prints the value to the output stream
{
	out << re << " + " << im << "i";
}

void Complex::setReal(double in) //sets the real part
{
	re = in;
}

void Complex::setImag(double in) //sets the imaginary part
{
	im = in;
}

double Complex::magnitude() const //returns the magnitude
{
	return sqrt(re*re + im*im);
}

double Complex::angle() const //returns the angle in radians
{
	if (re == 0 && im == 0)
	{	
		return 0;
	}
	else
	{
		double n = (atan2((im),(re)));
		if (n < 0) 
		{                          //Makes sure the angle is on the interval [0,2Pi)
			n +=(2.*M_PI);
		}	
		return n;             //Returns angle in radians
	}
}

Complex Complex::conjugate() const //returns the complex conjugate
{
	Complex Conjugate( re , (im == 0. ? 0 : -im) );
	return Conjugate;
}

Complex Complex::power(int n) const //takes the complex number to an integer power
{
	double Mag = pow(magnitude(),n);
	double Angle = (angle()*n);
	Complex Power( Mag*cos(Angle) , Mag*sin(Angle) );
	return Power;
}

Complex Complex::root(int n) const
{
	double mag = magnitude(); //compute the magnitude of the complex number
	double prinarg = angle(); //compute the principle angle
	double Angle[n]; //create an arrary to store all the angles
	Angle[0] = prinarg/n; //store the value of the angle of the complex number raised to the 1/n power as the first angle
	
	//if this angle is not between 0 and 2pi/n, change the value so it is
	while (Angle[0] <0 || Angle[0] >= (2.*M_PI/n)) 
	{ 
		//If the angle is negative, add 2 PI to it until it is positive	
		if (Angle[0] < 0) 
		{ 
			Angle[0] += (2.*M_PI); 
		}
		//If the angle is larger than 2PI/n subtract that value until it is smaller
		if (Angle[0] > (2.*M_PI/n)) 
		{
			Angle[0] -= (2.*M_PI/n);
		}
	}
	//Assign the angles of each root
	for (int i = 1; i<n; i++) 
	{
		Angle[i] = Angle[0] + i*(2.*M_PI/n); //assign all the proper angles for each root
	}

	Complex Root( pow(mag,(1/n))*cos(Angle[0]), pow(mag,(1/n))*sin(Angle[0]) );
	return Root; //only return the first root
		
}

Complex Complex::operator = (const Complex & c) //overload = operator
{
	re = c.re;
	im = c.im;
	return *this;	
}

Complex Complex::operator + (const Complex & c) //overload + operator
{
	Complex Result;
	Result.re = re + c.re;
	Result.im = im + c.im;
	return Result;
}

Complex Complex::operator - (const Complex & c) //overload - operator
{
	Complex Result;
	Result.re = re - c.re;
	Result.im = im - c.im;
	return Result;
}

Complex Complex::operator * (const Complex & c) //overload * operator
{
	Complex Result;
	Result.re = (magnitude()*c.magnitude())*cos(angle()+c.angle());
	Result.im = (magnitude()*c.magnitude())*sin(angle()+c.angle());
	return Result;
}

Complex Complex::operator / (const Complex & c) //overload / operator
{
	Complex Result;
	Result.re = (magnitude()/c.magnitude())*cos(angle()-c.angle());
	Result.im = (magnitude()/c.magnitude())*sin(angle()-c.angle());
	return Result;
}

ostream & operator << (ostream &out, const Complex &c) //overload << operator for output streams
{
	out << c.re << " + " << c.im << "i";
}

istream & operator >> ( istream &in , Complex &c) //overload >> operator for input streams
{
	in >> c.re >> c.im;
	return in;
}
