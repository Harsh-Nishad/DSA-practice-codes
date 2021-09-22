#include <bits/stdc++.h>
using namespace std;
// void swap_b(int *b, int *c)
// {
//     int temp = *b;
//     *b = *c;
//     *c = temp;
// }

// void sort_bubble(int arr[])
// {
//     for (int i = 0; i < 5 - 1; i++)
//     {
//         for (int j = 0; j < 5 - 1 - i; j++)
//         {
//             if (arr[j + 1] < arr[j])
//             {
//                 swap_b(&arr[j + 1], &arr[j]);
//             }
//         }
//     }
// }
// int main()

// {
//     int arr[5] = {1, 4, 2, 6, 7};
//     sort_bubble(arr);
//     for (int i = 0; i < 5; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

////////////////////////////////////////////////INSERTION SORT////

// void insert_sort(int arr[])
// {
//     for (int i = 1; i < 5; i++)
//     {
//         int temp = arr[i];
//         for (int j = i - 1; j >= 0; j--)
//         {

//             if (arr[j] < temp)
//             {
//                 arr[j + 1] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
//     for (int i = 0; i < 5; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }
// int main()
// {
//     int arr[6] = {1, 5, 2, 6, 3};
//     insert_sort(arr);

//     return 0;
// }

////////////////////////////////////////////////////selection sort/////
void swap_s(int *b, int *c)
{
    int temp = *b;
    *b = *c;
    *c = temp;
}
void selection_sort(int arr[])
{
    for (int i = 0; i < 5; i++)
    {
        int temp = i;
        for (int j = i + 1; j < 5; j++)
        {
            if (arr[j] < arr[temp])
            {
                temp = j;
            }
        }
        swap_s(&arr[temp], &arr[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[6] = {1, 5, 2, 6, 3};
    selection_sort(arr);

    return 0;
}

/////////////////////////////////////////////////quick sort/////////////
// void swap_q(int *b, int *c)
// {
//     int temp = *b;
//     *b = *c;
//     *c = temp;
// }

// int partition(int arr[], int i, int j)
// {

//     int piviot = arr[i];
//     while (i < j)
//     {
//         while (piviot > arr[i])
//         {
//             i++;
//         }
//         while (piviot < arr[j])
//         {
//             j--;
//         }
//         swap_q(&arr[i], &arr[j]);
//     }
//     swap_q(&piviot, &arr[j]);

//     return j;
// }
// void quick_sort(int arr[], int i, int j)
// {

//     if (i < j)
//     {
//         int piviot = partition(arr, i, j);
//         quick_sort(arr, i, (piviot - 1));
//         quick_sort(arr, (piviot + 1), j);
//     }
// }
// void display(int arr[])
// {
//     for (int i = 0; i < 5; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }

// int main()
// {
//     int arr[6] = {1, 5, 2, 6, 3};
//     int i = 0, j = 4;
//     quick_sort(arr, i, j);
//     display(arr);

//     return 0;
// }

// void display(int arr[])
// {
//     for (int i = 0; i < 5; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }
// void merge(int arr[], int lb, int mid, int ub)
// {
//     int i = lb;
//     int b[ub];
//     int j = mid + 1;
//     int k = lb;
//     while (i <= mid && j <= ub)
//     {
//         if (arr[i] < arr[j])
//         {
//             b[k] = arr[i];
//             i++;
//         }
//         else
//         {
//             b[k] = arr[j];
//             j++;
//         }
//         k++;
//     }
//     //////////////////left is exusted
//     if (i > mid)
//     {
//         while (j <= ub)
//         {
//             b[k] = arr[j];
//             j++;
//             k++;
//         }
//     }
//     /////////////////right is exausted
//     else
//     {
//         while (i <= mid)
//         {
//             b[k] = arr[i];
//             i++;
//             k++;
//         }
//     }
//     ////////////copying b arr in original array arr
//     for (k = lb; k <= ub; k++)
//     {
//         arr[k] = b[k];
//     }
//     display(arr);
// }
// void merge_sort(int arr[], int i, int j)
// {
//     if (i < j)
//     {
//         int mid = (i + (j - i) / 2);
//         merge_sort(arr, i, mid);
//         merge_sort(arr, mid + 1, j);
//         merge(arr, i, mid, j);
//     }
// }

// ////////////////////////////////////////////////////////merge sort//////////////
// int main()
// {
//     int arr[6] = {1, 5, 2, 6, 3};
//     int i = 0, j = 4;
//     merge_sort(arr, i, j);
//     display(arr);

//     return 0;
// }
