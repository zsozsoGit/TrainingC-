#ifndef  _ANY_H_
#define _ANY_H_
class Any {
private:
	struct placeholder
	{
		virtual ~placeholder()
		{

		}
	};

	template <typename T> struct holder : public placeholder {
		T *data;
		holder( const T&d)
		{
			data = new T;
			*data = d;
		}
		~holder()
		{
			delete data;
		}
	};
	
	placeholder * value;
		 
	public:
		template <typename T > Any(const T &d) : value(new holder<T>(d)){
			
		}
		~Any() { delete value; }

		template <typename T> Any& operator = (const T &d) {
			delete value;
			value = new holder <T>(d);

			return *this;
		}

		template <typename T> T* get() {
			holder<T>*h = dynamic_cast<holder<T>*> (value);
			if (h) return h->data;
			return 0;
		}


};
#endif
