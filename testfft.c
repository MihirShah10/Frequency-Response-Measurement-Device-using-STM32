
/* Compile: gcc testfft.c fft.c test_signal.c -o fft.out -lm */

#include "complex.h"
#include <math.h>
#include<stdio.h>
extern void fft();
extern void test_signal();

void main()
{
	complex X[16]; /* Declare input array */
	int i; /* loop index */
	int M = 4; /* log2(16) */
	float pi = 3.141592653589;
	int N = 16; /* Number of FFT points */
	int S = 0;
	/* Generate discrete Test Signals from ADC Pin using Sampling */
	
	test_signal(X,S,N);
	
	printf("\n\nInput Data x(n): \n \n");
	
	for(i=0; i<N; i++)
	{
		printf("%d\t\t%f\t\t%f\n",i,(X[i]).real, (X[i]).imag);
	}
	
	/* Perform FFT */	
	fft(X,M);
	/* Display results on screen */
	
	printf("\n\nFFT X(k): \n \n");
	for(i=0; i<N; i++)
	{
		if((X[i]).real!=0)
		{
			float Magnitude = sqrt((((X[i]).real)*((X[i]).real)) + (((X[i]).imag)*((X[i]).imag)));
			double value= (((X[i]).imag)/((X[i]).real));
			double Phase = (atan(value)*180.0)/(pi);
			printf("%4d%15.5f\t%15.5f\t\tMagnitude:%15.5f\t\tPhase:%15.5f\n",i,(X[i]).real, (X[i]).imag, Magnitude, Phase);
		}
		else
		{
			float Magnitude = sqrt((((X[i]).real)*((X[i]).real)) + (((X[i]).imag)*((X[i]).imag)));
			double value= (((X[i]).imag)/((X[i]).real));
			printf("%4d%15.5f\t%15.5f\t\tMagnitude:%15.5f\t\tPhase:\t\tInfinity\n",i,(X[i]).real, (X[i]).imag, Magnitude);
		}
	}
}