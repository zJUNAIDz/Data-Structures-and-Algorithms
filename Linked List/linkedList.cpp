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
/*
 *To insert at particular Index
 * Dummy Approach
 */
void insertAtIndex(Node *&head, int index, int data)
{
  Node *element = new Node(data);
  Node *currElem = head;
  for (int i = 1; i < index; i++)
    currElem = currElem->next;
  Node *nextElem = currElem->next;

  currElem->next = element;
  element->next = nextElem;
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
  Node *node1 = new Node(1);

  // Pointer to Head(first element)
  Node *head = node1;
  /*
   * Pointer to tail(in the beginning, tail will also point to first element as a linked list has only one element)
   */
  Node *tail = node1;
  // print(head);

  insertAtHead(head, 0);
  // print(head);

  insertAtTail(tail, 2);
  insertAtTail(tail, 3);
  insertAtIndex(head, 1, 5);
  print(head);
  // printing
  // cout << "data: " << node1->data << endl;
  // cout << "Next: " << node1->next << endl;

  return 0;
}
