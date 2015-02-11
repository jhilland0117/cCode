//Joseph Hilland
//ECE 231
//Includes all functions for assign2.c
//

#include "complex.h"

double print_real(complex n, int form)
{
    if (form == 0)
        return (n.real);
    if (form == 1);
    {
        complex temp = poltocart(n);
        return(temp.real);
    }
}

double print_imag(complex n, int form)
{
    if(form == 0)
        return(n.imaginary);
    if(form == 1)
        return((n.real * sin(n.imaginary)));
}

double print_magnitude(complex n, int form)
{
    if(form == 0)
    {
        float x = n.real;
        float y = n.imaginary;
        return(sqrt((x * x + y * y)));
    }
    if(form == 1)
        return(n.real);
}

double print_phase(complex n, int form)
{
    if(form == 0)
    {
        float x = n.real;
        float y = n.imaginary;
        return(atan2(y,x));
    }
    if(form == 1)
    {
        return(n.imaginary);
    }
}

complex add(complex n, complex m, int form)
{
    complex temp, temp2, temp3;
    if(form == 0)
    {
        temp.real = n.real + m.real;
        temp.imaginary = n.imaginary + m.imaginary;
        return(temp);
    }
    if(form == 1)
    {
        temp3.real = (n.real*cos(n.imaginary) + m.real*cos(m.imaginary));
        temp3.imaginary = (n.real*sin(n.imaginary) + m.real*sin(m.imaginary));
        temp2.real = print_magnitude(temp3, 0);
        temp2.imaginary = print_phase(temp3, 0);
        return(temp2);
    }
}

complex subtract(complex n, complex m, int form)
{
    complex temp, temp2;
    if(form == 0)
    {
        temp.real = n.real - m.real;
        temp.imaginary = n.imaginary - m.imaginary;
        return(temp);
    }
    if(form == 1)
    {
        temp.real = (n.real*cos(n.imaginary) - m.real*cos(m.imaginary));
        temp.imaginary = (n.real*sin(n.imaginary) - m.real*sin(m.imaginary));
        temp2.real = print_magnitude(temp, 0);
        temp2.imaginary = print_phase(temp, 0);
        return(temp2);
    }
}

complex multiply(complex n, complex m, int form)
{
    complex temp;
    if(form == 0)
    {
        float r1 = print_magnitude(n, 0);
        float r2 = print_magnitude(m, 0);
        float ang1 = print_phase(n, 0);
        float ang2 = print_phase(m, 0);
        float r3 = r1 * r2;
        if(r3 == 0)
        {
            temp.real = 0.0;
            temp.imaginary = 0.0;
            return(temp);
        }
        else
        {
            float ang3 = ang1 + ang2;
            temp.real = r3*cos(ang3);
            temp.imaginary = r3*sin(ang3);
            return(temp);
        }
    }
    if(form == 1)
    {
        if(n.real == 0 || m.real == 0)
        {
            temp.real = 0.0;
            temp.real = 0.0;
            return(temp);
        }
        else
        {
            temp.real = n.real * m.real;
            temp.imaginary = n.imaginary + m.imaginary;
            return(temp);
        }
    }
}

complex divide(complex n, complex m, int form)
{
    complex temp;
    if(form == 0)
    {
        if(print_magnitude(m, form) != 0)
        {
            float r1 = print_magnitude(n, 0);
            float r2 = print_magnitude(m, 0);
            float ang1 = print_phase(n, 0);
            float ang2 = print_phase(m, 0);
            float r3 = r1 / r2;
            float ang3 = ang1 - ang2;
            temp.real = r3*cos(ang3);
            temp.imaginary = r3*sin(ang3);
            return(temp);
        }
    }
    else
    {
        printf("Sorry, you cant divide by zero, instead, both parts will be show as -1.337.\n");
        temp.real = -1.337;
        temp.imaginary = -1.337;
        return(temp);
    }
    if(form == 1)
    {
        if(m.real != 0)
        {
            temp.real = n.real / m.real;
            temp.imaginary = n.imaginary - m.imaginary;
            return(temp);
        }
    }
    else
    {
        printf("Sorry, but you cant divide by zero, instead, both parts will be shown as -1.337.\n");
        temp.real = -1.337;
        temp.imaginary = -1.337;
        return(temp);
    }
}

complex print_power(int npower, complex n, int form)
{
    complex temp;
    if(form == 0)
    {
        float r1 = print_magnitude(n, 0);
        float ang1 = print_phase(n, 0);
        float r2 = pow(r1, npower);
        float ang2 = npower *ang1;
        temp.real = r2*cos(ang2);
        temp.imaginary = r2*sin(ang2);
        return(temp);
    }
    if(form == 1)
    {
        temp.real = pow(n.real, npower);
        temp.imaginary = npower * n.imaginary;
        return(temp);
    }
}

complex print_root(int mroot, complex n, int form)
{
    complex temp;
    if(form == 0)
    {
        float r1 = print_magnitude(n, 0);
        float ang1 = print_phase(n, 0);
        float r2 = pow(r1, 1.0/mroot);
        float ang2 = ang1 / mroot;
        temp.real = r2*cos(ang2);
        temp.imaginary = r2*sin(ang2);
        return(temp);
    }
}

complex print_conj(complex n)
{
    float iman = n.imaginary * -1;
    complex temp = {n.real, iman };
    return(temp);
}

complex poltocart(complex n)
{
    float rtemp = n.real;
    float ptemp = n.imaginary;
    float realtemp = rtemp * cos(ptemp);
    float imantemp = rtemp * sin(ptemp);
    complex temp = {realtemp, imantemp};
    return(temp);
}

complex carttopol(complex n)
{
    complex temp;
    temp.real = print_magnitude(n, 0);
    temp.imaginary = print_phase(n,0);
    return(temp);
}


