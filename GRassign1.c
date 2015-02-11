/*
 Joseph Hilland
 ECE 231 
 Spring 2012
 
 
 */


#include <stdio.h>
#include <math.h>


void SPCF(float P, float interest, int n, float farray[]); //function for single payment compound amount formula
void SPPWF(float F, float interest, int n, float parray[]); //function for Single payment present worth formula
void UPSA(float amount, float interest, int n, float farray[]); //function for Uniform payment series A
void UPSB(float F, float interest, int n, float aarray[]); //function for Uniform payment series B
void UPSC(float P, float interest, int n, float aarray[]); //function for the Uniform payment series C

int main(void)
{
 int option; //choosing formula
 int n; //number of years
 int i;
 float F; //Future sum
 float amount; //periodic disbursements
 float apr; //apr
 float P; //Present sum
 float interest; //interest
 float myarray[10]; //array stores values


        //prompt user for the equations 1 through 5 
	printf("\nPress 1 for Single Payment Compound Amount Formula");
        printf("\nPress 2 for Single Payment Present Worth Formula");
        printf("\nPress 3 for Uniform Payment Series A");
        printf("\nPress 4 for Uniform Payment Series B");
        printf("\nPress 5 Uniform Payment Series C");
	
        printf("\nEnter a choice 1 through 5 = ");
        scanf("%d", &option);
        while (option <= 0 && option >= 6) {
                printf("Incorrect response. Program Terminated.\n");
                break;
                }

   switch (option) {
        case 1:
        printf("\nSingle Payment Compound Amount Formula F=P[1+i]^n\n\n");
        printf("\nEnter Present sum (P) = "); // prompt user for P
        scanf("%f", &P); // enter P
	printf("Enter APR (i) = "); // prompt user for % APR
        scanf("%f", &apr); // enter % APR

        printf("Enter number of years (n) = "); // prompt user number of years
        scanf("%d", &n); // enter number of years

        interest = apr/100;

        SPCF(P, interest, n, myarray);

        for ( i = 0; i <= n; i++)
          {
             printf("\n\aF[%d] = $%7.2f", i, myarray[i]);
          }
	break;  
	case 2:

        printf("\n Single Payment Present Worth Formula.");
        printf("\n Enter Future Sum (F) = "); //prompt use for F
        scanf("%f", &F); //enter 

        printf("\n Enter APR (i) = ");
        scanf("%f", &apr);

        printf("\n Enter number of years (n)=");
        scanf("%d", &n);

        interest = apr/100;

        SPPWF(F, interest, n, myarray);
       
        for ( i = 0; i <= n; i++ )
        {
        printf("\n P[%d] = $%7.2f", i, myarray[i]);
         }
        break;
	case 3:
	printf("\nUniform Payment Series A.");
        printf("\nEnter Periodic Disbursement amount (A) = ");
        scanf("%f", &amount);

        printf("\nEnter APR (i) = ");
        scanf("%f", &apr);
	
	printf("\nEnter number of years (n)=");
	scanf("%d", &n); 

        interest = apr/100;
	 
	UPSA(amount, interest, n, myarray);
        for (i > 0; i <= n; i++)
        {
                printf("\n\aP[%d] = $%7.2f", i, myarray[i]);
        }
        break;
 	case 4:
        printf("\nUniform Payment Series B.");
        printf("\nEnter Future Sum (F) = ");
        scanf("%f", &F);

        printf("\nEnter APR (i) = ");
        scanf("%f", &apr);
	
	printf("\nEnter number of years(n)=");
	scanf("%d", &n); 

        interest = apr/100;
        UPSB(F, interest, n, myarray); 
	for (i > 0; i <= n; i++)
        {
                printf("\n\aA[%d] = $%7.2f", i, myarray[i]);
        }
        break;
	case 5:
        printf("\nUniform Payment Series C.");
        printf("\nEnter Present Sum (P) = ");
        scanf("%f", &P);

        printf("\nEnter APR (i) = ");
        scanf("%f", &apr);
	 
	printf("\nEnter number of years (n) = ");
	scanf("%d", &n); 
	
	interest = apr/100;
        UPSC(P, interest, n, myarray); 
	for (i > 0; i <= n; i++)
        {
                printf("\n\aA[%d] = $%7.2f", i, myarray[i]);
        }
	break;
        } 
    printf("\a\a\n");
    return (0);
}


  
/*
function to calculate Single Payment Compound Amount Formula
F=P(1+i)^n or F=P(F/P,i,n)
F = Future Sum
P = Present Sum
i = interest rate (APR)
n = periods of time, in years
*/

void SPCF(float P, float interest, int n, float *farray)
	{
        int i;
	printf("%f, %f, %d \n", P, interest, n ); 
        for ( i = 0; i <= n; i++)
              {
              farray[i] = P * pow ((1 + interest), i); 
    		} 
	} 
void SPPWF(float F, float interest, int n, float *parray)
        {
        int i;
	printf("%f, %f, %d \n", F, interest,  n); 
        for (i = 0; i <= n; i++)
        	{	
		parray[i] = F/(pow((1+interest), i)); 
                //parray[i] = F * pow((1 + interest), (-n));
        	}
        }
void UPSA(float amount, float interest, int n, float *farray)
	{
         int i;
	printf("%f, %f, %d \n", amount, interest,  n);
         for(i > 0; i<=n; i++)
        	{		
                 farray[i] = amount * ((pow((1+interest), i)-1)/interest);
        	}	
	}	
void UPSB(float F, float interest, int n, float *aarray)
	{
	 int i; 
	printf("%f, %f, %d \n", F, interest, n);
	 for (i > 0; i <=n; i++)
		{
		 aarray[i] = F *(interest/((pow((1+interest), i))-1));
		}
	}
void UPSC(float P, float interest, int n, float *aarray)
	{
	 int i; 
	printf("%f, %f, %d \n", P, interest,  n);
	 for (i > 0; i <=n; i++)
		{
		aarray[i] = P*(pow((1 + interest), i))*(interest/(pow(1+interest, i)-1));
		}
	}


