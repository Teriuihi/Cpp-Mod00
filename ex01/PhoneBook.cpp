#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	contactPos = 7;
	totalContacts = 0;
	contacts = new Contact*[8];
}

PhoneBook::~PhoneBook() {
	std::cout << "Destroyed phonebook." << std::endl;
}

void PhoneBook::addContact(Contact *contact) {
	if (totalContacts != 8)
		totalContacts++;
	int i = nextContactPos();
	contacts[i] = contact;
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

void PhoneBook::displayContacts() {
	if (totalContacts == 0)
		return;
	for (int i = 0; i <= totalContacts - 1; i++) {
		contacts[i]->display(i);
		std::cout << std::endl;
	}
}

