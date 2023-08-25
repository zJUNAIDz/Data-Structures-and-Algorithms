#include <iostream>
using namespace std;

// href : Visual representation: https://media.geeksforgeeks.org/wp-content/uploads/20220817185024/CircularSinglyLinkedList-660x172.png
//* Implementing Circular Linked list class
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
  ~Node()
  {
    if (next != nullptr)
    {
      delete next; // deleting pointer and not the velue in it
      next = nullptr;
    }
  }
};

//*To print CLL3
void print(Node *&tail)
{
  // cout << "hello ji" << endl;
  //*My Approach
  // //*If CLL has only one Node(i.e. tail)
  // if (tail->next == tail)
  // {
  //   cout << tail->data << endl;
  //   return;
  // }
  // //*if CLL has more than one Node
  // Node *head = tail->next;
  // while (head != tail)
  // {
  //   cout << head->data << ' ';
  //   head = head->next;
  // }
  // cout << tail->data;
  // cout << endl;
  //* Better Approach
  Node *temp = tail;
  do
  {
    cout << temp->data << ' ';
    temp = temp->next;
  } while (temp != tail);
  cout << endl;
}

//! creating functions to Insert at head or tail is not necessary ..insert at position is enough
//* To insert a Node at tail
void insertAtTail(Node *&tail, int data)
{
  // Node *head = tail->next;
  Node *newNode = new Node(data);
  // tail->next = newNode;
  // tail = newNode;
  // tail->next = head;
  newNode->next = tail->next;
  tail->next = newNode;
  tail = newNode;
}
//* To insert a Node at head
void insertAtHead(Node *&tail, int data)
{
  Node *head = tail->next;
  Node *newNode = new Node(data);
  // tail->next = newNode;
  // tail = newNode;
  // tail->next = head;
  newNode->next = head->next;
  head->next = newNode;
}
//*To insert at any postion
void insertAtPosition(Node *&tail, int pos, int data)
{ //*tracking head for traversal
  Node *head = tail->next;
  //*New Node to be inserted
  Node *newNode = new Node(data);
  //*If position is at head
  if (pos == 1)
  {
    // newNode->next = head->next;
    // head = newNode;
    // tail->next = head;
    // return;
    insertAtHead(tail, data);
  }
  //*keeping track of current node while not losing head for further use
  Node *currNode = head;
  //* Traversing until we reach node before position
  for (int i = 1; i < pos - 1; i++)
  {
    currNode = currNode->next;
  }

  //*If position is at tail
  if (currNode->next == tail)
  {
    // currNode->next = newNode;
    // newNode->next = tail;
    insertAtTail(tail, data);
  }
  //* if position is somewhere in the middle
  newNode->next = currNode->next;
  currNode->next = newNode;
}

//*Delete a Node at any position
void deleteNode(Node *&tail, int pos)
{
  //*IF empty LL
  if (tail == nullptr)
  {
    cout << "The List is Empty" << endl;
    return;
  }
  //*If CLL contains only 1 Node
  if (tail->next == tail)
  {
    cout << "1" << endl;
    delete tail;
    return;
  }
  //*If pos is at head
  if (pos == 1)
  {
    cout << "2" << endl;

    Node *temp = tail->next->next;
    delete tail->next;
    tail->next = temp;
    return;
  }
  //*Traversing to previous Node of position(pos-1)
  Node *prev = tail;
  Node *curr = tail->next;

  for (int i = 1; i < pos; i++)
  {
    curr = curr->next;
    prev = prev->next;
  }
  //*If pos is at tail
  if (curr == tail)
  {
    cout << "3" << endl;

    prev->next = tail->next;
    delete tail;
    tail = prev;
    return;
  }
  //*If position is somewhere in the middle
  prev->next = curr->next;
  curr->next = nullptr; //? why does it not work if I remove this line?
  delete curr;
}

int main()
{
  Node *node = new Node(10);
  node->next = node;
  //*This time we will keep track of tail
  //* as we can keep track of head(tail+1) also
  Node *tail = node;

  // print(tail);
  // cout << "tail: " << tail->data << endl;
  insertAtTail(tail, 11);
  // print(tail);
  // cout << "tail: " << tail->data << endl;
  // insertAtTail(tail, 12);
  // print(tail);
  // cout << "tail: " << tail->data << endl;
  // insertAtTail(tail, 13);
  // print(tail);
  // cout << "tail: " << tail->data << endl;
  // insertAtHead(tail, 19);
  // print(tail);
  // cout << "head: " << tail->next->data << endl;
  // cout << "tail: " << tail->data << endl;
  // insertAtPosition(tail, 3, 18);
  // print(tail);

  // insertAtPosition(tail, 1, 18);
  // print(tail);

  // insertAtPosition(tail, 6, 20);
  cout << "---" << endl;
  print(tail);
  cout << "---" << endl;
  // cout << "head: " << tail->next->data << endl;
  // cout << "tail: " << tail->data << endl;
  deleteNode(tail, 1);
  print(tail);
  // cout << "head: " << tail->next->data << endl;
  // cout << "tail: " << tail->data << endl;

  return 0;
}