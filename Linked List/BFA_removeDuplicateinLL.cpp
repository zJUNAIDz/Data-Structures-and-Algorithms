#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int n)
  {
    this->data = n;
    this->next = nullptr;
  }
  Node *push(int n)
  {
    //* If its the last node
    if (!this->next)
    {
      cout << "H" << endl;
      this->next = new Node(n);
    }
    //* Traverse to the last element
    Node *temp = this;
    while (temp->next)
    {
      cout << "A" << endl;
      temp = temp->next;
    }
    cout << "T" << endl;

    temp->next = new Node(n);
    return temp->next;
  }
};

void print(Node *list)
{
  Node *temp = list;
  while (temp->next != nullptr)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  Node *list = new Node(34);
  list->push(44);
  list->push(45);
  list->push(46);
  print(list);
  return 0;
}