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
/// reverse a Linked List in k-Groups
ListNode *reverse(ListNode *head, int k)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }
  ListNode *curr = head;
  int count = 0;
  // is nodes < k?
  while (count < k && curr != nullptr)
  {
    curr = curr->next;
    count++;
  }
  if (count < k)
    return head;
  count = 0;
  curr = head;
  ListNode *prev = nullptr;
  ListNode *next = nullptr;
  count = 0;

  while (curr != nullptr && count < k)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    count++;
  }
  //* step2 recursion ko dedo
  if (next != nullptr)
  {
    head->next = reverse(next, k);
  }
  //* return head of reversed ll
  return prev;
  //*Processing
  // //*check karlo bhai k nodes hai ya nahi
  // bool isK = true;
  // Node *temp = head;
  // for (int i = 1; i < k; i++)
  // {
  //   temp = temp->next;
  //   if (temp == nullptr)
  //   {
  //     isK = false;
  //     delete temp;
  //     break;
  //   }
  // }
  // if (isK)
  // //*Agar number of nodes is >= k
  // {
  // }
  // else
  // {
  //   //* agar number of nodes < k
  //   return head;
  // }
}

int main()
{
  ListNode *head = new ListNode(10);
  insert(head, 20);
  insert(head, 30);
  insert(head, 40);
  insert(head, 50);
  insert(head, 60);
  insert(head, 70);
  print(head);
  ListNode *reversedList = reverse(head, 2);
  cout << "reversed in group of 2:" << endl;
  print(reversedList);
  // print(head);
  return 0;
}