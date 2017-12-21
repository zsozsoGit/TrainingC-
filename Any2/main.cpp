#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include <type_traits>
#include "Any2.h"
using namespace std;

constexpr unsigned fact(unsigned f) {
	return (f == 0 ? 1 : (f* fact(f - 1)));
}

template <typename T> int vicces(const T &t) {
	if constexpr (is_integral<T>::value) cout << "INT\n";
	else
		return 12;
	return 0;
}
int main() {
	unsigned x = fact(12);
	//if 
	cout << x << endl<< endl;
	cout << vicces(string("ddd"));
	{
		Any a(6), v(12.5), c(string("cicus")); 
		a = string("koret");
		cout << *(c.get<string>()) << endl;
	}
	system("pause");
	return 0;
}