#include <iostream>

class Test {
public:
    Test( int num, int lvl) : num( num), lvl( lvl) {} 

    ~Test() {
        std::cout << "Destroying " << num << " on level " << lvl << std::endl;
    }
private:

    int lvl;
    int num;

};

void foo_inner() {

    Test test7( 7, 3);
    Test test8( 8, 3);

    throw 1;

    Test test9( 9, 3);
}

void foo_outer() {
    Test test4( 4, 2);
    Test test5( 5, 2);

    foo_inner();

    Test test6( 6, 2);
}

int main() {
   try {
        Test test1( 1, 1);
        Test test2( 2, 1);
    
        foo_outer();
    
        Test test3( 3, 1);
    } catch (long x) {
        std::cout << "Caught smth!\n";
    }
}
