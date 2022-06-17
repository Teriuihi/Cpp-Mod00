#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact {

public:
	Contact(const std::string& firstName, const std::string& lastName, const std::string& nickName, const std::string& phoneNumber, const std::string& darkestSecret);
	~Contact();
	void rem();

private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif
