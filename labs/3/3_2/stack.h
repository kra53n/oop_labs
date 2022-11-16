#pragma once
#include <iostream>

template <class T>
class Stack
{
    struct StackElem
    {
        StackElem* nxt = nullptr;
        T val;
    };

    StackElem* head = nullptr;
public:
    Stack() : head(nullptr) {}

    ~Stack()
    {
        clear();
    }

    void append(T val)
    {
        StackElem* elem = new StackElem;
        elem->val = val;
        elem->nxt = head;
        head = elem;
    }

    void get_size()
    {
        int size = 0;
        for (StackElem* cur = head; cur != nullptr; cur = cur->nxt)
            size++;
        return size;
    }

    T peek(T val)
    {
        return head == nullptr ? 0 : head->val;
    }

    T pop()
    {
        if (head == nullptr)
            return 0;
        T val = head->val;
        StackElem* elem = head;
        head = elem->nxt;
        delete elem;
        return val;
    }

    void print()
    {
        int i = 0;
        for (StackElem* cur = head; cur != nullptr; cur = cur->nxt)
        {
            printf("[%d] ", i++);
            std::cout << cur->val << std::endl;
        }
    }

    void clear()
    {
        while (head)
        {
            StackElem* elem = head;
            head = head->nxt;
            delete elem;
        }
    }
};
