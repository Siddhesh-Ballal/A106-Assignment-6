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
  push(10);
  push(20);
  push(30);
  printf("\n");
  show();
  pop();
  printf("\n");
  show();
  return 0;
}