#pragma once

#include <vector>
#include <iostream>
using namespace std;

//未优化版本
void bubblesort(vector<int> &list)
{
	int count = 0; //记录排序趟数
	for (int i = 0; i < list.size()-1; i++) {
		count++;
		for (int j = 0; j < list.size() - 1; j++) {
			if (list[j] > list[j + 1]) {
				swap(list[j], list[j + 1]);
			}
		}
	}
	cout << count << endl;
}


//优化版本
void bubblesort_flag(vector<int>& list)
{
	int count = 0; //记录排序趟数
	for (int i = 0; i < list.size() - 1; i++) {
		bool flag = false;	//记录该趟是否交换
		count++;
		for (int j = 0; j < list.size() - 1; j++) {
			if (list[j] > list[j + 1]) {
				flag = true;
				swap(list[j], list[j + 1]);
			}
		}
		if (!flag) {
			break;
		}
	}
	cout << count << endl;
}

