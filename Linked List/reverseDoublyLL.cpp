#include <iostream>
using namespace std;
class ListNode
{
public:
  int data;
  ListNode *prev;
  ListNode *next;

  ListNode(int data)
  {
    this->data = data;
    prev = nullptr;
    next = nullptr;
  }
  ~ListNode()
  {
    prev = nullptr;
    next = nullptr;
    delete prev;
    delete next;
    cout << endl
         << "Memory Freed for " << this->data << endl;
  }
  void insert(int data)
  {
    //* creating new node
    ListNode *newNode = new ListNode(data);
    if (this->next == nullptr)
    {
      this->next = newNode;
      newNode->prev = this;
    }

    //* traversing to last node
    ListNode *temp = this;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
  }
  void print()
  {
    cout << endl;
    ListNode *temp = this;
    while (temp != nullptr)
    {
      cout << temp->data << ' ';
      temp = temp->next;
    }
    cout << endl;
  }
};

int main()
{
  ListNode *list = new ListNode(10);
  list->insert(20);
  list->insert(30);
  list->insert(40);
  list->print();
  return 0;
}