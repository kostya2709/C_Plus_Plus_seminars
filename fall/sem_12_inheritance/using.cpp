#include <iostream>

class Base {
public:
  void f(char x) {
	std::cout << "Base::f(double)\n";
  }
};

class Derived : public Base {
public:
	// using Base::f;		  
	void f(char c) {
		std::cout << "Derived::f(char)\n";
	}
};

int main()
{
  Derived* d = new Derived();
  Base* b = d;
  
  b->f(65.3);
  d->f(65.3);
  
  delete d;
  return 0;
}
