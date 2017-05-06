
#include "complex.h"/* Definition of complex variable structure */
#include<math.h> /* Definitions for math library */
#include<stdio.h>

void fft(complex *X, int M)

{
	complex temp1;
	complex W; 
	complex U; 
	int i,j,k; 
	int id; 
	int N = 1 << M; 
	int N2 = N/2;
	int L; 
	int LE; 

	int LE1; 

	float pi = 3.1415926535897;

	j = 0;
	
	//printf("N2: %d\n", N2);
	//printf("N: %d\n", N);
	
	for(i=1; i<(N-1); i++)
	{
		k = N2;

		while(k<=j) 
		{
			j = j - k; 
			k = k/2; 
		}
		
		j = j+k; 
		
		if(i<j) 
		{
			temp1.real = (X[j]).real;
			temp1.imag = (X[j]).imag;
			(X[j]).real = (X[i]).real;
			(X[j]).imag = (X[i]).imag;
			(X[i]).real = temp1.real;
			(X[i]).imag = temp1.imag;
		}

	}
	
	printf("\n\nBit-Reversed x(n): \n \n");
	for(i=0; i<N; i++)
	{
	printf("%4d%15.5f\t%15.5f\n",i,(X[i]).real, (X[i]).imag);
	}
	
	for(L=1; L<=M; L++)
	{
		LE = 1 << L; 
		LE1 = LE/2; 
		U.real = 1.0;
		U.imag = 0.0; 
		W.real = cos(pi/LE1);
		W.imag = - sin(pi/LE1); 
		
		printf("\nNo.Points in Sub-DFT:%d\t No.Butterflies in Sub-DFT:%d\t Wn Real:%f\t Wn Imag:%f",LE,LE1,W.real,W.imag);
		
		for(j=0; j<LE1; j++)
		{
		
			for(i=j; i<N; i += LE)
			{
				id = i + LE1;
				printf("\nI:%d\t ID:%d\t\n",i,id);
				
				temp1.real = (X[id]).real*U.real - (X[id]).imag*U.imag;
				temp1.imag = (X[id]).imag*U.real + (X[id]).real*U.imag;
				
				(X[id]).real = (X[i]).real - temp1.real;
				(X[id]).imag = (X[i]).imag - temp1.imag;
				
				(X[i]).real = (X[i]).real + temp1.real;
				(X[i]).imag = (X[i]).imag + temp1.imag;

				printf("%4d%15.5f\t%15.5f\n",i,(X[i]).real, (X[i]).imag);
				printf("%4d%15.5f\t%15.5f\n",id,(X[id]).real, (X[id]).imag);
			}
								
				temp1.real = U.real*W.real - U.imag*W.imag;
				U.imag = U.real*W.imag + U.imag*W.real;
				U.real = temp1.real;
				if(j<LE1-1)
				{
					printf("\n\nWk Values : ID, Real, Imag\n\n");
					printf("%4d%15.5f\t%15.5f\n",j,U.real, U.imag);
				}
		}
		
		printf("\nStage:%d\n",L);
		for(i=0; i<N; i++)
		{
			printf("%4d%15.5f\t%15.5f\n",i,(X[i]).real, (X[i]).imag);
		}
	}
	
	return;
}