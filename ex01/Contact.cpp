#include "Contact.hpp"

Contact::Contact(const std::string& firstName, const std::string& lastName,
				 const std::string& nickName, const std::string& phoneNumber, const std::string& darkestSecret)
	: firstName(firstName), lastName(lastName), nickName(nickName), phoneNumber(phoneNumber), darkestSecret(darkestSecret) {
	std::cout << "Created contact." << std::endl;
	std::cout << "\tFirst Name: " << this->firstName << std::endl;
	std::cout << "\tLast Name: " << this->lastName << std::endl;
	std::cout << "\tNick Name: " << this->nickName << std::endl;
	std::cout << "\tPhone Number: " << this->phoneNumber << std::endl;
	std::cout << "\tDarkest Secret: " << this->darkestSecret << std::endl;
}

Contact::~Contact() {
	std::cout << "Destroyed contact." << std::endl;
}

void Contact::rem() {
	delete this;
}

void Contact::display(int index) {
	std::cout << "|";
	printAligned(std::to_string(index));
	printAligned(firstName);
	printAligned(lastName);
	printAligned(nickName);
}

void Contact::display() {
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nick name: " << nickName << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}

void Contact::printAligned(const std::string& str) {
	int strLen = str.size();
	if (strLen < 10) {
		for (int i = strLen; i != 10; i++) {
			std::cout << ' ';
		}
		std::cout << str;
	} else if (strLen == 10) {
		std::cout << str;
	} else {
		std::cout << str.substr(0, 9) << ".";
	}
	std::cout << "|";
}
