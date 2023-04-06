#include "BubbleSort.h"
#include "InsertSort.h"
#include "SelectSort.h"
#include "ShellSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include <iostream>

//打印排序后的数组
void print_sorted(vector<int>& arr)
{
	for (auto i : arr) {
		cout << i << " ";
	}
	cout << endl;
}

void test_bubble_sort(vector<int>& arr)
{
	bubblesort(arr);
	print_sorted(arr);
}

void test_bubble_sort_flag(vector<int>& arr)
{
	bubblesort_flag(arr);
	print_sorted(arr);
}

void test_insertSort(vector<int>& arr)
{
	insertSort(arr);
	print_sorted(arr);
}

void test_selectSort(vector<int>& arr)
{
	selectSort(arr);
	print_sorted(arr);
}

void test_shellSort(vector<int>& arr)
{
	shellSort(arr);
	print_sorted(arr);
}

void test_qucikSort(vector<int>& arr)
{
	quicksort(arr, 0, arr.size()-1);
	print_sorted(arr);
}

void test_QucikSort(vector<int>& arr)
{
	QuickSort(arr, 0, arr.size() - 1);
	print_sorted(arr);
}

void test_MergeSort(vector<int>& arr)
{
	MergeSort(arr, 0, arr.size() - 1);
	print_sorted(arr);
}

void test_HeapSort(vector<int>& arr)
{
	HeapSort(arr);
	print_sorted(arr);
}

int main()
{
	vector<int> arr = { 3 , 6 , 5 , 12 , 1 ,-1,1,1,11, 25 , 10, -3, 0 };
	/*
	test_bubble_sort(arr);		//不进行优化的冒泡排序
	test_bubble_sort_flag(arr);	//进行优化的冒泡排序
	*/

	//test_insertSort(arr);		//直接插入排序
	//test_selectSort(arr);		//选择排序
	//test_shellSort(arr);		//希尔排序
	//test_qucikSort(arr);		//原始快排
	//test_QucikSort(arr);		//三路快排
	//test_MergeSort(arr);		//归并排序
	test_HeapSort(arr);
	return 0;
}