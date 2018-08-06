#include <stdio.h>

int a[9], b[6], s, hh, mm, ss;

int present(int c) {
  int i;
  for(i=0; i < 9; i++)
    if(a[i] == c)
      return 1;

  return 0;
}

void discard(int c) {
  int i;
  for(i=0; i < 9; i++)
    if(a[i] == c)
    {
      a[i] = -1;
      return;
    }
}

void add(int c) {
  int i;
  for(i=0; i < 9; i++)

    if(a[i] == -1) {
      a[i] = c;
      return;
    }

}

int zeros() {
  int i=0, j=0;

  for(i=0; i<9; i++) {
    if(a[i] == 0)
      ++j;
  }

  if(j>3)
    return 1;
  return 0;
}

int max1() {
  int i, max = -1;

  for(i=0; i<9; i++) {
    if((a[i] > max) && (a[i] < 6))
      max = a[i];
  }

  return max;
}

int max2() {
  int i, max = -1;

  for(i=0; i<9; i++) {
    if(a[i] > max)
      max = a[i];
  }

  return max;
}

int main() {
  int i, j, ans=0, max;

  scanf("%d", &a[0]);
  for(i=1; i < 9; i++)
      scanf(",%d", &a[i]);

  if(present(2)) {
// hours
    discard(2);
    if(present(4) && zeros()) {
      b[0] = 2;
      discard(4);
      b[1] = 4;
      discard(0);
      b[2] = 0;
      discard(0);
      b[3] = 0;
      discard(0);
      b[4] = 0;
      discard(0);
      b[5] = 0;
    }

    else if(present(3)) {
      b[0] = 2;
      discard(3);
      b[1] = 3;
    }

    else if(present(2)) {
      b[0] = 2;
      discard(2);
      b[1] = 2;
    }

    else if(present(1)) {
      b[0] = 2;
      discard(1);
      b[1] = 1;
    }

    else if(present(0)) {
      b[0] = 2;
      discard(0);
      b[1] = 0;
    }

    else {
      printf("Impossible");
      return 0;
    }
// minutes
    b[2] = max1();
    discard(b[2]);

    b[3] = max2();
    discard(b[3]);

// seconds
    b[4] = max1();
    discard(b[4]);

    b[5] = max2();
    discard(b[5]);
  }

  else if(present(1)) {
// hours
    b[0] = 1;
    discard(1);

    b[1] = max2();
    discard(b[1]);

// minutes
    b[2] = max1();
    discard(b[2]);

    b[3] = max2();
    discard(b[3]);

// seconds
    b[4] = max1();
    discard(b[4]);

    b[5] = max2();
    discard(b[5]);
  }

  else if(present(0)) {
    b[0] = 0;
    discard(0);

    b[1] = max2();
    discard(b[1]);

// minutes
    b[2] = max1();
    discard(b[2]);

    b[3] = max2();
    discard(b[3]);

// seconds
    b[4] = max1();
    discard(b[4]);

    b[5] = max2();
    discard(b[5]);
  }

  else {
    printf("Impossible");
    return 0;
  }

  printf("%d%d:%d%d:%d%d",b[0],b[1],b[2],b[3],b[4],b[5]);

return 0;
}
