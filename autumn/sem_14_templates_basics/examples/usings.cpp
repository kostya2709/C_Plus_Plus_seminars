#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>


template <typename T>
using MyPair = std::unordered_map<std::string, std::map<double, T>>;

int main() {

	MyPair<std::vector<int>> pair;

}

