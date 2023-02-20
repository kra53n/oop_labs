#include <iostream>
using namespace std;

int main() {
  list<float> a = list<float>();
  // begin -> list<float>::iterator
  for (auto i = a.begin(); i != a.end; i++) {
	cout << *i << endl;
  }
}
