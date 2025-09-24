#pragma once
template <class T>
class Array {
protected:
	T* data;
	int capacity;

public:
	~Array() { if (data) delete[] data; }

	Array() : data(0) { }
	Array(int capacity) {
		data = new T[this->capacity = capacity];
	}
	Array(const Array& source) {
		data = new T[this->capacity = source.capacity];
		copy(source.data);
	}

protected:
	void copy(T* values);

public:
	int Capacity() const { return capacity; }
	T& ElementAt(int index) { return data[index]; }
	
	T& operator[](int index) { return data[index]; }
	Array& operator=(const Array& source) {
		if (data) delete[] data;
		data = new T[this->capacity = source.capacity];
		copy(source.data);

		return *this;
	}
public:
	T* begin() { return data; }
	T* end() { return data + capacity; }
};

template<class T>
inline void Array<T>::copy(T* values) {
	for (int i = 0; i < capacity; i++) {
		data[i] = values[i];
	}
}
