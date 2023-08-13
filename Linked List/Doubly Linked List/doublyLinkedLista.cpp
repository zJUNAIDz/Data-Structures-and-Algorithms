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
//* To insert at tail (P.S. we are not tracking tail so just use head)
void insertAtTail(Node *&head, int data)
{
  Node *newNode = new Node(data);
  Node *tail = head;
  // Traversing to the last node
  while (tail->next != nullptr)
  {
    tail = tail->next;
  }
  tail->next = newNode;
  newNode->prev = tail;
}
int main()
{
  Node *node1 = new Node(10);
  // *Initializing node1 as head
  //! We won't keep track of tail now as it is optional and will make this code larger
  Node *head = node1;
  insertAtHead(head, 50);
  insertAtTail(head, 88);
  print(head);
  cout << getLength(head);
  return 0;
}