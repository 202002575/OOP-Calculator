#pragma once

template<typename T>
class Stack {
private:
	const int DEFAULT_CAPACITY = 100;
	int size, capacity;
	T* stack;
public:
	int getSize() {
		return size;
	}
	bool isFull() {
		return (size == capacity);
	}
	bool isEmpty() {
		return (size == 0);
	}
	T pop() {
		if (isEmpty()) {
			return NULL;
		}
		return stack[size--];
	}
	T peek() {
		if (isEmpty()) {
			return NULL;
		}
		return stack[size];
	}
	bool push(T element) {
		if (isFull()) {
			return false;
		}
		stack[++size] = element;
	}
	Stack(int newCapacity = DEFAULT_CAPACITY) {
		this->capacity = newCapacity;
		stack = new T[this->capacity];
		size = 0;
	}
};