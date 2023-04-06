# 排序算法合集

### 排序

| 排序算法                              | 平均时间复杂度        | 最差时间复杂度        | 空间复杂度          | 数据对象稳定性       |
| ------------------------------------- | --------------------- | --------------------- | ------------------- | -------------------- |
| [冒泡排序](Algorithm/BubbleSort.h)    | O(n<sup>2</sup>)      | O(n<sup>2</sup>)      | O(1)                | 稳定                 |
| [选择排序](Algorithm/SelectionSort.h) | O(n<sup>2</sup>)      | O(n<sup>2</sup>)      | O(1)                | 数组不稳定、链表稳定 |
| [插入排序](Algorithm/InsertSort.h)    | O(n<sup>2</sup>)      | O(n<sup>2</sup>)      | O(1)                | 稳定                 |
| [快速排序](Algorithm/QuickSort.h)     | O(n*log<sub>2</sub>n) | O(n<sup>2</sup>)      | O(log<sub>2</sub>n) | 不稳定               |
| [堆排序](Algorithm/HeapSort.cpp)      | O(n*log<sub>2</sub>n) | O(n*log<sub>2</sub>n) | O(1)                | 不稳定               |
| [归并排序](Algorithm/MergeSort.h)     | O(n*log<sub>2</sub>n) | O(n*log<sub>2</sub>n) | O(n)                | 稳定                 |
| [希尔排序](Algorithm/ShellSort.h)     | O(n*log<sup>2</sup>n) | O(n<sup>2</sup>)      | O(1)                | 不稳定               |
| [计数排序](Algorithm/CountSort.cpp)   | O(n+m)                | O(n+m)                | O(n+m)              | 稳定                 |
| [桶排序](Algorithm/BucketSort.cpp)    | O(n)                  | O(n)                  | O(m)                | 稳定                 |
| [基数排序](Algorithm/RadixSort.h)     | O(k*n)                | O(n<sup>2</sup>)      |                     | 稳定                 |

> - 均按从小到大排列
> - k：代表数值中的 “数位” 个数
> - n：代表数据规模
> - m：代表数据的最大值减最小值

### 冒泡排序

- 基本思想：通过对待排序的序列从前向后依次比较相邻元素的值，如果发现逆序则交换位置。

  ps：逆序——从小到大排序，元素大的在前，元素小的在后就是逆序

- 代码

```C++
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
```

- 时间复杂度
  1. 如果原数组有序，则遍历一次即可，最好的时间复杂度为O(n)
  2. 如果原数组无序，则比较次数是：(n-1)+(n-2)+.....+2+1=(n-1)n/2=O(n<sup>2</sup>)

- 稳定性——稳定

### 选择排序

- 基本思想：从数组中找到一个最大值（最小值）与序列的末尾（首位）进行交换，再从剩下的序列（除掉序列的末尾或者首位）中找到次最大值（最小值）再进行交换，以此类推，直到完成排序。
- 代码

```C++
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
```

- 时间复杂度
  1. 比较次数和关键字的初始状态无关
  2. 总比较次数为(n-1)+(n-2)+.....+2+1=(n-1)*n/2，
  3. 故时间复杂度为O(n<sup>2</sup>)
- 稳定性——不稳定

### 直接插入排序

- 基本思想：将待排序序列分为两个序列，前面序列保持有序，依次选取后面元素插入到有序序列中。

- 代码

```C++
void insertSort(vector<int>& list)
{
	for (int i = 1; i < list.size(); i++) {
		int temp = list[i];//待插入元素
		int index = i - 1;//初始为前一个元素
		while (index >= 0 && list[index] > temp) {
            //index合法，前面的元素比待插入元素大
			list[index + 1] = list[index];//每当前面的元素比待插入元素大，就向后移动
			index--;
		}
		list[index + 1] = temp;//找到插入位置
	}
}
```

- 时间复杂度
  1. 如果元素有序，每趟只需与前面的有序元素序列最后一个元素进行比较，比较n-1次，元素移动次数为0。时间复杂度为O(n)
  2. 如果元素没有序，时间复杂度为O(n<sup>2</sup>)

- 稳定性——稳定

### 希尔排序

- 基本思想：把序列按下标的一定增量分组，每个分组使用直接插入排序；随着增量的减少，每组包含的关键词越来越多，当增量减少为1的时候，整个序列被分为一组，算法终止
- 代码

```C++
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
```

- 时间复杂度O(n*log<sup>2</sup>n)
- 稳定性——不稳定

### 归并排序

- 基本思想
  1. 将序列一次次分成子序列，直到子序列长度为1
  2. 再将已有序的子序列合并，得到完全有序的序列

- 代码

```C++
void Merge(vector<int>& list, int left, int mid, int right)
{
	vector<int> temp(list);	//临时数组

	int i = left;//左边有序序列索引
	int j = mid + 1;//右边有序序列索引
	int k = left;	//执行临时数组当前索引

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
		int mid = (left + right)/2;   //划分
		MergeSort(list, left, mid); //对左侧递归
		MergeSort(list, mid + 1, right);//对右侧递归
		Merge(list, left, mid, right);	//合并
	}
}
```

- 时间复杂度：归并排序是按照分层进行比较的，会分为log<sub>2</sub>n层；每一层需要比较次数为O(n);故时间复杂度为O(nlog<sub>2</sub>n)
- 稳定性——稳定

### 快速排序

- 基本思想：任取序列中的一个元素作为中心（枢轴）元素；将所有比枢轴大的元素放到其右边，将所有比枢轴小的元素放到其左边，形成左右两个子序列；再对两个子序列分别进行上述算法进行排序，直到每个子序列只剩下一个元素。
- 分治法
- 代码

原始快排

```C++
int partition(vector<int>& list, int left, int right)
{
	srand(time(nullptr));
	int random = rand() % (right - left + 1) + left;
	swap(list[random], list[left]);//随机划分枢轴

	int pivot = list[left];

	while (left < right) {
		while (left<right && list[right]>pivot) {//从右边找一个比枢轴小的元素
			right--;
		}
		list[left] = list[right];
		while (left < right && list[left] < pivot) {//从左边找一个比枢轴大的元素
			left++;
		}
		list[right] = list[left];
	}
	list[left] = pivot;//left和right相等，将枢轴元素赋值
	return left;//返回中间元素索引
}

void quicksort(vector<int>& list,int left, int right)
{
	if (left < right) {
		int pos = partition(list, left, right);
		quicksort(list, left, pos - 1);
		quicksort(list, pos + 1, right);
	}
}
```

三路快排

```C++
void QuickSort(vector<int>& list, int left, int right)
{
	if (left < right) {
		srand(time(nullptr));
		int random = rand() % (right - left + 1) + left;
		swap(list[random], list[left]);
		int pivot = list[left];

		int l = left;
		int i = left + 1;
		int r = right;
		while (i <= r) {
			if (list[i] < pivot) {
				swap(list[i], list[l]);
				i++;
				l++;
			}
			else if(list[i]==pivot)
			{
				i++;
			}
			else {
				swap(list[i], list[r]);
				r--;
			}
		}
		QuickSort(list, left, l - 1);
		QuickSort(list, r + 1, right);
	}
}

```

- 时间复杂度
  1. 最坏情况下：逆序为O(n<sup>2</sup>)
  2. 平均时间复杂度为O(n*log<sub>2</sub>n)

- 稳定性——不稳定

### 堆排序

- 堆（完全二叉树）
  1. 大顶堆：每个节点的值大于或等于其左右孩子节点的值
  2. 小顶堆：每个节点的值小于或等于其左右孩子节点的值

- 基本思想
  1. 将待排序序列构建成一个大顶堆，那么，整个序列的最大值就是堆的根节点
  2. 将堆顶元素和完全二叉树最后一个元素交换，那么末尾元素就存入了最大值
  3. 将剩余n-1个元素重新构建成大顶堆，重复上述操作

- 代码

```C++
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
	for (int i = n - 1; i >= 0; i--) {
		swap(list[i], list[0]);
		adjustHeap(list, 0, i);
	}
}
```

- 时间复杂度
  1. 建初始堆，复杂度为O(n)
  2. 交换操作次数为n-1次
  3. 重建堆的过程时间复杂度近似为O(n*log<sub>2</sub>n)
  4. 堆排序的时间复杂度为O(n*log<sub>2</sub>n)

- 稳定性——不稳定

### 基数排序

- 基本思想：将整数按位数切割成不同的数字，然后按每个位数分别比较从而得到有序的序列
- 时间复杂度：O(n)
- 稳定性——稳定
