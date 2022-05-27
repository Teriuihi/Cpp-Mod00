#include <iostream>
#include <string>
#include "Contact.hpp"

bool startsWith(const char *arr, const char *string)
{
	while (*arr && *string) {
		if (*arr != *string) {
			return false;
		}
		if (*arr == ' ')
			return true;
		arr++;
		string++;
	}
	return true;
}

bool	add(const char *arr){
	if (!startsWith(arr, "ADD"))
		return false;
	Contact *c = new Contact("John", "Doe", "Johny", "999", "Is not a real person");
	delete c;
	return true;
}

bool	search(const char *arr){
	if (!startsWith(arr, "SEARCH"))
		return false;
	return true;
}

bool	exit(const char *arr){
	if (!startsWith(arr, "EXIT"))
		return false;
	if (strlen(arr) > 4)
		return false;
	return true;
}

int main() {
	for (std::string line; std::getline(std::cin, line);) {
		std::string tmp;
		switch (*line.c_str()) {
			case 'A': {
				if (!add(line.c_str()))
					std::cout << "Invalid command" << std::endl;
				break;
			}
			case 'S': {
				if(!search(line.c_str()))
					std::cout << "Invalid command" << std::endl;
				break;
			}
			case 'E': {
				if (exit(line.c_str()))
					return (0);
				std::cout << "Invalid command" << std::endl;
				break;
			}
			default: {
				std::cout << "Invalid command" << std::endl;
				break;
			}
		}
	}
	return 0;
}
