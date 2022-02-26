#include <iostream>
using namespace std;
class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *x,int *y);
public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array()
    {
        delete[] A;
    }
    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    int isSorted();
    void Rearrange();
    Array *Merge(Array arr);
    Array *Union(Array arr);
    Array *Diff(Array arr);
    Array *Inter(Array arr);
};
void Array::Display()
{
    int i;
    cout << "The Elements are: ";
    for (i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
}
void Array::Append(int x)
{
    if (length < size)
    {
        A[length++] = x;
    }
}
void Array::Insert(int index, int x)
{
    if (index <= length && index >= 0 && length < size)
    {
        for (int i = length - 1; i >= index; i--)
        {
            A[i + 1] = A[i];
        }
        A[index] = x;
        length++;
    }
}
int Array::Delete(int index)
{
    if (index <= length && index >= 0)
    {
        int x = A[index];
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        return x;
    }
    return -1;
    length--;
}
void Array::swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int Array::LinearSearch(int key)
{
    int i;
    for (int i = 0; i < length; i++)
    {
        if (key == A[i])
        {
            swap(&A[0], &A[i]);
            return i;
        }
    }
    return -1;
}
int Array::BinarySearch(int key)
{
    int l, mid, h;
    l = 0;
    h = length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == A[mid])
        {
            return mid;
        }
        else if (key > A[mid])
        {
            l = mid + 1;
        }
        else if (key < A[mid])
        {
            h = mid - 1;
        }
    }
    return -1;
}
int Array::Get(int index)
{
    if (index >= 0 && index < length)
    {
        return A[index];
    }
    return -1;
}
void Array::Set(int index, int x)
{
    if (index >= 0 && index < length)
    {
        A[index] = x;
    }
}
int Array::Max()
{
    int max = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
        return max;
    }
    return -1;
}
int Array::Min()
{
    int min = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
        return min;
    }
    return -1;
}
int Array::Sum()
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += A[i];
    }
    return sum;
}
float Array::Avg()
{
    return (float)Sum() / length;
}
void Array::Reverse2()
{
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        swap(&A[i], &A[j]);
    }
}
void Array::InsertSort(int x)
{
    int i = length - 1;
    if (length == size)
    {
        return;
    }
    while (i > 0 && A[i] > x)
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}
int Array::isSorted()
{
    int i = 0;
    for (i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}
void Array::Rearrange()
{
    int i = 0;
    int j = length - 1;
    while (i < j)
    {
        while (A[i] < 0)
            i++;
        while (A[j] >= 0)
            j--;
        if (i < j)
            swap(&A[i], &A[j]);
    }
}

Array *Array::Merge(Array arr)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr1 = new Array(length + arr.length);
    while (i < length && j < arr.length)
    {
        if (A[i] < arr.A[j])
        {
            arr1->A[k] = A[i];
            k++;
            i++;
        }
        else
        {
            arr1->A[k] = arr.A[j];
            k++;
            i++;
        }
    }
    for (; i < length; i++)
    {
        arr1->A[k] = A[i];
    }
    for (; j < arr.length; j++)
    {
        arr1->A[k] = arr.A[j];
    }
    cout << arr1;
    return arr1;
}
Array *Array::Union(Array arr)

{
    int i, j, k;
    i = j = k = 0;
    Array *arr1 = new Array(length + arr.length);
    while (i < length && j < arr.length)
    {
        if (A[i] < arr.A[j])
            arr1->A[k++] = A[i++];
        else if (arr.A[j] < A[i])
            arr1->A[k++] = arr.A[j++];
        else
        {
            arr1->A[k++] = A[i++];
            j++;
        }
    }
    for (; i < length; i++)
        arr1->A[k++] = A[i];
    for (; j < arr.length; j++)
        arr1->A[k++] = arr.A[j];
    arr1->length = k;
    return arr1;
}

Array *Array::Inter(Array arr)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr1 = new Array(length + arr.length);
    while (i < length && j < arr.length)
    {
        if (A[i] < arr.A[j])

            i++;
        else if (arr.A[j] < A[i])
            j++;
        else if (A[i] == arr.A[j])
        {
            arr1->A[k++] = A[i++];
            j++;
        }
    }
    arr1->length = k;
    return arr1;
}
Array *Array::Diff(Array arr)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr1 = new Array(length + arr.length);
    while (i < length && j < arr.length)
    {
        if (A[i] < arr.A[j])
            arr1->A[k++] = A[i++];
        else if (arr.A[j] < A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < length; i++)
        arr1->A[k++] = A[i];

    arr1->length = k;
    return arr1;
}
