#pragma once
#include <vector>

using namespace std;

void Merge(vector<int>& list, int left, int mid, int right)
{
	vector<int> temp(list);	//临时数组

	int i = left;//左边有序序列索引
	int j = mid + 1;//右边有序序列索引
	int k = left;	//执行临时数组当前索引

	while (i <= mid && j <= right) {
		if (temp[i] <= temp[j]) {
			list[k++] = temp[i++];
		}
		else {
			list[k++] = temp[j++];
		}
	}
	while (i <= mid) {
		list[k++] = temp[i++];
	}
	while (j <= right) {
		list[k++] = temp[j++];
	}
}

void MergeSort(vector<int>& list, int left, int right)
{
	if (left < right) {
		int mid = (left + right)/2;   //划分
		MergeSort(list, left, mid); //对左侧递归
		MergeSort(list, mid + 1, right);//对右侧递归
		Merge(list, left, mid, right);	//合并
	}
}