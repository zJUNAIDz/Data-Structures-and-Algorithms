#include <iostream>
using namespace std;
//* Implementation
class ListNode
{
public:
  int data;
  ListNode *next;

  ListNode(int data)
  {
    this->data = data;
    this->next = nullptr;
  }
  void insert(int data)
  {
    ListNode *temp = this;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }
    temp->next = new ListNode(data);
  }
};
//*Printing LL
void print(ListNode *head)
{
  while (head != nullptr)
  {
    cout << head->data << ' ';
    head = head->next;
  }
  cout << endl;
}
//*Insert
void insert(ListNode *&head, int data)
{
  if (head == nullptr)
  {
    head = new ListNode(data);
    return;
  }
  //*Traversing to tail
  ListNode *temp = head;
  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  temp->next = new ListNode(data);
}

//* Middle of a Linked List
ListNode *middle(ListNode *&head)
{

  //*If there exist only one element
  if (head->next == nullptr)
  {
    return head;
  }
  //-----------------------------------------------------------------------
  //*Creating slow and fast pointers
  // Node *slow = head;
  // Node *fast = head->next;

  // while (fast->next != nullptr)
  // {
  //   slow = slow->next;

  //   // fast = fast->next ? fast->next->next : fast->next;
  //   fast = fast->next->next;
  //   // cout << "atka";
  // }
  // return slow;
  //-----------------------------------------------------------------------
  //*Creating slow and fast pointers
  ListNode *slow = head;
  ListNode *fast = head;

  while (fast->next != nullptr && fast != nullptr)
  {
    slow = slow->next;
    fast = fast->next ? fast->next->next : fast->next;
  }
  return slow;
}
int main()
{
  ListNode *head = new ListNode(10);
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