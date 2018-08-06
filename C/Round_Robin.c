#include <stdio.h>
//#include <stdlib.h>

float Avg_waiting_time(int AT[], int RT[], int n, int Q) {

  int tim=0, i=0, j=0, flag=0, *WT;
  float sum=0;
  WT = (int*)malloc(n*sizeof(int));

  for(i=0; i<n; ++i)
    WT[i] = 0;

  while(1) {

      flag = 0;

      for(i=0; i < n; ++i) {

          if(RT[i] <= Q) {
            tim = tim + RT[i];
            RT[i] = 0;

            if((AT[(i+1)%n] <= tim) && (RT[(i+1)%n] > 0)) {

              WT[(i+1)%n] = WT[(i+1)%n] + tim - AT[(i+1)%n];
              AT[i] = tim;
            }
          }

          else {
            tim = tim + Q;
            RT[i] = RT[i] - Q;

            if((AT[(i+1)%n] <= tim) && (RT[(i+1)%n] > 0)) {

              WT[(i+1)%n] = WT[(i+1)%n] + tim - AT[(i+1)%n];
              AT[i] = tim;
            }
          }

          if(RT[i] > 0)
            flag = 1;

      }

      if(flag == 0)
        break;

  }

  for(i=0; i<n; ++i)
    sum += WT[i];

  return (sum/n);
}

int main() {

  int AT[5], RT[5], Q=3, i, n=5;
  float ans;

  printf("Enter AT and RT of 5 processes\n");
  for(i=0; i<n; ++i)
    scanf("%d %d", &AT[i], &RT[i]);

  printf("Input accepted\n");
  ans = Avg_waiting_time(AT, RT, n, Q);
  printf("%.2f\n", ans);

  return 0;
}
