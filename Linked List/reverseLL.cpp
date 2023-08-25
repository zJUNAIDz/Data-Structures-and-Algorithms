#include <iostream>
using namespace std;
// Implementing LL
class Node
{
public:
  int data;
  Node *next;
  Node(int data)
  {
    this->data = data;
    this->next = nullptr;
  }
};
void print(Node *&head)
{
  Node *temp = head;
  while (temp != nullptr)
  {
    cout << temp->data << ' ';
    temp = temp->next;
  }
  cout << endl;
}
void insert(Node *&head, int data)
{
  Node *temp = head;
  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  temp->next = new Node(data);
}
//* Iteratively reversing a Linked List
void reverse(Node *&head)
{
  //*If it has only one node
  if (head->next == nullptr)
  {
    return;
  }
  //*Otherwise
  //* keeping track of previous and next of current node
  Node *prev = nullptr;
  Node *curr = head;
  Node *next = curr;
  while (curr != nullptr)
  {
    //* updating forward pointer
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
}
//* recursively reversing a Linked List
void reverser(Node *&head, Node *&prev, Node *&curr)
{
  // //* Edge Cases
  // if (curr->next == nullptr || curr == nullptr)
  // {
  //   return;
  // }
  //* keeping track of previous and next of current node

  //* Base Case
  if (curr == nullptr)
  {
    head = prev;
    return;
  }
  //*Processing

  //* Recursive Relation
  reverser(head, curr, curr->next);
  curr->next = prev;
}

Node *reverser2(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }

  Node *chotahead = reverser2(head->next);
  head->next->next = head;
  head->next = nullptr;
  return chotahead;
}
int main()
{
  Node *head = new Node(10);
  print(head);
  insert(head, 20);
  print(head);
  insert(head, 30);
  print(head);
  insert(head, 45);
  print(head);
  Node *prev = nullptr;
  Node *curr = head;
  Node *next = curr->next;
  reverser(head, prev, curr);
  cout << "reversed: ";
  print(head);
  Node *reversedList = reverser2(head);
  cout << "reversed 2 : ";
  print(reversedList);
  return 0;
}