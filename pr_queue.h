#pragma once
using std::pair;

class pr_queue
{ 
	pair<pair<int, int>, int>* arr;
	int size;
	int arr_size;
	void shift_up(int pos);
	void shift_down(int pos);
	void push(pair<pair<int, int>, int>, int end);
public:
	pr_queue(int size);
	~pr_queue();
	pair<int, int> top();
	void push(pair<pair<int, int>, int>);
	void push(int, int, int);
	void pop();
	void balance(int pos);
	void clear();
	void printAsTree(int begin, int level);
	void printAsArray();
	bool empty();
};

