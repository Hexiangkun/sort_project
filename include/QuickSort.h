#pragma once
#include <vector>
#include <time.h>

using namespace std;
//void QuickSort(vector<int>& list, int left, int right);

int partition(vector<int>& list, int left, int right)
{
	srand(time(nullptr));
	int random = rand() % (right - left + 1) + left;
	swap(list[random], list[left]);//随机划分枢轴

	int pivot = list[left];

	while (left < right) {
		while (left<right && list[right]>pivot) {//从右边找一个比枢轴小的元素
			right--;
		}
		list[left] = list[right];
		while (left < right && list[left] < pivot) {//从左边找一个比枢轴大的元素
			left++;
		}
		list[right] = list[left];
	}
	list[left] = pivot;//left和right相等，将枢轴元素赋值
	return left;//返回中间元素索引
}


void quicksort(vector<int>& list,int left, int right)
{
	if (left < right) {
		int pos = partition(list, left, right);
		quicksort(list, left, pos - 1);
		quicksort(list, pos + 1, right);
	}
}


void QuickSort(vector<int>& list, int left, int right)
{
	if (left < right) {
		srand(time(nullptr));
		int random = rand() % (right - left + 1) + left;
		swap(list[random], list[left]);
		int pivot = list[left];

		int l = left;
		int i = left + 1;
		int r = right;
		while (i <= r) {
			if (list[i] < pivot) {
				swap(list[i], list[l]);
				i++;
				l++;
			}
			else if(list[i]==pivot)
			{
				i++;
			}
			else {
				swap(list[i], list[r]);
				r--;
			}
		}
		QuickSort(list, left, l - 1);
		QuickSort(list, r + 1, right);
	}
}


