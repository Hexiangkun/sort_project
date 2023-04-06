#pragma once
#include <vector>

using namespace std;

void adjustHeap(vector<int>& list, int i, int length)
{
	//��Ҷ�ӽڵ�
	int notleafNodeVal = list[i];

	/*
	k�ĳ�ʼֵΪ��ǰ��Ҷ�ӽڵ����������
	k = 2 * k + 1��ʾ�������ӽڵ���
	*/
	for (int k = i * 2 + 1; k < length; k = 2 * k + 1) {
		//���k+1���ڴ������ĳ����ڣ�����������ֵ���ڵ�����������ֵ
		//��k++����ʱΪ��ǰ�ڵ���Һ���
		if (k + 1 < length && list[k] < list[k + 1]) {
			k++;
		}

		//������ӽڵ���ڸ��ڵ�
		if (list[k] > notleafNodeVal) {
			list[i] = list[k];//����ǰ�ڵ㸳ֵΪ���ӽڵ��ֵ
			i = k;//��i��ֵΪ���ӽڵ���������ٿ��亢�ӽڵ��Ƿ��б������
		}
		else {
			//�������ң��������Ͻ��е�����ֻҪ����Ĳ����ڣ�����ıز�����
			break;
		}
	}
	list[i] = notleafNodeVal;
}

void HeapSort(vector<int>& list)
{
	int n = list.size();
	for (int i = n / 2 - 1; i >= 0; i--) {
		adjustHeap(list, i, n);
	}
	for (int i = n - 1; i > 0; i--) {
		swap(list[i], list[0]);
		adjustHeap(list, 0, i);
	}
}