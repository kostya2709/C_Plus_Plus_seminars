#include <iostream>
#include <cstring>

enum Country {
	Null,
	Russia,
	UK,
	Germany,
};

const char* getCapital(Country country) {
	
/*
	switch(country) {
		case Russia: return "Moscow";
		//...
		default: return "Not found";	
	};
*/

	switch(country) {

#define COUNTRY(name, capital, area, population) case name: return #capital;
#include "country_info"
#undef COUNTRY
		default: return "Not found";
	};


}


Country getCountryByName(const char* countryName) {

	if (0) {}
#define COUNTRY(name, capital, area, population) else if (!strcmp(countryName, #name)) {return name;}
#include "country_info"
#undef COUNTRY
	else {
		return Null;
	}

}


int main() {

	
	std::cout << getCapital(Russia) << '\n';
	std::cout << getCapital(getCountryByName("Germany")) << '\n';

}
