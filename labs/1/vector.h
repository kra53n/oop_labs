#pragma once

enum VECTOR_SORTING { VECTOR_SORT_INCREMENTLY, VECTOR_SORT_DECREMENTLY };

class Vector
{
    int* data = 0;
    int size = 0;
public:
    Vector();
    ~Vector();

    void fill_randomly(int size, int min, int max);
    void fill_from_file(const char* filename);

    void sort(int by = VECTOR_SORT_INCREMENTLY);
    void switch_odd_with_even_idxs();

    void append(int elem);

    int pop(int idx);
    int peek(int idx);

    int get_size();

    void clear();

    Vector& operator<<(int elem);
    int operator[](int idx);
    bool operator==(Vector& vector);
    bool operator!=(Vector& vector);
};

