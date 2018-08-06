#include<stdio.h>

void main() { //Array multiplication using 1D arrays;
  int i, j, k, a[9], b[9], c[3][3];

  for(i = 0; i < 9; i++)
	 scanf("%i", &a[i]);

  for(j = 0; j < 9; j++)
	 scanf("%i", &b[j]);

  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++) {

      C[i][j]=0;
	    for(k = 0; k < 3; k++)
		    c[i][j] = c[i][j] + (a[(i*3)+k]*b[j+(3*k)]);
		}

  for(i = 0; i < 3; i++){

	   for(j = 0; j < 3; j++)
		   printf("%i ", c[i][j]);

     printf("\n");
  }

}
