#include <iostream>
using namespace std;
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
  ListNode(ListNode *newNode)
  {
    this->data = newNode->data;
    this->next = newNode->next;
  }
};
void print(ListNode *&head)
{
  ListNode *temp = head;
  do
  {
    cout << temp->data << ' ';
    temp = temp->next;

  } while (temp != nullptr && temp != head);
  cout << endl;
}
//*Insert by data
ListNode *insert(ListNode *&head, int data)
{
  ListNode *temp = head;
  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  return temp->next = new ListNode(data);
}
//* TO Insert a particular Node
ListNode *insert(ListNode *&head, ListNode *newNode)
{
  ListNode *temp = head;
  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  return temp->next = newNode;
}