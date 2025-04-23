#include <tuple>

struct ExplicitTest {
	explicit ExplicitTest(int x) {}
};

struct ImplicitTest {
	ImplicitTest(int x) {}
};

std::tuple<int, int> foo_tuple0()
{
    return std::make_tuple(1, -1);
}


std::tuple<int, int> foo_tuple1()
{
    return {1, -1};
}

std::tuple<ImplicitTest, int> foo_tuple2()
{
    return {1, -1};
}

std::tuple<int, ImplicitTest> foo_tuple3()
{
    return std::make_tuple(1, -1);
}

std::tuple<int, ExplicitTest> foo_tuple3()
{
    return std::make_tuple(1, -1);
}

int main() {
	auto test0 = foo_tuple0();
	auto test1 = foo_tuple1();
	auto test2 = foo_tuple2();
	auto test3 = foo_tuple3();
}
