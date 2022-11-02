#include "stack.h"

int main()
{
	Stack<const char*> s;
	s.append("Igor");
	s.append("Semikin");
	s.append("Anatolievich");
	s.print();

	const char* nani = s.pop();
	printf("\ndigit %s", nani);

	nani = s.pop();
	printf("\ndigit %s", nani);

	nani = s.pop();
	printf("\ndigit %s", nani);
}