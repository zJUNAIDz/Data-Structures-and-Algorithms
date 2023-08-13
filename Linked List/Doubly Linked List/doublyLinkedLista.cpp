#include <iostream>
using namespace std;
//*Implementing Node for Doubly Linked List
class Node
{
public:
  int data;
  Node *prev;
  Node *next;
  // Constructor
  Node(int data)
  {
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
  }
};
//* Prints node from given node to last node
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
//* returns length of LL from given node to last node
int getLength(Node *&head)
{
  Node *temp = head;
  int len = 1;
  while (temp->next != nullptr)
  {
    temp = temp->next;
    len++;
  }
  return len;
}
//* To insert a Node at Head
void insertAtHead(Node *&head, int data)
{
  Node *newNode = new Node(data);
  // pointing newNode next to head
  newNode->next = head;
  // pointing head prev to newNode
  head->prev = newNode;
  // shifting head to newNode(previous value)
  head = newNode;
}
//* To insert at tail 
void insertAtTail(Node *&tail, int data)
{
  Node *newNode = new Node(data);
  tail->next = newNode;
  newNode->prev = tail;
  tail = newNode;
}
int main()
{
  Node *node1 = new Node(10);
  // *Initializing node1 as head
  Node *head = node1;
  //* initially, taill will also be pointing on head
  Node *tail = head;
  insertAtHead(head, 50);
  insertAtTail(tail, 88);
  print(head);
  cout << getLength(head);
  return 0;
}