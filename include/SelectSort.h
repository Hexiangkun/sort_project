#pragma once
#include <vector>

using namespace std;

void selectSort(vector<int>& list)
{
	
	for (int i = 0; i < list.size(); i++) {
		int min_index = i;		//最小值索引
		for (int j = i + 1; j < list.size(); j++) {
			if (list[j] < list[min_index]) {//找到最小值位置
				min_index = j;
			}
		}
		if (min_index != i) {//交换首位和最小值
			swap(list[min_index], list[i]);
		}
	}
}