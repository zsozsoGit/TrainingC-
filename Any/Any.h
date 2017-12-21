#ifndef  _ANY_H_
#define _ANY_H_
#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <typeindex>
using namespace std;
namespace {
	template<typename T> void deleteAny(void *data) {
		delete static_cast<T*>(data);
		std::cout<< std::boolalpha <<std::is_integral<T>::value <<endl;
		std::cout << typeid(static_cast<T*>(data)).name() <<endl;
	}
}

class Any {
private:
	void * data;
	void(*deleter)(void*);
	type_index ti;
public:
	template <typename T > Any(const T &d):ti(type_index(typeid(T))) {
		data = new T;
		*static_cast<T*> (data) = d;
		deleter = deleteAny<T>;
		//ti = type_index(typeid(T));
	}
	~Any()
	{
		deleter(data);
	}

	template <typename T> Any& operator = (const T &t)
	{
		deleter(data);
		data = new T;
		*static_cast<T*> (data) = t;
		deleter = deleteAny<T>;
		ti = type_index(typeid(T));
		return *this;
	}
	template <typename T> T* get() {
		if (type_index(typeid(T)) == ti)
		{
			return static_cast<T*>(data);

		}
		return 0;
	}
};
#endif // ! _ANY_H_

