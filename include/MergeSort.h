#pragma once
#include <vector>

using namespace std;

void Merge(vector<int>& list, int left, int mid, int right)
{
	vector<int> temp(list);	//��ʱ����

	int i = left;//���������������
	int j = mid + 1;//�ұ�������������
	int k = left;	//ִ����ʱ���鵱ǰ����

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
		int mid = (left + right)/2;   //����
		MergeSort(list, left, mid); //�����ݹ�
		MergeSort(list, mid + 1, right);//���Ҳ�ݹ�
		Merge(list, left, mid, right);	//�ϲ�
	}
}