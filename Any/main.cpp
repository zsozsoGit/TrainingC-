#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include "Any.h"
using namespace std;
int main() {
	{
		Any a(1), b(12.2) ,c(string("cica"));
		c = string("alma");
		cout << *(a.get<string>()) << endl;
	}
	system("pause");
	return 0;
}