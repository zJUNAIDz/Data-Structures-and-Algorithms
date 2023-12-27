// NOTE: Using Recusrsion
#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &inputStack, int count, int size)
{
  //* Base Case
  if (inputStack.size() == size / 2)
  {
    inputStack.pop();
    return;
  }

  int temp = inputStack.top();
  inputStack.pop();

  //* Recursive case
  solve(inputStack, count + 1, size);

  inputStack.push(temp);
}

void deleteMiddle(stack<int> &inputStack, int size)
{
  int count = 0;
  solve(inputStack, count, size);
}

