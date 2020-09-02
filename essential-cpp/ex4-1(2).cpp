#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Stack {
public:
	bool push(const string&);
	bool pop(string& elem);
	bool peek(string& elem);
	bool find(string& elem);

	int count(string& elem);

	bool empty();
	bool full();

	int size() { return _stack.size(); }

private:
	vector<string> _stack;
};

inline bool
Stack::empty() {
	return _stack.empty();
}

inline bool
Stack::full() {
	return _stack.size() == _stack.max_size();
}

#include "stack.h"

bool Stack::pop(string& elem) {
	if (empty()) {
		return false;
	}
	elem = _stack.back();
	_stack.pop_back();
	return true;
}

bool Stack::push(const string& elem) {
	if (full()) {
		return false;
	}
	_stack.push_back(elem);
	return true;
}

bool Stack::peek(string& elem) {
	if (empty()) {
		return false;
	}
	elem = _stack.back();
	return true;
}

bool Stack::find(string& elem) {
	if (empty()) {
		return false;
	}
	for (auto i : _stack) {
		if (i == elem) {
			return true;
		}
	}
	return false;
}

int Stack::count(string& elem) {
	int sum = 0;
	for (auto i : _stack) {
		if (i == elem) {
			sum++;
		}
	}
	return sum;
}