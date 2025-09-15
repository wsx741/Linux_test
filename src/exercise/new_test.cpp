#include <iostream>
using namespace std;

int main()
{
    int *p1 = new int(5);
    int *p2 = new int[5]{0};
    cout << *p1 << endl;
    cout << p2[2] << endl;
    cout << *(p2 + 2) <<endl;
    delete p1;
    delete[] p2;
    return 0;
}