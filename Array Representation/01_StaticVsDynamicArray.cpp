#include <iostream>
using namespace std;
int main()
{

    int *p;

    int A[5] = {1, 2, 3, 4, 5};
    p = new int[5];

    p[0] = 10;
    p[1] = 20;
    p[2] = 30;
    p[3] = 40;
    p[4] = 50;

    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << endl;
    }

    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << endl;
    }
    delete []p;
    return 0;
}