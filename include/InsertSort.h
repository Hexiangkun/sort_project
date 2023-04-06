#pragma once
#include <vector>
using namespace std;

void insertSort(vector<int>& list)
{
	for (int i = 1; i < list.size(); i++) {
		int temp = list[i];//待插入元素
		int index = i - 1;//初始为前一个元素
		while (index >= 0 && list[index] > temp) {//index合法，前面的元素比待插入元素大
			list[index + 1] = list[index];
			index--;
		}
		list[index + 1] = temp;//找到插入位置
	}
}