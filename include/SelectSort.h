#pragma once
#include <vector>

using namespace std;

void selectSort(vector<int>& list)
{
	
	for (int i = 0; i < list.size(); i++) {
		int min_index = i;		//��Сֵ����
		for (int j = i + 1; j < list.size(); j++) {
			if (list[j] < list[min_index]) {//�ҵ���Сֵλ��
				min_index = j;
			}
		}
		if (min_index != i) {//������λ����Сֵ
			swap(list[min_index], list[i]);
		}
	}
}