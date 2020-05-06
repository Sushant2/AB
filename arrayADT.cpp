#include <iostream>
using namespace std;
class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y)
    {
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }

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
    void Display()
    {
        int i;
        cout << "Elements are:";
        for (i = 0; i < length; i++)
            cout << A[i] << " ";
    }
    void Append(int x)
    {
        if (length < size)
            A[length++] = x;
    }
    void Insert(int index, int x)
    {
        int i;
        if (index >= 0 && index <= length)
        {
            for (i = length; i > index; i--)
                A[i] = A[i - 1];
            A[index] = x;
            length++;
        }
    }
    int Delete(int index)
    {
        int x = 0;
        int i;
        if (index >= 0 && index < length)
        {
            x = A[index];
            for (i = index; i < length - 1; i++)
                A[i] = A[i + 1];
            length--;
            return x;
        }
        return 0;
    }
    int LinearSearch(int key)
    {
        int i;
        for (i = 0; i < length; i++)
        {
            if (key == A[i])
            {
                swap(&A[i], &A[0]);
                return i;
            }
        }
        return -1;
    }
    int BinarySearch(int key)
    {
        int l, mid, h;
        l = 0;
        h = length - 1;
        while (l <= h)
        {
            mid = (l + h) / 2;
            if (key == A[mid])
                return mid;
            else if (key < A[mid])
                h = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    int RBinSearch(int a[], int l, int h, int key)
    {
        int mid;
        if (l <= h)
        {
            mid = (l + h) / 2;
            if (key == a[mid])
                return mid;
            else if (key < a[mid])
                return RBinSearch(a, l, mid - 1, key);
            else
                return RBinSearch(a, mid + 1, h, key);
        }
        return -1;
    }
    int Get(int index)
    {
        if (index >= 0 && index < length)
            return A[index];
        return -1;
    }
    void Set(int index, int x)
    {
        if (index >= 0 && index < length)
            A[index] = x;
    }
    int Max()
    {
        int max = A[0];
        int i;
        for (i = 1; i < length; i++)
        {
            if (A[i] > max)
                max = A[i];
        }
        return max;
    }
    int Min()
    {
        int min = A[0];
        int i;
        for (i = 1; i < length; i++)
        {
            if (A[i] < min)
                min = A[i];
        }
        return min;
    }
    int Sum()
    {
        int s = 0;
        int i;
        for (i = 0; i < length; i++)
            s += A[i];
        return s;
    }
    float Avg()
    {
        return (float)Sum() / length;
    }
    void Reverse()
    {
        int *B;
        int i, j;
        B = new int[length];
        for (i = length - 1, j = 0; i >= 0; i--, j++)
            B[j] = A[i];
        for (i = 0; i < length; i++)
            A[i] = B[i];
    }
    void Reverse2()
    {
        int i, j;
        for (i = 0, j = length - 1; i < j; i++, j--)
        {
            swap(&A[i], &A[j]);
        }
    }
    void InsertSort(int x)
    {
        int i = length - 1;
        if (length == size)
            return;
        while (i >= 0 && A[i] > x)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = x;
        length++;
    }
    int isSorted()
    {
        int i;
        for (i = 0; i < length - 1; i++)
        {
            if (A[i] > A[i + 1])
                return 0;
        }
        return 1;
    }
    void Rearrange()
    {
        int i, j;
        i = 0;
        j = length - 1;
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
    Array *Merge(Array arr2)
    {
        int i, j, k;
        i = j = k = 0;
        Array *arr3 = new Array(length + arr2.length);

        while (i < length && j < arr2.length)
        {
            if (A[i] < arr2.A[j])
                arr3->A[k++] = A[i++];
            else
                arr3->A[k++] = arr2.A[j++];
        }
        for (; i < length; i++)
            arr3->A[k++] = A[i];
        for (; j < arr2.length; j++)
            arr3->A[k++] = arr2.A[j];
        arr3->length = length + arr2.length;
        arr3->size = 10;
        return arr3;
    }
    Array *Union(Array arr2)
    {
        int i, j, k;
        i = j = k = 0;
        Array *arr3 = new Array(length + arr2.length);
        while (i < length && j < arr2.length)
        {
            if (A[i] < arr2.A[j])
                arr3->A[k++] = A[i++];
            else if (arr2.A[j] < A[i])
                arr3->A[k++] = arr2.A[j++];
            else
            {
                arr3->A[k++] = A[i++];
                j++;
            }
        }
        for (; i < length; i++)
            arr3->A[k++] = A[i];
        for (; j < arr2.length; j++)
            arr3->A[k++] = arr2.A[j];
        arr3->length = k;
        arr3->size = 10;
        return arr3;
    }
    Array *Intersection(Array arr2)
    {
        int i, j, k;
        i = j = k = 0;
        Array *arr3 = new Array(length + arr2.length);
        while (i < length && j < arr2.length)
        {
            if (A[i] < arr2.A[j])
                i++;
            else if (arr2.A[j] < A[i])
                j++;
            else if (A[i] == arr2.A[j])
            {
                arr3->A[k++] = A[i++];
                j++;
            }
        }
        arr3->length = k;
        arr3->size = 10;
        return arr3;
    }
    Array *Difference(Array arr2)
    {
        int i, j, k;
        i = j = k = 0;
        Array *arr3 = new Array(length + arr2.length);
        while (i < length && j < arr2.length)
        {
            if (A[i] < arr2.A[j])
                arr3->A[k++] = A[i++];
            else if (arr2.A[j] < A[i])
                j++;
            else
            {
                i++;
                j++;
            }
        }
        for (; i < length; i++)
            arr3->A[k++] = A[i];
        arr3->length = k;
        arr3->size = 10;
        return arr3;
    }
};
int main()
{
    Array *arr1;
    int ch, sz;
    int x, index;
    cout << "Enter Size of Array:";
    cin >> sz;
    arr1 = new Array(sz);
    do
    {
        cout << "\n\nMenu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Display\n";
        cout << "6.Exit\n";
        cout << "Enter you choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter an element and index:";
            cin >> x >> index;
            arr1->Insert(index, x);
            break;
        case 2:
            cout << "Enter index:";
            cin >> index;
            x = arr1->Delete(index);
            cout << "Deleted Element is:\n"
                 << x;
            break;
        case 3:
            cout << "Enter element to search:";
            cin >> x;
            index = arr1->LinearSearch(x);
            cout << "Element index:" << index;
            break;
        case 4:
            cout << "Sum is\n"
                 << arr1->Sum();
            break;
        case 5:
            arr1->Display();
        }
    } while (ch < 6);
    return 0;
}