#include <filesystem>
#include <fstream>
#include <iostream>

class Character {
public:
	void save(std::ostream& stream) {
		stream << name_ << ' ' << level_;
	}

  void load(std::istream& stream) {
    stream >> name_;
    stream >> level_;
  }

	std::string name_;
	int level_;
};

namespace fs = std::filesystem;

int main() {
	Character player;

	std::fstream file;
	std::string file_name = "logs";
	const fs::path save_file{"logs"};

	if (fs::exists(save_file)) {
		std::cout << "Loading a saved game\n";
		file.open(file_name, std::ios::in);
		player.load(file);
	} else {
		std::cout << "Starting a new game\n";
		file.open(file_name, std::ios::out);
		player.name_ = "Conan";
		player.level_ = 1;
		player.save(file);
	}
	
	file.close();

	std::sstringstream stream;
	stream << "Name: " << player.name_ << '\n';
	stream << "Level: " << player.level_ << '\n';

	std::cout << stream;
	std::cout << "Character.save: ";
	player.save(std::cout);
}
