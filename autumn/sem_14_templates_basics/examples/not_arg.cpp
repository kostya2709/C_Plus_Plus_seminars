/*
template <typename T>
T foo() {
	return 1;
}
*/

template <typename T>
int bar() {
	return 1;
}

template <typename T>
float bar() {
	return 1.0;
}

/*
int func() {
	return 1;
}

float func() {
	return 1.0;
}
*/


int main() {


//	foo();
//	foo<int>();
//	foo<double>();

//	bar<int>();
	((int(*)())bar<int>)();
	((float(*)())bar<float>)();

	//	func();
//	((int(*)())func)();
}
