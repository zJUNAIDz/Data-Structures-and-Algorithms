#include <iostream>
using namespace std;


int fact(int num){
  int res = 1;
  for(int i = num; i>1; i--){
    res*=i;
  }
  return res;
}
int findComb(int n, int r){
  return (fact(n)/(fact(r)*fact(n-r)));
}
int main()
{
  cout << findComb(4,3);
  return 0;
}