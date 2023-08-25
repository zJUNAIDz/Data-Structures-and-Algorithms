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
  Node *next = head->next;
  while (curr != nullptr)
  {
    curr->next = prev;
    prev = curr;
    curr = next;
    // if (next->next)
    next = next->next;

    cout << prev->data << endl;
    cout << curr->data << endl;
    cout << next->data << endl;
    cout << endl;
    cout << endl;
    cout << endl;
  }
  head = prev;
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
  reverse(head);
  print(head);
  return 0;
}