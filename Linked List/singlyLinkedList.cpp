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
  //! Implementing destructor is unnecessary but it is just for sake of understanding
  ~Node()
  {
    //* TO print destructed(deleted) Value
    int value = this->data;
  }
};

// Methods
// *To Insert at head (start)
void insertAtHead(Node *&head, int data)
{
  Node *temp = new Node(data);
  temp->next = head;
  head = temp;
}

//  * To Insert at tail using head (dummy approach)
void insertAtTail(Node *&tail, int data)
{
  Node *element = new Node(data);
  tail->next = element;
  // tail=element;
  tail = tail->next;
}
//  *To insert at particular Index
//  * Dummy Approach
// void insertAtIndex(Node *&node, int index, int data)
// {
//   Node *element = new Node(data);
//   Node *currElem = node;
//   for (int i = 1; i < index; i++)
//     currElem = currElem->next;
//   Node *nextElem = currElem->next;

//   currElem->next = element;
//   element->next = nextElem;
// }
//  *improved version of insertAtIndex
void insertAtIndex(Node *&head, Node *&tail, int index, int data)
{
  // if we have to insert at index 0 ?

  if (index == 0)
  {
    insertAtHead(head, data);
    return; // as we dont want to execute further code
  }

  Node *element = new Node(data);
  Node *currElem = head;
  for (int i = 1; i < index - 1; i++)
    currElem = currElem->next;
  //  *Update Tail in case we are inserting at last index
  //  *Better Approach
  if (currElem->next == nullptr)
  {
    insertAtTail(tail, data);
    return;
  }
  element->next = currElem->next;
  currElem->next = element;

  //  *Update Tail in case we are inserting at last index
  //  *Dummy Approach
  // if (element->next == nullptr)
  // {
  //   tail = element;
  // }
}

//*To Delete a Node at any Index
//! It's not necessary to keep track of tail...
//! We are doing it just for eaze of access to last node in a list and nothing else
void deleteNode(Node *&head, Node *&tail, int index)
{
  // Saving head in a temp variable
  Node *currElem = head;
  //*If to be deleted Element is a head
  if (index == 0)
  {
    // delete head; //? Why is it causing infinite calls?
    head = currElem->next;
    return;
  }
  //*Traversing to each element in a linked list
  for (int i = 0; i < index - 1; i++)
  {
    currElem = currElem->next;
  }
  //*If to be deleted element is a tail
  if (currElem->next == tail)
  {
    tail = currElem;
    delete currElem->next;
    tail->next = nullptr;
    return;
  }

  //*Storing the new next in temporary variable
  Node *newNext = currElem->next->next;
  delete currElem->next;
  currElem->next = newNext;
}

//  *To Print Linked List
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
  /*
   *after modification,we better not use node1
   */
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
  insertAtIndex(head, tail, 1, 5);
  insertAtIndex(head, tail, 0, 100);
  deleteNode(head, tail, 5);
  print(head);
  // printing
  // cout << "data: " << node1->data << endl;
  // cout << "Next: " << node1->next << endl;

  return 0;
}
