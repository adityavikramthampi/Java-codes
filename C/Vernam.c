#include <stdio.h>
#include <stdlib.h>

char ABC[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int pos(char a) {
    int i;

    for(i=0; i<26; ++i) {
        if(ABC[i] == a)
            return i;
    }

    return -1;
}

int main()
{
    int i, j=-1, plen, num;
    char PT[20], CT[20], OTP[20];

    printf("Enter PT: ");
    gets(PT);

    plen = strlen(PT);

    for(i=0; i<plen; ++i) {

        if(pos(PT[i]) == -1) {
            CT[i] = PT[i];
            continue;
        }

        OTP[++j] = ABC[rand()%26];

        num = pos(PT[i]) + pos(OTP[(j)%plen]);

        if(num >= 26)
            num = num - 26;

        CT[i] = ABC[num];
    }

    printf("OTP: ");
    puts(OTP);

    printf("CT: ");
    puts(CT);

    j = -1;
    for(i=0; i<plen; ++i) {

        if(pos(CT[i]) == -1) {
            PT[i] = CT[i];
            continue;
        }

        num = pos(CT[i]) - pos(OTP[(++j)%plen]);

        if(num < 0)
            num = num + 26;

        PT[i] = ABC[num];
    }

    printf("PT: ");
    puts(PT);

    return 0;
}
