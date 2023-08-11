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

// To Print Linked List
void print(Node *&head)
{
  Node *temp = head;
  while (temp != nullptr)
  {
    cout << temp->data << ' ';
    temp = temp->next;
  }
}
int main()
{
  // Instantiating a new Liked list (node)
  // In a Heap Memory
  Node *node1 = new Node(34);
  insertAtHead(node1, 87);
  print(node1);
  // printing
  cout << "data: " << node1->data << endl;
  cout << "Next: " << node1->next << endl;

  return 0;
}
