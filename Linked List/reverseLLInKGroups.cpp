#include <iostream>
using namespace std;
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
};
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
void insert(Node *&head, int data)
{
  Node *temp = head;
  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  temp->next = new Node(data);
}
/// reverse a Linked List in k-Groups
Node *reverse(Node *head, int k)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }
  Node *curr = head;
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
  Node *prev = nullptr;
  Node *next = nullptr;
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
  Node *head = new Node(10);
  insert(head, 20);
  insert(head, 30);
  insert(head, 40);
  insert(head, 50);
  insert(head, 60);
  insert(head, 70);
  print(head);
  Node *reversedList = reverse(head, 2);
  cout << "reversed in group of 2:" << endl;
  print(reversedList);
  // print(head);
  return 0;
}