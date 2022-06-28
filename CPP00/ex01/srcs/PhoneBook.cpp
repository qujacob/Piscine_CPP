#include "class.hpp"

std::string	PhoneBook::_my_getline(void) {
	std::string	str;

	while (str.size() == 0)
	{
		if (!(std::getline(std::cin, str)))
			std::exit(1);
	}
	return (str);
}

int		PhoneBook::_lowest_index(void) {
	int tmp = 2147483647;

	for (int i = 0; i < this->getSize(); i++)
		if (this->getContacts()[i].getIndex() < tmp)
			tmp = this->getContacts()[i].getIndex();
	for (int i = 0; i < this->getSize(); i++)
		if (this->getContacts()[i].getIndex() == tmp)
			return (i);
	return (-1);
}

void	PhoneBook::new_contact(void) {
	Contact	tmp;

	std::cout << "prénom : ";
	tmp.setFirst(_my_getline());
	std::cout << "nom : ";
	tmp.setLast(_my_getline());
	std::cout << "surnom : ";
	tmp.setNick(_my_getline());
	std::cout << "numero : ";
	tmp.setPhone(_my_getline());
	std::cout << "secret : ";
	tmp.setSecret(_my_getline());
	tmp.setIndex(this->getIndex());
	if (this->getSize() < 8) {
		this->getContacts()[this->getSize()] = tmp;
		this->setSize(getSize() + 1);
	}
	else
		this->getContacts()[_lowest_index()] = tmp;
	this->setIndex(this->getIndex() + 1);
}

PhoneBook::PhoneBook(void) {
	this->_size = 0;
	this->_index = 0;
}

PhoneBook::~PhoneBook(void) {
}

void	PhoneBook::setSize(int size) {
	this->_size = size;
}

void	PhoneBook::setIndex(int index) {
	this->_index = index;
}

void	PhoneBook::setContacts(Contact *contacts) {
	this->_contacts = contacts;
}

int		PhoneBook::getSize(void) const {
	return (this->_size);
}

int		PhoneBook::getIndex(void) const {
	return (this->_index);
}

Contact	*PhoneBook::getContacts(void) const {
	return (this->_contacts);
}
