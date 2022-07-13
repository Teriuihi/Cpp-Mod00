#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {

public:

	PhoneBook();
	~PhoneBook();
	void deleteContacts();
	void addContact(Contact *contact);
	void displayContacts();
	void displayContact(int index);

private:

	Contact **contacts;
	int contactPos;
	int totalContacts;

	int	nextContactPos();
};

#endif
