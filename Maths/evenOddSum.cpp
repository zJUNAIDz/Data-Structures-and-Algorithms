#include <iostream>
using namespace std;

int main() {
  // Write your code here
  int n;
  cin >> n;
  int evenSum = 0;
  int oddSum = 0;
  int digit = n % 10;

  while (n) {
    if (digit % 2 == 0)
      evenSum += digit;
    if (digit % 2) {
      oddSum += digit;
    }
    n = n / 10;
    digit = n % 10;
    return 0;
  }