#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include "EQ.h"
using namespace std;
int main() {
	Eq eq;

	Eq::Var x = eq.getVar();
	Eq::Var y = eq.getVar();
	Eq::Var z = eq.getVar();
	Eq::Exp e = x;
	e += y;
	e += x;
	e += 3 * z;
	eq.addEq(e, 4);
	//e += z*3;
	//Eq::Row r = eq.getRow();

	//Eq::Exp e;

	//e + x + 2*y;
	//r.set(e, 12);
	eq.solve();
	e.print();
	system("pause");
	return 0;
}