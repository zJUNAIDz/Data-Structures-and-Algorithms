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
  Node(Node *newNode)
  {
    this->data = newNode->data;
    this->next = newNode->next;
  }
};
void print(Node *&head)
{
  Node *curr = head;
  while (curr)
  {
    cout << curr->data << ' ';
    curr = curr->next;
  }
  cout << endl;
}
//*Insert by data
Node *insert(Node *&head, int data)
{
  Node *temp = head;
  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  return temp->next = new Node(data);
}
//* TO Insert a particular Node
Node *insert(Node *&head, Node *newNode)
{
  Node *temp = head;
  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  return temp->next = newNode;
}
Node *removeFromSortedList(Node *&head)
{
  if (!head || !head->next)
  {
    return head;
  }
  Node *curr = head;
  while (curr && curr->next)
  {
    if (curr->data == curr->next->data)
    {
      Node *duplicate = curr->next;
      curr->next = curr->next->next;
      delete duplicate;
    }
    else
      curr = curr->next;
  }
  print(head);
  return head;
}
Node *removeFromUnsortedList(Node *&head)
{
  //*Using Brute force
  Node *i = head;
  Node *j = head->next;
  Node *prev = head;
  while (i)
  {
    while (j)
    {
      if (i->data == j->data)
      {
        Node *duplicate = j;
        
      }
      else
        j = j->next;
    }
    i = i->next;
    j = i;
  }
}
int main()
{
  Node *list = new Node(10);
  insert(list, 20);
  insert(list, 30);
  insert(list, 40);
  insert(list, 40);
  insert(list, 40);
  insert(list, 50);
  insert(list, 50);
  insert(list, 60);
  insert(list, 70);
  print(list);
  Node *newList = removeFromSortedList(list);
  print(newList);
  // print(list);
  // cout << list->data << endl;
  return 0;
}