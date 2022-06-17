#include <iostream>
#include <string>
#include "PhoneBook.hpp"

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

bool	add(const char *arr, PhoneBook& phoneBook) {
	if (!startsWith(arr, "ADD"))
		return false;
	phoneBook.addContact(new Contact("John", "Doe", "Johny", "999", "Is not a real person"));
	return true;
}

bool	search(const char *arr, PhoneBook& phoneBook) {
	if (!startsWith(arr, "SEARCH"))
		return false;
	return true;
}

bool	exit(const char *arr, PhoneBook& phoneBook) {
	if (!startsWith(arr, "EXIT"))
		return false;
	if (strlen(arr) > 4)
		return false;
	return true;
}

int main() {
	PhoneBook *p = new PhoneBook();
	for (std::string line; std::getline(std::cin, line);) {
		std::string tmp;
		switch (*line.c_str()) {
			case 'A': {
				if (!add(line.c_str(), *p))
					std::cout << "Invalid command" << std::endl;
				break;
			}
			case 'S': {
				if(!search(line.c_str(), *p))
					std::cout << "Invalid command" << std::endl;
				break;
			}
			case 'E': {
				if (exit(line.c_str(), *p))
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
