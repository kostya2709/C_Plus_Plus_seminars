#include <iostream>
#include <map>
#include <unordered_map>

void iterate_basic( std::map<int, char>& dict) {

	std::cout << "iterate basic:\n";
    for ( std::map<int, char>::iterator it = dict.begin(); it != dict.end(); ++it) {
		std::cout << it->first << " " << it->second << std::endl;
    }
	std::cout << "\n\n";
}


void iterate_get( std::map<int, char>& dict) {
	
	std::cout << "iterate get:\n";
    for ( std::map<int, char>::iterator it = dict.begin(); it != dict.end(); ++it) {
        std::cout << std::get<0>(*it) << " " << std::get<1>(*it) << std::endl;
    }
	std::cout << "\n\n";
}

void iterate_type( std::map<int, char>& dict) {

	std::cout << "iterate type:\n";
    for ( std::map<int, char>::iterator it = dict.begin(); it != dict.end(); ++it) {
        std::cout << std::get<int>(*it) << " " << std::get<char>(*it) << std::endl;
    }
	std::cout << "\n\n";
}


int main() {
    
    std::map<int, char> dict;
    dict[0] = 'a';
    dict[2] = 'c';
    dict[1] = 'b';

    
   iterate_basic(dict);
   iterate_get(dict);
   iterate_type(dict);
}
