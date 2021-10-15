#include <bits/stdc++.h>
using namespace std;
void swap_q(int *b, int *c)
{
    int temp = *b;
    *b = *c;
    *c = temp;
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int partition(int arr[], int i, int j)
{

    int piviot = arr[i];
    while (i < j)
    {
        while (piviot > arr[i])
        {
            i++;
        }
        while (piviot < arr[j])
        {
            j--;
        }
        swap_q(&arr[i], &arr[j]);
    }
    swap_q(&piviot, &arr[j]);

    return j;
}

void quick_sort(int arr[], int i, int j)
{

    if (i < j)
    {
        int piviot = partition(arr, i, j);
        quick_sort(arr, i, (piviot - 1));
        quick_sort(arr, (piviot + 1), j);
    }
}

void merge(int arr[], int lb, int mid, int ub)
{

    int i = lb;
    int b[ub];
    int j = mid + 1;
    int k = lb;
    while (i <= mid && j <= ub)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        while (j <= ub)
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    /////////////////right is exausted
    else
    {
        while (i <= mid)
        {
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    ////////////copying b arr in original array arr
    for (k = lb; k <= ub; k++)
    {
        arr[k] = b[k];
    }
    int size = sizeof(arr) / arr[0];
    cout << endl;
    display(arr, size);
    cout << endl;
}
int merge_sort(int arr[], int i, int j)
{
    int count_merge;
    int count_division;

    if (i < j)
    {
        int mid = (i + (j - i) / 2);
        count_division++; //
        merge_sort(arr, i, mid);
        count_division++; //
        merge_sort(arr, mid + 1, j);
        count_merge++;
        merge(arr, i, mid, j);
    }
    // cout << "\nThe number of times division is performed is : " << count_division;
    // cout << "\nThe number of times merge is performed is : " << count_merge << endl;
    return count_merge, count_division;
}

int main()
{
    // int arr[6] = {1, 5, 2, 6, 3};
    // int i = 0, j = 4;
    // quick_sort(arr, i, j);
    // display(arr);
    int n;
    cout << "Enter the number of elements\n";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array to be sorted\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value for [" << i + 1 << "] :";
        cin >> arr[i];
        cout << endl;
    }
    int ch;
    do
    {
        cout << "\nEnter your choice : ";
        cin >> ch;

        cout << "\nEnter 1 for Quick sort\n";
        cout << "Enter 2 for Merge sort\n";
        cout << "Enter 3 to exit\n";
        switch (ch)
        {
        case 1:
        {
            cout << "\nEnter 1 to have pivot as the first element :";
            cout << "\nEnter 2 to have pivot as the last element :";
            cout << "\nEnter 3 to have pivot as the median element :";
            quick_sort(arr, 0, n - 1);
            display(arr, n);
            break;
        }
        case 2:
        {

            // cout << "Number of division and merges are :" << merge_sort(arr, 0, n - 1);
            merge_sort(arr, 0, n - 1) break;
        }

        default:
            break;
        }

    } while (ch != 3);

    return 0;
}