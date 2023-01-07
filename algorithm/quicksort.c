#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define SIZE 100000
void quick_sort(int arr[], int, int);
void quick_sort(int arr[], int begin, int end) {
	if (begin > end)
		return;
	int temp = arr[begin];
	int i = begin;
	int j = end;
	while (i!=j) {
		while (arr[j] >= temp && j > i)
			j--;
		while (arr[i] <= temp && j > i)
			i++;
		if (j > i) {
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}
	arr[begin] = arr[i];
	arr[i] = temp;
	quick_sort(arr, begin, i - 1);
	quick_sort(arr, i + 1, end);
	

	
}
int main() {
	srand((unsigned int)time(NULL));
	int arr[SIZE];
	printf("排序前的随机数组\n");
	for (int i = 0; i < SIZE-1; i++) {
		arr[i] = rand();
		printf("%d\t", arr[i]);
	}
	for(int i=0;i<50;i++)
		printf("\n");
	printf("快速排序后的数组\n");
	quick_sort(arr,0,SIZE-1);
	for (int i = 0; i < SIZE-1; i++) {
		printf("%d\t", arr[i]);
	}
	return 0;
}