#pragma once
#include <vector>
using namespace std;

void insertSort(vector<int>& list)
{
	for (int i = 1; i < list.size(); i++) {
		int temp = list[i];//������Ԫ��
		int index = i - 1;//��ʼΪǰһ��Ԫ��
		while (index >= 0 && list[index] > temp) {//index�Ϸ���ǰ���Ԫ�رȴ�����Ԫ�ش�
			list[index + 1] = list[index];
			index--;
		}
		list[index + 1] = temp;//�ҵ�����λ��
	}
}