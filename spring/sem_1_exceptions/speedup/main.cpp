#include <vector>
#include <string>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

class X {
private:
	string s;
public:
	X() : s(100, 'a') { }

   	X(const X& x) = default;
 
	X (X&& x) noexcept : s(move(x.s)) { }
};

int main() {
	vector<X> v(1000000);
	cout << "cap.: " << v.capacity() << endl;
	
	auto t0 = high_resolution_clock::now();
	v.emplace_back();
	auto t1 = high_resolution_clock::now();
	
	auto d = duration_cast<milliseconds>(t1 - t0);
	cout << d.count() << " ms\n";
}
