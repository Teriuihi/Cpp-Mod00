#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {

public:

	PhoneBook();
	~PhoneBook();
	void deleteContacts();

private:

	Contact contacts[8];
};

#endif
