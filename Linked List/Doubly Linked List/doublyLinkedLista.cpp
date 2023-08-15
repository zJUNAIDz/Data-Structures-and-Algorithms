#include <iostream>
#include <vector>
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

// #FUNCTION DECLARATIONS#

//* Prints node from given node to last node
void print(Node *&head, Node *&tail);
//* returns length of LL from given node to last node
int getLength(Node *&head);
//* To insert a Node at Head
void insertAtHead(Node *&head, int data);
//* To insert at tail
void insertAtTail(Node *&tail, int data);
//* To insert at any position( 1 indexed )
void insertAtPosition(Node *&head, Node *&tail, int pos, int data);

// #MAIN BODY#

int main()
{
  Node *node1 = new Node(10);
  // *Initializing node1 as head
  Node *head = node1;
  //* initially, taill will also be pointing on head
  Node *tail = head;
  insertAtHead(head, 50);
  insertAtTail(tail, 88);
  insertAtPosition(head, tail, 2, 99);
  insertAtPosition(head, tail, 3, 19);
  // insertAtPosition(head, tail, 6, 19);
  print(head, tail);
  return 0;
}

// #FUNCTION DEFINITIONS#

//* Prints node from given node to last node
void print(Node *&head, Node *&tail)
{
  Node *temp = head;
  while (temp != nullptr)
  {
    cout << temp->data << ' ';
    temp = temp->next;
  }
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
//* To insert at any position( 1 indexed )
void insertAtPosition(Node *&head, Node *&tail, int pos, int data)
{
  //*If position is head
  if (pos == 1)
  {
    insertAtHead(head, data);
    return;
  }
  //* didn't declared at top to save some memory if position is already at head
  Node *currNode = head;
  // cout << "head " << head->data;
  Node *newNode = new Node(data);
  //*Traversing through each node until we reach to node before position
  for (int i = 1; i < pos - 1; i++)
  {
    currNode = currNode->next;
  }
  //*If position is tail
  if (currNode->next == tail)
  {
    insertAtTail(tail, data);
    return;
  }
  //*IF position is next to tail
  if (currNode->next == nullptr)
  {
    currNode->next = newNode;
    newNode->prev = currNode;
    tail = newNode;
  }
  //* To keep track of Node next to currNode
  Node *nextNode = currNode->next;
  currNode->next = newNode;
  newNode->prev = currNode;
  newNode->next = nextNode;
  nextNode->prev = newNode;
}