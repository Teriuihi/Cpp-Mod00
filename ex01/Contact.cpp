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

std::ostream &operator<<(std::ostream &os, const Contact& c) {
	os << c.firstName << c.lastName << c.nickName << c.phoneNumber;
	return os;
}
