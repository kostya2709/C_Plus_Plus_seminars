#include <iostream>

template <typename T>
class C { C() = delete; };

template<typename T>
void f(T param) {
	C<T>();
}

template<typename T>
void f_ref(T& param) {
	C<T>();
}

void bar(char var[]) {
	std::cout << sizeof(var) << '\n';
}

template <typename T, size_t N>
constexpr size_t arraySize(T(&)[N]) {
	return N;	
}	


int main() {
	int y;
	std::cin >> y;
	constexpr int x = y;
	char city[x] = "Moscow";
	char* ptrToName = city;
	std::cout << sizeof(city) << '\n';
	std::cout << sizeof(ptrToName) << '\n';
	bar(city);

//	f(city);
//	f_ref(city);

//	char new_city[arraySize(city)];
//	new_city[0] = 'a';
//	f_ref(new_city);
}


/*
template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept
{
	return N;
}
*/
