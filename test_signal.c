
#include "complex.h"/* Definition of complex variable structure */
#include<math.h> /* Definitions for math library */
#include<stdio.h>

float pi = 3.141592653589;
int i;
int A=1;
int freq=5000;

int Fs = 20000;            //% Sampling frequency                    
double T = 0.00005;            // % Sampling period       
//L = N (1500);             % Length of signal
//t = (0:L-1)*T;        % Time vector

void test_signal(complex *X,int sig, int N)
{
	switch(sig)
	{
		case 0:		for(i=0; i<N;i++)
					{			
							/*Sinusoid Signal*/
						(X[i]).real = A*sin(i*2.0*pi*freq*T);
						(X[i]).imag = 0.0;
					}
					break;
	
	
		case 1: 	for(i=0; i<N; i++)
					{	
						/* Square Signal*/
						if(i<N/2)
						{
							(X[i]).real = 1.0;
							(X[i]).imag = 0.0;
						}
						else
						{
							(X[i]).real = 0.0;
							(X[i]).imag = 0.0;
						}
					}
					break;
					
		case 2: 	for(i=0; i<N; i++)
					{	
						/* Triangle Signal*/
						if(i<N/2)
						{
							(X[i]).real = (2*i);
							(X[i]).real = (((X[i]).real)/N);
							(X[i]).imag = 0.0;
						}
						else
						{
							(X[i]).real = (2*(N-i));
							(X[i]).real = (((X[i]).real)/N);							
							(X[i]).imag = 0.0;
						}
					}
					break;	
	}
	return;
}