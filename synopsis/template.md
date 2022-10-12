# Шаблоны

Шаблон нельзя разносить (он реализуется в header файлах), так как он
не компилируется.

## шаблон функции

```cpp
template<class T>
void swap(T& a, t& b) {
	T c = a;
	a = b;
	b = c;
}

int main() {
	int x = 3, y = 2;
	swap(x, y);

	MyClass a. b;
	swap(a, b);
}
```

## шаблон класса

```cpp
template<class T>
class A {
	T data;

public:
	T some_method(T x, T A) {
		// ...
	}
}
```

## использование нескольких классов

```cpp
template<class T, class K>
class B {
	// ...
}
```

## шаблон массива

```cpp
// array.h

template <class T>
class Array {
	T* arr;
	int size;
	
public:
	Array(int size) : size(size) {
		arr = new T[size];
	}
	T& operator[](int idx) {
		return arr[idx];
	}
}

// array.cpp

int main() {
	Array<float> arr1;
	arr1[0] = 1.2f;
	
	Array<Student> arr2;
	arr2[0] = { ... };
}
```
