#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <iostream>

//template <class T>
//vec<T>::vec(const vec& v)
//{
//    size = 0;
//    delete[] data;
//    for (int i = 0; i < v.size; i++)
//        append(v[i]);
//}
//
//template <class T>
//vec<T>::~vec()
//{
//    delete[] data;
//    size = 0;
//}
//
//template <class T>
//void vec<T>::append(double val)
//{
//    T* new_data = new T[++size];
//    for (int i = 0; i < size - 1; i++)
//        new_data[i] = data[i];
//    new_data[size-1] = val;
//    delete[] data;
//    data = new_data;
//}
//
//template <class T>
//double vec<T>::pop(int idx = -1)
//{
//    double* new_data = new double[--size];
//    double elem = data[idx < 0 && idx > size ? size : idx];
//
//    for (int i = 0, off = 0; i < size; i++)
//    {
//        if (i == idx)
//            off++;
//        new_data[i] = data[i+off];
//    }
//    delete[] data;
//    data = new_data;
//
//    return elem;
//}
//
//template <class T>
//T& vec<T>::peek(int idx) const
//{
//    if (idx >= size || -size > idx)
//        throw std::out_of_range("index > size");
//    if (idx < 0)
//        idx = size + idx;
//    return data[idx];
//}
//
//template <class T>
//double vec<T>::get_size() const
//{
//    return size;
//}
//
//template <class T>
//double vec<T>::get_len() const
//{
//    double sum = 0;
//    for (double i = 0; i < get_size(); i++)
//        sum += (*this)[i] * (*this)[i];
//    return sqrt(sum);
//}
//
//template <class T>
//void vec<T>::print() const
//{
//    std::cout << std::endl;
//    for (int i = 0; i < get_size(); i++)
//        std::cout << "[" << i << "] " << this->peek(i) << std::endl;
//    std::cout << std::endl;
//}
//
//template <class T>
//void vec<T>::clear()
//{
//    if (!data)
//        return;
//    delete[] data;
//    size = 0;
//    data = 0;
//}
//
//template <class T>
//vec<T> const& vec<T>::operator=(vec const& v)
//{
//    size = 0;
//    delete[] data;
//    data = new T[v.size];
//    for (int i = 0; i < v.size; i++)
//        this->append(v[i]);
//    return *this;
//}
//
//template <class T>
//vec<T>& vec<T>::operator<<(double elem)
//{
//    append(elem);
//    return *this;
//}
//
//template <class T>
//double& vec<T>::operator[](int idx) const
//{
//    return peek(idx);
//}
//
//template <class T>
//bool vec<T>::operator==(vec& v)
//{
//    return get_len() == v.get_len();
//}
//
//template <class T>
//bool vec<T>::operator!=(vec& v)
//{
//    return !(*this == v);
//}
//
//template <class T>
//bool vec<T>::operator<(vec& v)
//{
//    return get_len() < v.get_len();
//}
//
//template <class T>
//bool vec<T>::operator>(vec& v)
//{
//    return get_len() > v.get_len();
//}
//
//template <class T>
//bool vec<T>::operator==(T val)
//{
//    return get_len() == val;
//}
//
//template <class T>
//bool vec<T>::operator!=(T val)
//{
//    return get_len() != val;
//}
//
//template <class T>
//bool vec<T>::operator<(T val)
//{
//    return get_len() < val;
//}
//
//template <class T>
//bool vec<T>::operator>(T val)
//{
//    return get_len() > val;
//}
//
//template <class T>
//bool operator==(T val, vec<T> const& v)
//{
//    return val == v.get_len();
//}
//
//template <class T>
//bool operator!=(T val, vec<T> const& v)
//{
//    return val != v.get_len();
//}
//
//template <class T>
//bool operator<(T val, vec<T> const& v)
//{
//    return false;
//}
//
//template <class T>
//bool operator>(T val, vec<T> const& v)
//{
//    return val > v.get_len();
//}
//
//template <class T>
//std::ostream& operator<<(std::ostream& out, vec<T> const& v)
//{
//    for (int i = 0; i < v.size; i++)
//        out << " " << v[i] << " ";
//    return out;
//}
//
//template <class T>
//std::istream& operator>>(std::istream& in, vec<T>& v)
//{
//    for (double i = 0; i < v.size; i++)
//        in >> v[i];
//    return in;
//}
//
//template <class T>
//vec<T> vec<T>::operator+(vec const& v) const
//{
//    vec other;
//    int tmp_size = size > v.size ? size : v.size;
//    for (int i = 0; i < tmp_size; i++)
//    {
//        T val = 0;
//        if (i < size)
//            val += peek(i);
//        if (i < v.size)
//            val += v[i];
//        other << val;
//    }
//    return other;
//}
//
//template <class T>
//vec<T> operator+(vec<T> const& v, T val)
//{
//    vec other;
//    for (int i = 0; i < v.size; i++)
//        other << v[i] + val;
//    return other;
//}
//
//template <class T>
//vec<T> operator+(T val, vec<T> const& v)
//{
//    vec other;
//    for (int i = 0; i < v.size; i++)
//        other << v[i] + val;
//    return other;
//}
//
//template <class T>
//vec<T> vec<T>::operator*(vec const& v) const
//{
//    vec other;
//    int tmp_size = size > v.size ? size : v.size;
//    for (int i = 0; i < tmp_size; i++)
//    {
//        T val = 1;
//        if (i < size)
//            val *= peek(i);
//        if (i < v.size)
//            val *= v[i];
//        other << val;
//    }
//    return other;
//}
//
//template <class T>
//vec<T> operator*(vec<T> const& v, T val)
//{
//    vec other;
//    for (int i = 0; i < v.size; i++)
//        other << v[i] * val;
//    return other;
//}
//
//template <class T>
//vec<T> operator*(T val, vec<T> const& v)
//{
//    vec other;
//    for (int i = 0; i < v.size; i++)
//        other << v[i] * val;
//    return other;
//}
