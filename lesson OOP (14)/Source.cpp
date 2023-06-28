// Шаблонные классы. Если понадобиться длительное действие программы.
// Шаблонные классы. Знаем как работать, но не знаем с чем будем работать.

// Типы шаблонoв.
// Определёнными количеством аргументов.
// Не определёнными количеством аргументов (Variadic, Template). Tuple - кортедж.
// Не определённый аргумент. ] Передаёться типы данных. Аргумент параметров.
// Вычесляеммый аргумент. ] Передаёться типы данных. Аргумент параметров.

#include <iostream>
#include <array>

template <typename Type, const int _size>
class MyClass
{
public:
	
	/*MyClass() : _data(nullptr), _size (0)
	{

	}*/
	
// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	// Нужно выбрать из двух видов операторов, для дальнейшего создание функций.
	Type &operator[](int i)
	{
		return data_[i];
	}

	const Type& operator[](int i) const
	{
		return data_[i];
	}

	auto at(int i) -> Type&
	{
		return data_[i];
	}

	auto at(int i) const -> const Type&
	{
		return data_[i];
	}

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	int size()const
	{
		return size_;
	}

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	class iterator
	{
	public:
		iterator() = delete;
		iterator(Type* data) : data_(data) {}

		iterator& operator++()
		{
			data_++;
			return *this;
		}

		iterator& operator++(int)
		{
			iterator tmp(*this);
			data_++;
			return tmp;
		}

		bool operator==(const iterator &obj)const
		{
			return this->data_ == obj.data_;
		}

		bool operator!=(const iterator& obj)const
		{
			return ! this->operator==(obj);
			// Такой стиль применим если условия проверки содержат сложные условия или вызовы функций.
		}

		Type& operator*()
		{
			return *data_;
		}

	private:
		Type *data_;
	};

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	iterator begin()
	{
		return iterator(data_);
	}

	iterator end()
	{
		return iterator(data_ + size_);
	}

private:
	Type data_ [ _size ];
	const int size_ { _size };
};

void f01(MyClass <int , 10> a)
{
	// MyClass <int, 10> obj(a);
	for (size_t i = 0; i < a.size(); ++i)
	{
		std::cout << a[i] << " ";
	}
}

int main()
{
	MyClass <int, 10> a;
	for (size_t i = 0; i < a.size(); ++i)
	{
		a[i] = i + 1;
	}

	f01(a);

	std::cout << std::endl;

	int arr[10];

	for (size_t i = 0; i < std::size(arr); ++i)
	{
		arr[i] = i + 1;
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;

	for (int &el : arr) 
	{
		std::cout << el << " ";
	}

	std::cout << std::endl;

	std::array <int, 10> arrObj;
	for (size_t i = 0; i < std::size(arrObj); ++i)
	{
		arrObj[i] = i + 19;	
	}

	std::cout << std::endl;

	for (const auto& el : arrObj)
	{
		std::cout << el << " ";
	}

	std::cout << std::endl;

	for (std::array <int, 10>::iterator it = arrObj.begin(); it != arrObj.end(); ++it)
	{
		const auto& el = *it;
		std::cout << el << " ";
	}

	std::cout << std::endl;

	for (const auto& el : a)
	{
		std::cout << el << " ";
	}

	std::cout << std::endl;

	return {};
}