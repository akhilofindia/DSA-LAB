//start:
#include<stdio.h>
#include<stdlib.h>
//declaring a structure
struct node
{
  int data;
  struct node *firstchild;
  struct node *nextsibling;
};
//creating a function for creating the tree
struct node *
create (int data)
{
  struct node *newnode = (struct node *) malloc (sizeof (struct node));
  if (newnode == NULL)
    {
      printf ("Memory Allocation failed!");
    }
  else
    {
      newnode->data = data;
      newnode->firstchild = NULL;
      newnode->nextsibling = NULL;
      return newnode;
    }
}
//creating a function for adding the child in the tree
void
addchild (struct node *parent, struct node *child)
{
  if (parent->firstchild == NULL)
    {
      parent->firstchild = child;
    }
  else
    {
      struct node *sibling = parent->firstchild;
      while (sibling->nextsibling != NULL)
	{
	  sibling = sibling->nextsibling;
	}
      sibling->nextsibling = child;
    }
}
//creating a fucntion for dislaying the tree
void
display (struct node *root)
{
  if (root != NULL)
    {
      printf ("%d->", root->data);
      struct node *child = root->firstchild;
      while (child != NULL)
	{
	  display (child);
	  child = child->nextsibling;
	}
    }
}
//main function
int
main ()
{
  //tree creation with child in it.
  struct node *root = create (1);
  struct node *child1 = create (2);
  struct node *child2 = create (3);
  struct node *child3 = create (4);
  //adding child in it.
  addchild (root, child1);
  addchild (root, child2);
  addchild (child1, child3);
  //printing the tree
  printf ("Tree:");
  display (root);
  printf ("NULL\n");
  return 0;
}
//end.
