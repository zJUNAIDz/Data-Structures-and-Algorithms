#include <iostream>
using namespace std;
// Implementing LL
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
};
void print(ListNode *&head)
{
  ListNode *temp = head;
  while (temp != nullptr)
  {
    cout << temp->data << ' ';
    temp = temp->next;
  }
  cout << endl;
}
void insert(ListNode *&head, int data)
{
  ListNode *temp = head;
  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  temp->next = new ListNode(data);
}
//* Iteratively reversing a Linked List
void reverse(ListNode *&head)
{
  //*If it has only one node
  if (head->next == nullptr)
  {
    return;
  }
  //*Otherwise
  //* keeping track of previous and next of current node
  ListNode *prev = nullptr;
  ListNode *curr = head;
  ListNode *next = curr;
  while (curr != nullptr)
  {
    //* updating forward pointer
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
}
//* recursively reversing a Linked List
void reverser(ListNode *&head, ListNode *&prev, ListNode *&curr)
{
  // //* Edge Cases
  // if (curr->next == nullptr || curr == nullptr)
  // {
  //   return;
  // }
  //* keeping track of previous and next of current node

  //* Base Case
  if (curr == nullptr)
  {
    head = prev;
    return;
  }
  //*Processing

  //* Recursive Relation
  reverser(head, curr, curr->next);
  curr->next = prev;
}

ListNode *reverser2(ListNode *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }

  ListNode *chotahead = reverser2(head->next);
  head->next->next = head;
  head->next = nullptr;
  return chotahead;
}
int main()
{
  ListNode *head = new ListNode(10);
  print(head);
  insert(head, 20);
  print(head);
  insert(head, 30);
  print(head);
  insert(head, 45);
  print(head);
  ListNode *prev = nullptr;
  ListNode *curr = head;
  ListNode *next = curr->next;
  reverser(head, prev, curr);
  cout << "reversed: ";
  print(head);
  ListNode *reversedList = reverser2(head);
  cout << "reversed 2 : ";
  print(reversedList);
  return 0;
}