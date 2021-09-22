// #include <bits/stdc++.h>
// using namespace std;
// // int binser(int a[], int e, int f, int r, int mid)
// // {

// //     mid = (f + r) / 2;
// //     if (a[mid] == e)
// //         return mid;
// //     else if (a[mid] > e)
// //     {
// //         r = mid - 1;
// //     }
// //     else if (a[mid] < e)
// //     {
// //         f = mid + 1;
// //     }
// //     else
// //         return 0;
// //     binser(a, e, f, r, mid);
// // }
// // int main()
// // {
// //     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// //     int ele = 2;
// //     //cin >> ele;
// //     int f = 0, r = sizeof(arr) - 1, mid;
// //     cout << "element found at  " << binser(arr, ele, f, r, mid) << endl;

// //     return 0;
// // }

// // int first_last(int arr[], int e)
// // {
// //     int t = -1, f = 0, r = 7, m;
// //     while (f <= r)
// //     {
// //         m = (f + (r - f) / 2);

// //         if (arr[m] == e)
// //         {
// //             t = m;
// //             r = m - 1;
// //             //for last occurance f=m+1;
// //         }
// //         else if (arr[m] > e)
// //         {
// //             r = m - 1;
// //         }
// //         else
// //             f = m + 1;
// //     }
// //     return t;
// // }
// // int main()
// // {
// //     int arr[8] = {1, 2, 10, 10, 10, 10, 17, 18};
// //     int ele = 10;
// //     cout << "the first occurance is at " << first_last(arr, ele);
// //     return 0;
// // }

// // int last_(int arr[], int e)
// // {
// //     int t = -1, f = 0, r = 7, m;
// //     while (f <= r)
// //     {
// //         m = (f + (r - f) / 2);

// //         if (arr[m] == e)
// //         {
// //             t = m;
// //             //r = m - 1;
// //             f = m + 1;
// //         }
// //         else if (arr[m] > e)
// //         {
// //             r = m - 1;
// //         }
// //         else
// //             f = m + 1;
// //     }
// //     return t;
// // }
// // int first_(int arr[], int e)
// // {
// //     int t = -1, f = 0, r = 7, m;
// //     while (f <= r)
// //     {
// //         m = (f + (r - f) / 2);

// //         if (arr[m] == e)
// //         {
// //             t = m;
// //             r = m - 1;
// //             //for last occurance f=m+1;
// //         }
// //         else if (arr[m] > e)
// //         {
// //             r = m - 1;
// //         }
// //         else
// //             f = m + 1;
// //     }
// //     return t;
// // }
// // // int main()
// // {
// //     int arr[8] = {1, 2, 10, 10, 10, 10, 17, 18};
// //     int ele = 10;
// //     int sum = last_(arr, ele) - first_(arr, ele) + 1;
// //     cout << sum << endl;
// //     //cout << "the first occurance is at " << countele(arr, ele);
// //     return 0;
// // }

// // int no_of_rotation(int a[])
// // {
// //     int front = 0, end = 7, mid, res;
// //     while (front <= end)
// //     {
// //         mid = (front + (end - front) / 2);
// //         int n = (mid + 1) % 7;
// //         int p = (mid - 1) % 7;
// //         if (a[mid] < a[n] && a[mid] < a[p])
// //         {
// //             return mid;
// //         }
// //         else if (a[front] < a[mid])
// //         {
// //             front = mid + 1;
// //         }
// //         else if (a[mid] < a[end])
// //         {
// //             end = mid - 1;
// //         }
// //     }
// //     return res;
// // }
// // int main()
// // {
// //     int arr[8] = {11, 12, 15, 18, 2, 4, 6, 8};
// //     cout << "the array is rotated by " << no_of_rotation(arr);

// //     return 0;
// // }

// // int floor_(int a[], int ele)
// // {
// //     int start = 0, end = 7, mid, res;
// //     while (start <= end)
// //     {
// //         mid = (start + (end - start) / 2);
// //         if (a[mid] == ele)
// //         {
// //             res = a[mid];
// //         }
// //         else if (a[mid] > ele)
// //         {
// //             end = mid - 1;
// //         }
// //         else if (a[mid] < ele)
// //         {
// //             res = a[mid];
// //             start = mid + 1;
// //         }
// //     }
// //     return res;
// // }
// // int main()
// // {
// //     int arr[8] = {1, 2, 3, 4, 8, 10, 12, 19};
// //     int ele = 11;
// //     cout << "the floor of the element is  " << floor_(arr, ele);

// //     return 0;
// // }
// // int ceil_(int a[], int ele)
// // {
// //     int start = 0, end = 7, mid, res;
// //     while (start <= end)
// //     {
// //         mid = (start + (end - start) / 2);
// //         if (a[mid] == ele)
// //         {
// //             res = a[mid];
// //         }
// //         else if (a[mid] < ele)
// //         {
// //             start = mid + 1;
// //         }
// //         else if (a[mid] > ele)
// //         {
// //             res = a[mid];
// //             end = mid - 1;
// //         }
// //     }
// //     return res;
// // }
// // int main()
// // {
// //     int arr[8] = {1, 2, 3, 4, 8, 10, 12, 19};
// //     int ele = 5;
// //     cout << "the floor of the element is  " << ceil_(arr, ele);

// //     return 0;
// // }

// // int min_diff(int a[], int ele)
// // {
// //     int start = 0, end = 7, mid, res;
// //     while (start <= end)
// //     {
// //         mid = (start + (end - start) / 2);
// //         if (a[mid] == ele)
// //         {
// //             return a[mid];
// //         }
// //         else if (a[mid] < ele)
// //         {
// //             start = mid + 1;
// //         }
// //         else if (a[mid] > ele)
// //         {
// //             end = mid - 1;
// //         }
// //     }
// //     int av = abs(a[start] - ele);
// //     int bv = abs(a[end] - ele);
// //     if (av > bv)
// //         return a[start];
// //     else
// //         return a[end];
// // }

// // int main()
// // {
// //     int arr[8] = {1, 2, 3, 4, 8, 10, 12, 19};
// //     int ele = 9;
// //     //cout << "the floor of the element is  " << min_diff(arr, ele);
// //     cout << "the min is with " << min_diff(arr, ele);

// //     return 0;
// // }

// // int peekgfg(int a[])
// // {
// //     int start = 0, end = 3, mid;
// //     while (start <= end)
// //     {
// //         mid = (start - (end - start) / 2);
// //         if (mid > 0 && mid < 3)
// //         {
// //             if (a[mid] > a[mid + 1] && a[mid] > a[mid - 1])
// //                 return a[mid];

// //             else if (a[mid + 1] > a[mid])
// //                 start = mid + 1;

// //             else
// //                 end = mid - 1;
// //         }
// //         else if (mid == 0)
// //         {
// //             if (a[0] > a[1])
// //                 return 0;
// //             else
// //                 return 1;
// //         }
// //         else if (mid = 3)
// //         {
// //             if (a[3] > a[2])
// //                 return 3;
// //             else
// //                 return 2;
// //         }
// //     }
// // }
// // int main()
// // {
// //     int arr[8] = {5, 10, 20, 15};
// //     //int ele = 9;
// //     //cout << "the floor of the element is  " << min_diff(arr, ele);
// //     cout << "the peek element is " << peekgfg(arr);

// //     return 0;
// // }

// int samsung_first(int a[], int ele)
// {
//     int start = 0, end = 7, mid, res, first, last;
//     while (start <= end)
//     {
//         mid = (start + (end - start) / 2);
//         if (a[mid] == ele)
//         {
//             res = mid;
//             end = mid - 1;
//         }
//         else if (a[mid] < ele)
//         {
//             start = mid + 1;
//         }
//         else
//         {
//             end = mid - 1;
//         }
//     }
//     return res;
// }
// int samsung_last(int a[], int ele)
// {
//     int start = 0, end = 7, mid, res, first, last;
//     while (start <= end)
//     {
//         mid = (start + (end - start) / 2);
//         if (a[mid] == ele)
//         {
//             res = mid;
//             start = mid + 1;
//         }
//         else if (a[mid] < ele)
//         {
//             start = mid + 1;
//         }
//         else
//         {
//             end = mid - 1;
//         }
//     }
//     return res;
// }
// int change(int a[], int l, int f)
// {

//     for (int i = f, j = 0; i <= l, j <= (l - f); i++, j++)
//     {
//         a[i] = a[i] + j;
//     }
//     for (int i = 0; i < 7; i++)
//     {
//         cout << a[i] << "  ";
//     }
// }
// int main()
// {
//     int arr[7] = {1, 2, 3, 4, 5, 5, 5};
//     int ele = 5;
//     //cout << "the floor of the element is  " << min_diff(arr, ele);
//     int f = samsung_first(arr, ele);

//     int l = samsung_last(arr, ele);
//     change(arr, l, f);

//     return 0;
// }
