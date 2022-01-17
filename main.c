//A106 Siddhesh Ballal
/*
Assignment 6: Implement stack as an abstract data type using linked list and use this ADT for conversion of infix expression to postfix, prefix, and evaluation of postfix and prefix expression.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next; 
};
struct node* top;

int is_empty()
{
  if (top==NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int is_full()
{
  struct node* temp;
  temp = (struct node*) malloc (sizeof(struct node));
  if (temp == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

struct node* push(int input)
{
  if (is_full())
  {
    printf("\nStack is full");
  }
  else
  {
    struct node* temp;
    temp = (struct node*) malloc (sizeof(struct node));
    temp -> data = input;
    temp -> next = top;
    top = temp;
    printf("\n%d is inserted",input);
  }
  return top;
}

void show()
{
  struct node* p;
  p = top;
  while(p != NULL)
  {
    printf("%d\t", p->data);
    p = p->next;
  }
}

void pop()
{
  if (is_empty())
  {
    printf("\nStack is already empty");
  }
  else 
  {
   struct node* p;
   p = top;
   top = top->next;
   free(p);
  }
}

int main() 
{
  int choice, value;
  do
  {
    printf("\n\nChoose: \n1.Push\n2.Pop\n3.Display\n4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
      case(1):
      printf("\nEnter value to be pushed: ");
      scanf("%d", &value);
      push(value);
      break;

      case(2):
      pop();
      break;

      case(3):
      show();
      break;

      case(4):
      printf("\nProgram exited Successfully");

    }
  }
  while(choice != 4);
  // push(10);
  // push(20);
  // push(30);
  // printf("\n");
  // show();
  // pop();
  // printf("\n");
  // show();
  return 0;
}