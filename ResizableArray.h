#pragma once

#include <algorithm>


template <typename T>
class ResizableArray {
private:
	T* arr;
	size_t capacity;
	size_t size;

public:
	ResizableArray() : arr(nullptr), capacity(0), size(0) {}

	~ResizableArray() {
		if (arr != nullptr) {
			delete[] arr;
		}
	}

	ResizableArray(const ResizableArray& obj) : arr(nullptr), capacity(0), size(0) {
		*this = obj;
	}

	ResizableArray& operator=(const ResizableArray& obj) {
		if (this != &obj) {
			clear();
			reserve(obj.capacity);
			copy(obj.arr, obj.arr + obj.size, arr);
			size = obj.size;
		}
		return *this;
	}

	void addItem(const T& obj) {
		if (size >= capacity) {
			resize();
		}
		arr[size++] = obj;
	}

	void removeItem(const T& obj) {
		auto it = find(arr, arr + size, obj);
		if (it != arr + size) {
			copy(it + 1, arr + size, it);
			size--;
		}
	}

	size_t getSize() const {
		return size;
	}

    T* getArray() const {
		return arr;
	}

private:
	void resize() {
		if (capacity == 0) {
			capacity = 1;
		}
		else {
			capacity *= 2;
		}
		T* newArr = new T[capacity];
		copy(arr, arr + size, newArr);
		delete[] arr;
		arr = newArr;
	}

	void clear() {
		delete[] arr;
		arr = nullptr;
		capacity = 0;
		size = 0;
	}

	void reserve(size_t newCapacity) {
		if (newCapacity > capacity) {
			T* newArr = new T[newCapacity];
			copy(arr, arr + size, newArr);
			delete[] arr;
			arr = newArr;
			capacity = newCapacity;
		}
	}
};