#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	contactPos = 0;
	totalContacts = 0;
	contacts = new Contact*[8];
}

PhoneBook::~PhoneBook() {
	std::cout << "Destroyed phonebook." << std::endl;
}

void PhoneBook::addContact(Contact *contact) {
	if (totalContacts != 8)
		totalContacts++;
	contacts[nextContactPos()] = contact;
}

void PhoneBook::deleteContacts() {
	contactPos = 0;
	totalContacts = 0;
}

int PhoneBook::nextContactPos() {
	if (contactPos == 7)
		contactPos = 0;
	else
		++contactPos;
	if (totalContacts == 8)
		contacts[contactPos]->rem();
	return contactPos;
}

