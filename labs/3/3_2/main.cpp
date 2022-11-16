#include <iostream>

#include "stack.h"

int main()
{
	Stack<const char*> s1;
	s1.append("keep");
	s1.append("it");
	s1.append("please");
	s1.print();

	Stack<int> s2;
	s2.append(1);
	s2.append(2);
	s2.append(3);
	s2.print();
}