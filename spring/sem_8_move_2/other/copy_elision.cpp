#include <iostream>

struct Test {
	Test() {
		std::cout << "Test()\n";
	}

	Test(const Test&) {
		std::cout << "Test(const Test&)\n";
	}
	
	Test(Test&&) {
		std::cout << "Test(Test&&)\n";
	}
};

Test RVO() {
	return Test(); 
}

Test NRVO() {
	//...
	Test test;
	//...
	return test; 
}

Test noRVO() {
	return std::move(Test()); 
}

Test foo(Test test) {
	return test;
}

Test bar(Test&& test) {
	return std::move(test);
}

int main() {

	std::cout << "1\n";
	Test test = Test();
	
	std::cout << "\n2\n";
	Test test2 = std::move(Test());
	
	std::cout << "\n3\n";
	Test test3 = RVO();
	
	std::cout << "\n4\n";
	Test test4 = NRVO();
	
	std::cout << "\n5\n";
	Test test5 = noRVO();
	
	std::cout << "\n6\n";
	Test test6 = Test(Test(Test(Test())));
	
	std::cout << "\n7\n";
	Test test7 = foo(test6);
	
	std::cout << "\n8\n";
	Test test8 = bar(std::move(test7));

}
