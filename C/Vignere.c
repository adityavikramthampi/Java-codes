#include <stdio.h>

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
    int i, j=-1, plen, klen, num;
    char PT[20], CT[20], Key[5];

    printf("Enter PT: ");
    gets(PT);

    plen = strlen(PT);

    printf("Enter Key: ");
    gets(Key);

    klen = strlen(Key);

    for(i=0; i<plen; ++i) {

        if(pos(PT[i]) == -1) {
            CT[i] = PT[i];
            continue;
        }

        num = pos(PT[i]) + pos(Key[(++j)%klen]);

        if(num >= 26)
            num = num - 26;

        CT[i] = ABC[num];
    }

    printf("CT: ");
    puts(CT);

    j = -1;
    for(i=0; i<plen; ++i) {

        if(pos(CT[i]) == -1) {
            PT[i] = CT[i];
            continue;
        }

        num = pos(CT[i]) - pos(Key[(++j)%klen]);

        if(num < 0)
            num = num + 26;

        PT[i] = ABC[num];
    }

    printf("PT: ");
    puts(PT);

    return 0;
}
