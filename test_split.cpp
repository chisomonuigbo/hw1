/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/


#include <iostream>
#include "split.h"
using namespace std;
#include "split.h"

int main(int argc, char* argv[])
{
  Node* last = new Node{63, nullptr};
  Node* second = new Node{14, last};
  Node* third = new Node{3, second};
  Node* head = third;  

  Node* odds = nullptr;
  Node* evens = nullptr;
  split(head, odds, evens);

  Node* temp = odds;
  while (temp != nullptr) {
    cout << temp->value << ", ";
    temp = temp->next;
  }

  temp = evens;
  while (temp != nullptr) {
    cout << temp->value << ", ";
    temp = temp->next;
  }


  while (odds != nullptr) {
    temp = odds;
    odds = odds->next;
    delete odds;
    odds = NULL;
  }

  while (head != nullptr) {
    temp = evens;
    evens = evens->next;
    delete temp;
    evens = nullptr;
  }

  delete temp;
  temp = nullptr;
  
  return 0;
}
