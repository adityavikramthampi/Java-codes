#include <stdio.h>

int bina(int a)
{
    int d, sum = 0;

    while(a >= 6)
    {
        d = a%6;
        sum += d;
        a /= 6;
    }

    return (sum+a);
}

int main()
{
    int a[50], b[50], i, j, N ,ans=0;
    scanf("%d", &N);

    scanf("%d", &a[0]);
    b[0] = bina(a[0]);
    for(i=1; i < N; i++)
    {
        scanf(",%d", &a[i]);
        b[i] = bina(a[i]);
    }

    for(i=0; i < N-1; i++)
     for(j = i+1; j < N; j++)
     {
         if(b[i] > b[j])
            ++ans;
     }

    printf("%d", ans);
    return 0;
}
