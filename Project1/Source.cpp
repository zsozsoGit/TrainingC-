#include <iostream>

using namespace std;

extern "C" {
	__declspec(dllimport) double dll_adder(double a, double b	);
}
int main() {

	cout << dll_adder(23, 324) << endl;;
	system("pause");
	return 0;
}