#include <iostream>
using namespace std;
struct Array
{
    int *A;
    int size;
    int length;
};
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void Display(struct Array arr)
{
    int i;
    cout << "\nElements are\n";
    for (i = 0; i < arr.length; i++)
        cout << arr.A[i] << " ";
}
int get(struct Array arr, int idx)
{
    if (idx >= 0 && idx < arr.length)
        return arr.A[idx];
}
int set(struct Array arr, int i, int val)
{
    if (i >= 0 && i < arr.length)
        arr.A[i] = val;
}
int max(struct Array arr)
{
    int maxV = arr.A[0];
    for (int i = 0; i < arr.length; i++)
        if (arr.A[i] > maxV)
            maxV = arr.A[i];
    return maxV;
}
int min(struct Array arr)
{
    int minV = arr.A[0];
    for (int i = 0; i < arr.length; i++)
        if (arr.A[i] < minV)
            minV = arr.A[i];
    return minV;
}
int sum(struct Array arr)
{
    int total = 0;
    for (int i = 0; i < arr.length; i++)
        total = total + arr.A[i];
    return total;
}
// using recursion
// int sumR(struct Array arr, int n){
//     if(n<=0)
//         return 0;
//     return sumR(arr.A, n-1) + arr.A[arr.length];
// }
float Avg(struct Array arr)
{
    return (float)sum(arr) / arr.length;
}
void Reverse(struct Array *arr)
{
    int *B, i, j;
    B = new int[arr->length];
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];
    for (i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
}
void Reverse2(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
        swap(&arr->A[i], &arr->A[j]);
}
void insertsort(struct Array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
        return;
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}
bool isSorted(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length - 1; i++)
        if (arr.A[i] > arr.A[i + 1])
            return false;
    return true;
}
void rearrange(struct Array *arr)
{
    int i, j;
    i = 0;
    j = arr->length;

    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;
        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}
struct Array *merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}
int main()
{
    struct Array arr1, arr2, *arr3;
    int n1, n2;
    cout << "Enter size of an array:";
    cin >> arr1.size;
    cout << "Enter size of an 2nd array:";
    cin >> arr2.size;
    arr1.A = new int[arr1.size];
    arr2.A = new int[arr2.size];
    arr1.length = 0;
    arr2.length = 0;
    cout << "Enter how many numbers for 1st array:";
    cin >> n1;
    cout << "Enter how many numbers for 2st array:";
    cin >> n2;
    cout << "Enter Elements for 1st array:\n";
    for (int i = 0; i < n1; i++)
        cin >> arr1.A[i];
    arr1.length = n1;
    cout << "Enter elements for 2nd array:";
    for (int i = 0; i < n2; i++)
        cin >> arr2.A[i];
    arr2.length = n2;
    // cout<<get(arr, 4);
    // cout<<set(arr, 3, 75);
    // cout<<max(arr);
    // cout<<min(arr);
    // cout<<sumR(arr, arr.length);
    // cout<<Avg(arr);
    // Reverse(&arr);
    // Reverse2(&arr);
    // insertsort(&arr, 4);
    // cout<<isSorted(arr);
    // rearrange(&arr);
    arr3 = merge(&arr1, &arr2);

    Display(*arr3);
    return 0;
}