#include<iostream>
#include"binary_heap.hpp"
#include<time.h>

int main()
{
	int arr[10]{};
	//srand((int)time(0));
	binaryHeap<int> list;
	list.buildNode();
	for (int i = 0; i < 10; ++i)
		arr[i] = i;
	for (int t : arr)
		list.push(t);
	list.push(40);
	list.foreach();
	int temp{};
	list.pop(temp);
	list.foreach();
	list.pop(temp);
	list.foreach();
	std::cout << list.Size() << "\n";
	return 0;
}
