#pragma once
#include <iostream>
#include <map>
using namespace std;
class Eq {
private:
	int varnum;
public:
	class Var
	{
	private:
		int idx;
	public:
		Var(int idx) : idx(idx) {};
		int getIndex() const { return idx; }
	};

	Eq() :varnum(0) {};
	Var getVar() { return Var(varnum++); }

	class Exp {
	private:
		map<int, double> e;
	public:
		Exp() = default;
		Exp(const Var& x, double d = 1) { e[x.getIndex()] = d; }
		//Exp& operator+(const Var&x) { e[x.getIndex] ++; }
		//Exp& operator+=(const Var&x) { e[x.getIndex] ++; return *this; }
		Exp(const Exp &e) = default;
		Exp& operator+=(const Exp&ae) {
			for (auto &x : ae.e) {
				e[x.first] += x.second;
			};
			return *this; 
		}
		void print() const {
			for (auto x : e) {
				cout << "+"<< x.second << "* x_" << x.first << " ";
			}
			cout << endl;
		}
	};
};

Eq::Exp operator*(double d, const Eq::Var &v) {
	return Eq::Exp(v, d);
}
