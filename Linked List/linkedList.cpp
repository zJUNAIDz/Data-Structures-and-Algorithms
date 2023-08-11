#include <iostream>
using namespace std;
// Implementing Singly Linked list node
class Node
{
public:
  int data;
  Node *next;
  // Method to add something in data
  Node(int data)
  {
    this->data = data;
    this->next = nullptr;
  }
};

// Methods
// To Insert at head (start)
void insertAtHead(Node *&head, int data)
{
  Node *temp = new Node(data);
  temp->next = head;
  head = temp;
}

/*
 * To Insert at tail using head (dummy approach)
 */
void insertAtTail(Node *&tail, int data)
{
  Node *element = new Node(data);
  tail->next = element;
  // tail=element;
  tail = tail->next;
}


// To Print Linked List
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
int main()
{
  // Instantiating a new Liked list (node)
  // In a Heap Memory
  Node *node1 = new Node(34);

  // Pointer to Head(first element)
  Node *head = node1;
  /*
   * Pointer to tail(in the beginning, tail will also point to first element as a linked list has only one element)
   */
  Node *tail = node1;
  print(head);

  insertAtHead(head, 87);
  print(head);

  insertAtTail(tail, 77);

  print(head);
  // printing
  // cout << "data: " << node1->data << endl;
  // cout << "Next: " << node1->next << endl;

  return 0;
}
