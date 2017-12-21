#include <iostream>
#include <string>
#include <vector>
#include <type_traits>
using namespace std;

template<typename T, typename U> struct is_same2 {
	constexpr static bool value = false;
};

template <typename T> struct is_same2 <T, T>
{
	constexpr static bool value = true;
};
//
//template <> struct is_same2<char,char>
//{
//	constexpr static bool value = true;
//};

//template <typename T> struct is_integer : public is_same2<T, int > {};
template <typename T> using is_integer = is_same2<T, int >;

template <typename T> void printIt(const T &t) {
	static_assert(is_integral<T>::value, "Not an integral type.");
	cout << "integral  " << t << endl;
}
template<> void printIt<string>(const string &s) {
	cout << "string: " << s << endl;
}

//variadic template
template <typename T, typename... Args> T adder(T first, Args... args) {
	return first + adder(args...);
}
template <typename T> T adder(T the_one) {
	return the_one;
}

template <typename Head> void printList(const Head& gead) {
	cout << gead << endl;
}

template <typename Head, typename ... Tail>
void printList(const Head &head, const Tail& ... tail) {
	cout << head << ", ";
	printList(tail...);
}


template <typename Head, typename ... Tail>
void printList2(const Head &head, const Tail& ... tail) {
	cout << head;
	if constexpr (sizeof ... (tail) > 0) {
		cout << ", ";
		printList2(tail...);
	}
	else		cout << endl;
}


template <typename ... Args> bool containsZero(const Args&... args) {
	return ((args == 0) || ...);
	//return (args+ ...);
}
template <typename ... Args> auto squareSum(const Args&... args) {
	return (sqrrr(args) + ...);
	//return (args+ ...);
}

template <typename T> T sqrrr(T t) {
	return t * t;
}

template <typename T, typename ... Args > T squareSum2(T t, Args... args) {
	return sqrrr(t) + squareSum2(args...);
}

template <typename T > T squareSum2(T ts) {
	return sqrrr(ts);
}

void safe_printf(const char *s) {
	while (*s) {
		if (*s == '%') {
			if (*(s + 1) == '%') {
				++s;
			}
			else {
				throw "Missing arg";
 				return;
			}

		}
		cout << *s++;
	}
}

template <typename T, typename ...Args >
void safe_printf(const char * s, const T & value, Args ... args)
{
	while (*s) {
		if (*s == '%') {
			if (*(s + 1) == '%') {
				++s;
			}
			else {
				cout << value;
				safe_printf(s + 1, args...);
				return;
			}

		}
		cout << *s++;
	}
	throw "Extra parameter";
}
int main() {
	cout << is_integer<int>::value << endl;
	//	printIt("uff");
	printIt(string("uffstring"));
	printIt(11);
	cout << "-----------------------------------------------------" << endl;
	cout << adder(1, 23, 54, 6, 32) << endl;
	cout << adder(1, 23) << endl;
	cout << "-----------------------------------------------------" << endl;
	printList(1);
	printList(1, string("cica"));
	printList2(1, string("cica"), 1.2, 2, 333, "e", 'i');
	//vector<int> v{ 1,23,34 };
	//printList(vector<int>{ 1,23,4 });
	cout << "-----------------------------------------------------" << endl;
	cout << containsZero(1, 2, 3, 4, 5, 7, 8, 6, 50, 9, 10, 11);
	cout << "-----------------------------------------------------" << endl;
	cout << squareSum(2, 1, 0, 1, 1, 0) << endl;
	cout << squareSum(2, 1, unsigned('e'), 0, 1, 1, 0) << endl;
	cout << "-----------------------------------------------------" << endl;
	safe_printf("% alma%,%: % vagy %!%", "erett", "fa", 5, 2, 2.1,2);
		system("pause");
	return 0;
}