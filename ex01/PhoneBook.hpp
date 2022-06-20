#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {

public:

	PhoneBook();
	~PhoneBook();
	void deleteContacts();
	void addContact(Contact *contact);

private:

	Contact **contacts;
	int contactPos;
	int totalContacts;

	int	nextContactPos();
};

#endif
