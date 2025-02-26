#include <string>
#include <vector>
#include <iostream>

std::vector<std::string_view> split(std::string_view str, char delimiter) {
    std::vector<std::string_view> tokens;
    size_t start = 0, end = 0;
    while ((end = str.find(delimiter, start)) != std::string_view::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}

int main() {
	std::string text("Simple string with whitespaces");
	
	auto tokens = split(text, ' ');
	for (auto token : tokens) {
		std::cout << token << '\n';
	}

}
