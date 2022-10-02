#include <time.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#include "vector.h"

Vector::Vector()
{
}

Vector::~Vector()
{
    delete data;
}

void Vector::fill_randomly(int size, int min, int max)
{
    clear();
    srand(time(0));
    this->size = size;
    data = new int[size];

    for (int i = 0; i < size; i++)
        data[i] = min + rand() % (max - min);
}

void Vector::fill_from_file(const char* filename)
{
    clear();
    FILE* f;
    if (fopen_s(&f, filename, "r"))
    {
        printf("\nMan, this is fatal error. Dont worry!");
    }
}

void Vector::sort(int by)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - 1; j++)
        {
            bool cond;
            switch (by)
            {
            case VECTOR_SORT_INCREMENTLY: cond = data[j] < data[j+1]; break;
            case VECTOR_SORT_DECREMENTLY: cond = data[j] > data[j+1]; break;
            }
            if (cond)
                continue;
            int tmp = data[j];
            data[j] = data[j+1];
            data[j+1] = tmp;
            swapped = true;
        }
        if (!swapped)
            break;
    }
}

void Vector::switch_odd_with_even_idxs()
{
    for (int i = 0; i < size; i++)
    {
        if (i % 2)
        {
            int tmp = data[i];
            data[i] = data[i-1];
            data[i-1] = tmp;
        }
    }
}

void Vector::append(int elem)
{
    int* new_data = new int[++size];
    for (int i = 0; i < size - 1; i++)
        new_data[i] = data[i];
    new_data[size-1] = elem;
    delete data;
    data = new_data;
}

int Vector::pop(int idx = -1)
{
    int* new_data = new int[--size];
    int elem = data[idx < 0 or idx > size ? size : idx];

    for (int i = 0, off = 0; i < size; i++)
    {
        if (i == idx)
            off++;
        new_data[i] = data[i+off];
    }
    delete data;
    data = new_data;

    return elem;
}

int Vector::peek(int idx)
{
    return idx < size and idx >= 0 ? data[idx] : INT_MIN;
}

int Vector::get_size()
{
    return size;
}

void Vector::clear()
{
    if (!data)
        return;
    delete data;
    size = 0;
    data = 0;
}

Vector& Vector::operator<<(int elem)
{
    append(elem);
    return *this;
}

int Vector::operator[](int idx)
{
    return peek(idx);
}

bool Vector::operator==(Vector& vector)
{
    if (size != vector.size)
        return false;
    for (int i = 0; i < get_size(); i++)
        if (peek(i) != vector.peek(i))
            return false;
    return true;
}

bool Vector::operator!=(Vector& vector)
{
    return not (*this == vector);
}
