#include <fstream>
#include <iostream>

std::fstream File;

void ReadFile() {
  File.seekg(0);
  std::cout << "File Contents:\n"
            << File.rdbuf() << "\n\n";
}

void ReadCharacter(int Position) {
  File.seekp(Position);
  std::cout << "Character at Input Position "
            << File.tellp() << ": "
            << static_cast<char>(File.get())
            << "\n";
}

void WriteString(std::string String,
                 int Position) {
  File.seekg(Position);
  std::cout << "Writing \"" << String
            << "\" to Output Position "
            << File.tellg() << "\n\n";
  File << String;
}

int main() {
  File.open("hello.txt");

  ReadFile();
  ReadCharacter(0);
  ReadCharacter(3);
  ReadCharacter(6);
  WriteString("Everyone", 6);
  ReadFile();

  File.close();
}
