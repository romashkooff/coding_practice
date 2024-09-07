//#include <iostream>
//#include <string>
//#include <fstream>
//
//int main() {
//	std::fstream file("vstup.txt", std::ios::in);
//
//	std::string s;
//	file >> s; // slovo
//	std::cout << "First word is: " << s << std::endl;
//	file >> s; // slovo
//	std::cout << "Second word is: " << s << std::endl;
//	int a;
//	file >> a;
//	if (file.good()) {
//		std::cout << "Error 404" << std::endl;
//		return 1;
//	}
//	
//	std::getline(file, s); // radek
//	std::cout << "What is after two words in the first line: " << s << std::endl;
//
//	char c = file.get();
//}	