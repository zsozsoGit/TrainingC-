#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
using namespace std;
void doIt2(int &i) {
	cout << "lvalue" << endl;
}
void doIt2(int &&i) {
	cout << "rvalue" << endl;
}
template <typename T> void doIt(T &&d)
{
	d++;
	//doIt2((d));
	doIt2(forward<T>(d));
	cout << "Done: " << d << endl;

}

void doIt3(int &&i) {
	cout << "doit3 "<< i << endl;
}
int main() {

	doIt(7);
	int i = 5;
	doIt3((i));
	cout << i << endl;
	system("pause");
	return 0;
}