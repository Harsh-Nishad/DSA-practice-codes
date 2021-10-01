#include <bits/stdc++.h>
using namespace std;
void print_arr(float arr[], int s)
{
    cout << "\nThe sorted array is :";
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
}
void swap(float *b, float *c)
{

    float temp = *b;
    *b = *c;
    *c = temp;
}
////////////////////////////////////////////////BUBBLE SORT////
void sort_bubble(float arr[], int s)
{
    int comp_b, count_s;
    for (int i = 0; i < s - 1; i++)
    {
        for (int j = 0; j < s - 1 - i; j++)
        {
            comp_b++;
            if (arr[j + 1] < arr[j])
            {

                swap(&arr[j + 1], &arr[j]);
                count_s++;
            }
        }
    }
    print_arr(arr, s);
    cout << "\nThe number of comparison are :" << comp_b;
    cout << "\nThe number of swaps are :" << count_s;
    cout << endl;
}

////////////////////////////////////////////////INSERTION SORT////

void insert_sort(float arr[], int s)
{
    int swap_i, comp_i;
    for (int i = 1; i < s; i++)
    {
        float temp = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            comp_i++;
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swap_i;
            }
        }
    }
    print_arr(arr, s);
    cout << "\nThe number of comparison are :" << comp_i;
    cout << "\nThe number of swaps are :" << swap_i;
    cout << endl;
}
////////////////////////////////////////////////SELECTION SORT////
void selection_sort(float arr[], int s)
{
    int swap_s, comp_s;
    for (int i = 0; i < s; i++)
    {
        int temp = i;
        for (int j = i + 1; j < s; j++)
        {
            comp_s++;
            if (arr[j] < arr[temp])
            {
                temp = j;
            }
        }
        swap(&arr[temp], &arr[i]);
        swap_s++;
    }
    print_arr(arr, s);
    cout << "\nThe number of comparison are :" << comp_s;
    cout << "\nThe number of swaps are :" << swap_s;
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the numbers in array\n";
    cin >> n;
    float arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the value :";
        cin >> arr[i];
    }
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << size << endl;
    int ch;
    do
    {
        cout << endl;
        cout << "Enter 1 for bubble sort\n";
        cout << "Enter 2 for insertion sort\n";
        cout << "Enter 3 for selection sort\n";
        cout << "Enter 4 to exit \n";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            sort_bubble(arr, size);
            break;
        }
        case 2:
        {
            insert_sort(arr, size);
            break;
        }
        case 3:
        {
            selection_sort(arr, size);
            break;
        }
        case 4:
        {
            break;
        }
        default:
            break;
        }
    } while (ch != 4);

    return 0;
}