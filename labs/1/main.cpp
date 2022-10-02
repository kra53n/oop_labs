#include <iostream>
using namespace std;

#include "vector.h"

int main()
{
    Vector v;
    v.append(12);
    v.append(13);
    v.append(14);

    v << 15 << 16;

    for (int i = 0; i < v.get_size(); i++)
        printf("[%d] %d\n", i, v[i]);

    v.pop(2);

    cout << endl;
    for (int i = 0; i < v.get_size(); i++)
        printf("[%d] %d\n", i, v.peek(i));

    v.switch_odd_with_even_idxs();

    cout << endl;
    for (int i = 0; i < v.get_size(); i++)
        printf("[%d] %d\n", i, v.peek(i));

    v.sort(VECTOR_SORT_DECREMENTLY);

    cout << endl;
    for (int i = 0; i < v.get_size(); i++)
        printf("[%d] %d\n", i, v.peek(i));
}