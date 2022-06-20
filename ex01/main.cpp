#include <iostream>
#include <string>
#include "PhoneBook.hpp"

bool equals(const char *arr, const char *string)
{
	while (*arr && *string) {
		if (*arr != *string) {
			return false;
		}
		arr++;
		string++;
	}
	return *arr == *string;
}

bool	add(const char *arr, PhoneBook& phoneBook) {
	std::string request[5] = {"First Name: ", "Last Name: ", "Nick Name: ", "Phone Number: ", "Darkest Secret: "};
	std::string strings[5];
	std::string line;
	if (!equals(arr, "ADD"))
		return false;
	int pos = 0;
	while (pos != 5) {
		std::cout << request[pos];
		std::getline(std::cin, line);
		if (line.empty())
			continue;
		strings[pos++] = line;
	}
	phoneBook.addContact(new Contact(strings[0], strings[1], strings[2], strings[3], strings[4]));
	return true;
}

bool	search(const char *arr, PhoneBook& phoneBook) {
	if (!equals(arr, "SEARCH"))
		return false;
	phoneBook.displayContacts();
	return true;
}

bool	exit(const char *arr, PhoneBook& phoneBook) {
	if (!equals(arr, "EXIT"))
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
