#include <iostream>
using namespace std;

int main()
{
    int ans = 0;
    int n = 998001;
    int start = 0;
    int end = n;
   long long int mid = start + (end - start) / 2;
    while (start < end)
    {
        long long int square = mid*mid;
        if (square == n)
        {
            cout << mid << endl;    
            return 0;
        }
        else if (square > n)
            {end = mid - 1;}
        else if (square< n)
        {
            ans = mid;
            start = mid+1;
        }
        mid = start + (end - start) / 2;
        cout << start << " " <<mid << " "<< end <<endl;
        // cout << "start ="<< start << endl;
        // cout << "mid = " << mid << endl;
        // cout << "end = "<< end << endl;
    }
    cout <<ans  <<" ok" << endl;
    return 0;
}