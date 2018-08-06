#include <stdio.h>

int main()
{
    int choice, n=3, i, l, temp;
    char CT[50], PT[50];

    printf("Enter 1. Additive 2. Caesar ");

    scanf("%d",&choice);

    if(choice == 1)
    {
        printf("Enter the value of n ");
        scanf("%d",&n);
    }

    printf("Enter length of PT and PT ");
    scanf("%d\n",&l);

    printf("PT: ");
    for(i = 0; i < l; i++)
    {
        scanf("%c", &PT[i]);
        temp = ((int) PT[i]) - 65;
        CT[i] = ((char) (((temp + n) % 26) + 65));
        printf("%c",PT[i]);
    }

    if(choice == 1)
        printf(", %d",n);

    printf("\nCT: ");
    for(i = 0; i < l; i++)
    {
        printf("%c",CT[i]);
        temp = ((int) CT[i]) - 65;
        PT[i] = ((char) (((temp - n) % 26) + 65));
    }

    printf("\nPT: ");
    for(i = 0; i < l; i++)
        printf("%c",PT[i]);

    return 0;
}
