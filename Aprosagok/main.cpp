#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
using namespace std;

constexpr long double operator"" deg(long double d) {
	return d * 3.1415 / 180;
}

void operator"" _print(const char* str) {
	cout << str<< endl;
}
void operator"" _print(const char* str, size_t size) {
	cout << str << endl;
}

enum {alma, korte, szilva};
enum class Color:long{black, red, green};
int main() {
	//int a = alma;
	//Color b = Color::black;
	//auto c = Color::red;
	//cout <<static_cast<int> (c) << endl;
	//cout << 360.0deg << endl;
	//"alma"_print;
	//13_print;
	float f=0;
	int j=0;
	for (int i = 0; i < 1000000000; i++)
	{
		j++;
		f += 1.0f;
	}
	cout << "float\t" << f << endl;
	cout << "int\t" << j << endl;
	cout << "uff\t" << static_cast<float>(1000000000) << endl;
	system("pause");
	return 0;
}