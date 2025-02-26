#include <sstream>
#include <iterator>
#include <vector>
#include <fstream>

int main() {
	std::ofstream out_file("output.txt");
	std::vector<std::string> words = {"here", "could", "be", "your", "ad"};

	std::copy(
		words.begin(),
		words.end(),
		std::ostream_iterator<std::string>(out_file, "\n")
	);
}
