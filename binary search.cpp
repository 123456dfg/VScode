#include<iostream>
#include<algorithm>
using namespace std;
int search1(int arr[20], int, int, int);
int search1(int arr[20], int a, int begin, int end) {
    int mid = (begin + end) / 2;
        if (arr[mid] == a) {
            return mid;
        }
        if (arr[mid] > a) {
            search1(arr,a, begin, mid - 1);
        }
        else search1(arr,a, mid + 1, end);
        
}
int main() {
    int arr[20] = { 25,10,11,12,13,44,55,66,100,1,5,6,14,3,14,67,87,41,20,36 };
    sort(arr,arr+20);
    cout << arr;
    int flag = search1(arr, 5, 1-1, 20-1);
    if (!flag) {
        cout << "没有找到值" << endl;
    }
    else cout << "所在下标为" << flag << endl;
    return 0;
}