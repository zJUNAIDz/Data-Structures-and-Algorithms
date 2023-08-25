#include <iostream>
using namespace std;
//* Implementation
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
  void insert(int data)
  {
    Node *temp = this;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }
    temp->next = new Node(data);
  }
};
//*Printing LL
void print(Node *head)
{
  while (head != nullptr)
  {
    cout << head->data << ' ';
    head = head->next;
  }
  cout << endl;
}
//*Insert
void insert(Node *&head, int data)
{
  if (head == nullptr)
  {
    head = new Node(data);
    return;
  }
  //*Traversing to tail
  Node *temp = head;
  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  temp->next = new Node(data);
}

//* Middle of a Linked List
Node *middle(Node *&head)
{

  //*If there exist only one element
  if (head->next == nullptr)
  {
    return head;
  }
  //*Creating slow and fast pointers
  Node *slow = head;
  Node *fast = head;

  while (fast->next != nullptr)
  {
    slow = slow->next;

    // fast = fast->next ? fast->next->next : fast->next;
    fast = fast->next->next;
    // cout << "atka";
  }
  return slow;
}
int main()
{
  Node *head = new Node(10);
  insert(head, 20);
  insert(head, 30);
  insert(head, 40);
  insert(head, 50);
  insert(head, 60);
  head->insert(34);
  print(head);
  cout << "Middle: " << middle(head)->data << endl;
  return 0;
}