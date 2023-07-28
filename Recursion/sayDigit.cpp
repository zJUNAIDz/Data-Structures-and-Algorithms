#include <iostream>
#include <vector>
using namespace std;
void sayDigit(int n)
{
  // Base Case
  if (n == 0)
    return;
  // Processing
  vector<string> map = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  // extracting last digit
  int digit = n % 10;
  // updating the number by shortening last digit
  n /= 10;

  // Recursive Relation
  sayDigit(n);
  // printing hehe
  cout << map[digit] << ' ';
}
int main()
{
  sayDigit(234);
  return 0;
}