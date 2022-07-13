#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	contactPos = -1;
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
	if (totalContacts == 0)
		return;
	for (int i = 0; i <= totalContacts - 1; i++) {
		contacts[i]->rem();
	}
}

int PhoneBook::nextContactPos() {
	if (contactPos == 7 || contactPos == -1)
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

void PhoneBook::displayContact(int index) {
	if (index > contactPos) {
		std::cout << "Invalid contact, ending search." << std::endl;
		return;
	}
	contacts[index]->display();
}

