/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

/* Add a prototype for a helper function here if you need */

#include "split.h"

void split(Node*& in, Node*& odds, Node*& evens)
{
  Node *tempNode = NULL;
  if (in == NULL)
  {
    return;
  }
  else if (in->value % 2 == 0) {
    tempNode = in->next;
    in->next = evens;
    evens = in;
  }
  else {
    tempNode = in->next;
    in->next = odds;
    odds = in;
  }
  in = tempNode;

  return split(in, odds, evens);

}

