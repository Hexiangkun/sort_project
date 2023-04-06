#pragma once
#include <vector>

using namespace std;

void adjustHeap(vector<int>& list, int i, int length)
{
	//非叶子节点
	int notleafNodeVal = list[i];

	/*
	k的初始值为当前非叶子节点的左孩子索引
	k = 2 * k + 1表示再往左子节点找
	*/
	for (int k = i * 2 + 1; k < length; k = 2 * k + 1) {
		//如果k+1还在待调整的长度内，且右子树的值大于等于左子树的值
		//将k++，此时为当前节点的右孩子
		if (k + 1 < length && list[k] < list[k + 1]) {
			k++;
		}

		//如果孩子节点大于父节点
		if (list[k] > notleafNodeVal) {
			list[i] = list[k];//将当前节点赋值为孩子节点的值
			i = k;//将i赋值为孩子节点的索引，再看其孩子节点是否有比它大的
		}
		else {
			//从左至右，从下至上进行调整，只要上面的不大于，下面的必不大于
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