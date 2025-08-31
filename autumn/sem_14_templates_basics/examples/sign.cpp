
template <typename T>
void foo(T a) {

}

template <typename T>
int foo(T b) {
	return 0;
}

int main() {
	((int(*)(int))foo)(1);
}
