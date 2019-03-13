#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void printPQ(priority_queue<int> &pq) {
	while (pq.size() > 0)
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

int main() {
	priority_queue<int> pq1;//default, 最大值优先级队列
	priority_queue<int, vector<int>, less<int>> pq2;//less<>预定义好的函数对象, 最大值优先级队列
	priority_queue<int, vector<int>, greater<int>> pq3;//最小值优先级队列

	cout << "===test maxmium priority===" << endl;
	pq1.push(22);
	pq1.push(44);
	pq1.push(99);
	pq1.push(55);
	pq1.push(11);

	cout << "head element:" << pq1.top() << endl;
	cout << "queue size:" << pq1.size() << endl;
	printPQ(pq1);

	cout << endl;
	cout << "===test minmium priority===" << endl;
	pq3.push(22);
	pq3.push(44);
	pq3.push(99);
	pq3.push(55);
	pq3.push(11);

	cout << "head element:" << pq3.top() << endl;
	cout << "queue size:" << pq3.size() << endl;
	while (pq3.size() > 0)
	{
		cout << pq3.top() << " ";
		pq3.pop();
	}
	cout << endl;


	cout << "hello..." << endl;
	system("pause");
	return 0;
}
