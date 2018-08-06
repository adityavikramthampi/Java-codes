#include <stdio.h>
#include <conio.h>

void main() {

  int a[151], i, j;
  clrscr();

  for(i=1; i<151; i++)
      a[i] = 0;

  for(i=2; i<151; i+=2)
      a[i] = 1;

  for(j=3; j<151; j++)
      for(i=j; i<151; i+=j) {
          if(a[i] == 1)
              a[i] = 0;
          else
              a[i] = 1;
      }

  for(i=1; i<151; i++)
      if(a[i] == 0)
          printf("%d ",i);

  getch();
}
