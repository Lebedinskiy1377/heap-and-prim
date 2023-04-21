#include <iostream>
#include "pr_queue.h"

using std::make_pair;

void pr_queue::shift_up(int pos)
{
	int prev = (pos-1)/2;
	if (prev >= 0 and pos > 0) {
		if (arr[pos].second < arr[prev].second)
			std::swap(arr[pos], arr[prev]);
		pos = prev;
		prev = (pos - 1) / 2;
		shift_up(pos); 
	}
}

void pr_queue::shift_down(int pos)
{
	int prev = (pos-1)/2;
	if (prev > 0 and pos > 0) {
		if (arr[pos].second > arr[prev].second)
			std::swap(arr[arr_size], arr[prev]);
		pos = prev;
		prev = (pos - 1) / 2;
		shift_down(pos);
	}
}

pr_queue::pr_queue(int size)
{
	this->size = size;
	arr = new std::pair<std::pair<int,int>, int>[size];
	arr_size = 0;
}

pr_queue::~pr_queue()
{
	clear();
}

pair<int, int> pr_queue::top()
{
	return arr->first;
}

void pr_queue::push(pair<pair<int, int>, int> value)
{
	push(value, arr_size);
}

void pr_queue::push(int v, int w, int weight) {
	push(make_pair(make_pair(v, w), weight));
}

void pr_queue::push(pair<pair<int, int>, int> value, int end)
{ 
	arr[end] = value;
	shift_up(end);
	++arr_size;
}

void pr_queue::pop()
{
	for (int i = 0; i < arr_size-1; ++i)
		arr[i] = arr[i + 1];
	--arr_size;
}

void pr_queue::balance(int pos)
{
	int l = 2 * pos + 1;
	int r = 2 * pos + 2;
	if (l < arr_size)
		if (arr[pos] > arr[l]) {
			std::swap(arr[pos], arr[l]);
			balance(l);
		}
	if (r < arr_size)
		if (arr[pos] > arr[r]) {
			std::swap(arr[pos], arr[r]);
			balance(r);
		}
}

void pr_queue::clear()
{
	arr_size = 0;
}

void pr_queue::printAsTree(int begin, int level)
{
		if (begin < arr_size) {
			printAsTree(2 * begin + 2, level +1);
			for (int i = 0; i < level; i++) {
				std::cout << "    ";
			} 
			std::cout << arr[begin].second << '\n';
			printAsTree(2*begin + 1, level + 1);
		}
}

void pr_queue::printAsArray()
{
	for (int i = 0; i < arr_size; ++i)
		std::cout << arr[i].second << ' ' << "->" << ' ' << "[" << arr[i].first.first << ' ' << arr[i].first.second << "];\n";
}

bool pr_queue::empty()
{
	return arr_size == 0;
}

//arr[i] = i[arr]