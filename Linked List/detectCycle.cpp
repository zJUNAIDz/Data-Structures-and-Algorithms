#include <iostream>
#include <map>
#include <vector>
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
//*floyds'cycle algrithm using slow and fast
ListNode *floydsCycle(ListNode *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }
  ListNode *slow = head;
  ListNode *fast = head;
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
    {
      cout << "Intersected at " << slow->data << endl;
      return slow;
    }
  }
  return nullptr;
}
ListNode *detectCycle(ListNode *&head)
{
  //---------------------------------------------------------------------
  //*not so optimised (using map)
  //*TC -> O(n)
  //*SC -> )(n)
  // map<ListNode *, bool> visited;
  // while (head != nullptr)
  // {
  //   if (visited[head])
  //     return head;
  //   visited[head] = true;
  //   head = head->next;
  // }
  // return nullptr;
  //---------------------------------------------------------------------
  //*using Floyd's Cycle detecting loop in a linked list
  //*TC -> O(n)
  //*SC -> O(1)
  ListNode *intersetion = floydsCycle(head);
  ListNode *slow = head;
  while (slow != intersetion && slow == nullptr)
  {
    slow = slow->next;
    intersetion = intersetion->next;
    if (slow == intersetion)
    {
      cout << "Loop starting point is " << slow->data << endl;
      cout << endl;
      cout << endl;
      return slow;
    }
  }

  cout << "Cycle or a loop not Found." << endl;
  cout << endl;
  cout << endl;
  return nullptr;
}
//*Get start of a loop
ListNode *getStartOfLoop(ListNode *head)
{
  if (!head && !head->next)
  {
    return head;
  }
  ListNode *intersection = floydsCycle(head);
  ListNode *slow = head;
  while (slow != intersection)
  {
    slow = slow->next;
    intersection = intersection->next;
  }
  return slow;
}
ListNode *removeLoop(ListNode *head)
{
  ListNode *startingPoint = getStartOfLoop(head);
  ListNode *temp = startingPoint->next;
  while (temp->next != startingPoint)
  {
    temp = temp->next;
  }
  temp = nullptr;
  //* returning starting node so we can store removed loop version some pointer
  return head;
}
int main()
{
  ListNode *list = new ListNode(10);
  insert(list, 20);
  insert(list, 30);
  //*pointing to start of loop
  ListNode *loopPoint = insert(list, 40);
  insert(list, 50);
  insert(list, 60);
  insert(list, 70);
  print(list);
  // list->next->next->next->next->next = list->next->next;
  //*creating a loop
  insert(list, loopPoint);
  //*to detect if there is a loop in a linked list or if it is circular linked list and return starting node from where loop started
  detectCycle(list);
  //*removes the loop in a linked list
  removeLoop(list);
  //*checking if loop is removed successfully
  detectCycle(list);
  //* printing after removing the loop
  print(list);
  return 0;
}