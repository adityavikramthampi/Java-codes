#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

typedef struct lnode {
  int data;
  struct lnode *link;
}node;

void sort(node *head) {
  node *ptr, *p;
  int temp;
  for(p = head; p->link != NULL; p=p->link)
    for(ptr = head; ptr->link != NULL; ptr=ptr->link)

      if(ptr->data > ptr ->link->data) {
        	temp = ptr->data;
          ptr->data = ptr->link->data;
          ptr->link->data = temp;
      }
}

void insert(node *head, int no) {
  node *p, *back, *ptr = head;

  while((ptr->data < no)&&(ptr != NULL)) {
    back = ptr;
    ptr = ptr->link;
  }

  p = (node*)malloc(sizeof(node));
  scanf("\n%d", &p->data);

  if(ptr->data >= no) {
    p->link = ptr;
    back->link = p;
  }

  else {
    ptr->link = p;
    p->link = NULL;
  }

}

void delete(node *head, int no) {
  node *ptr = head, back;

  while((no != ptr->data)&&(ptr != NULL)) {
    back = ptr;
    ptr = ptr->link;
  }

  if(no == ptr->data)
    back->link = ptr->link;
}

void createlist(node* head) {
  node *head, *ptr, *p, *back;
  char choice;
  head = (node*)malloc(sizeof(node));
  ptr = head;

  do {
    scanf("%d", &ptr->data);
    p = (node*)malloc(sizeof(node));
    ptr->link = p;
    back = ptr;
    ptr = p;
    printf("\nContinue: Y/N ");
    choice = getche();

  } while(choice != 'N');
  back->link = NULL;
}

void merge(node* head1, node* head2, node* head3) {
  node *ptr1, *ptr2, *ptr3, *p, *back;
  ptr3 = head3;

  while((ptr1 != NULL)&&(ptr2 != NULL)) {
    p = (node*)malloc(sizeof(node));
    back = ptr3;
    ptr3->link = p;
    ptr3 = p;

    if((ptr1->data) < (ptr2->data)) {
      ptr3->data = ptr1->data;
      ptr1 = ptr1->link;
    }

    else {
      ptr3 = ptr2->data;
      ptr2 = ptr2->link;
    }

  }

  while(ptr1 != NULL) {
    p = (node*)malloc(sizeof(node));
    back = ptr3;
    ptr3->link = p;
    ptr3 = p;
    ptr3->data = ptr1->data;
    ptr1 = ptr1->link;
  }

}

void  main() {
  char choice = 'Y';
  int n=0, sum=0;

  node *head, *ptr, *p, *back;
  clrscr();
  head = (node*)malloc(sizeof(node));
  ptr = head;

  do {
    scanf("%d", &ptr->data);
    p = (node*)malloc(sizeof (node));
    ptr->link = p;
    back = ptr;
    ptr = p;
    printf("\ncontinue?, Y/N");
    choice = getche();
  } while(toupper(choice) != 'N');

  back->link = NULL;

  sort(head);

  ptr = head;

  while(ptr != NULL) {
    ++n;
    printf("\n%d", ptr->data);
    sum += ptr->data;
    ptr = ptr->link;
  }

  printf("\nsum = %d", sum);
  printf("\naverage = %f", (float)sum/n);;
  getche();
}
