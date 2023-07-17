#include <iostream>
using namespace std;
int main()
{
    // int num = 7;
    // int *ptr = &num;
    // int addr = ptr[3];
    // cout << num <<endl;
    // cout << &num <<endl;
    // cout << ptr <<endl;
    // cout << *ptr <<endl;
    // cout << addr <<endl;

    //Important Concept : Pointer Arithmetics

    // double i[] = {2.4,3.9};
    // double *p = i;

    // // cout << i <<endl;
    // // cout << &i <<endl;
    // cout << p <<endl;
    // cout << *p <<endl;
    // p++;
    //     // cout << i <<endl;
    // // cout << &i <<endl;
    // cout << p <<endl;
    // cout << *p <<endl;
    // p ++;
    // cout << p <<endl;
    // cout << *p <<endl;

    int a = 34;
    int b = 45;
    int *p= &a;
    *p++ ;
    cout << *p <<endl;
}