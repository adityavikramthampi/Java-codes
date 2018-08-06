#include <stdio.h>

int main() {
  int a[500], N, P, i, j, k;
  long count=0;

  scanf("%d,%d", &N, &P);

  scanf("%d", &a[0]);
  for(i=1; i < N; i++)
    scanf(",%d", &a[i]);

  for(i=0; i < N-2; i++)
    for(j=i+1; j < N-1; j++)
      for(k=j+1; k < N; k++) {
        if((a[i]+a[j]+a[k])%P == 0)
          ++count;
      }

  printf("%ld", &count);
  return 0;

}
