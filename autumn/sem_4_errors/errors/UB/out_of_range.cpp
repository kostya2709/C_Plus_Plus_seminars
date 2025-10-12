#include <iostream>

int table[4];

bool exists_in_table(int v) {
    for (int i = 0; i <= 4; i++) {
        if (table[i] == v) return true;
    }
    return false;
}


int main() {
	std::cout << exists_in_table(10) << '\n';
}
