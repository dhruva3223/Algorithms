#include <iostream>
using namespace std;
int main()
{
    // Method 1
    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {1, 3, 5, 7}};

    // Method2
    int *B[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    B[0][0] = 1;
    B[0][1] = 2;
    B[0][2] = 3;
    B[0][3] = 4;
    B[1][0] = 5;
    B[1][1] = 6;
    B[1][2] = 7;
    B[1][3] = 8;
    B[2][0] = 9;
    B[2][1] = 2;
    B[2][2] = 3;
    B[2][3] = 4;

    // Method 3
    int **C;
    C = new int *[3];
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];
    C[0][0] = 1;
    C[0][1] = 2;
    C[0][2] = 3;
    C[0][3] = 4;
    C[1][0] = 5;
    C[1][1] = 6;
    C[1][2] = 7;
    C[1][3] = 8;
    C[2][0] = 9;
    C[2][1] = 2;
    C[2][2] = 3;
    C[2][3] = 4;

    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
    cout << endl;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%d ", B[i][j]);
        printf("\n");
    }
    cout << endl;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}