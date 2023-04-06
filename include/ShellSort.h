#pragma once
#include <vector>

using namespace std;

void shellSort(vector<int>& list)
{
	int n = list.size();
	//进行分组，最开始时增量为数组的一半
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {			//直接插入排序
			int temp = list[i];
			int index = i - gap;
			while (index >= 0 && list[index] > temp) {
				list[index + gap] = list[index];
				index -= gap;
			}
			list[index + gap] = temp;
		}
	}
}