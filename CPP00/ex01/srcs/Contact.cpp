#include "class.hpp"

Contact::Contact(void) {
}

Contact::~Contact(void) {
}

void		Contact::setIndex(int index) {
	this->_index = index;	
}

void		Contact::setFirst(std::string first) {
	this->_first_name = first;	
}

void		Contact::setLast(std::string last) {
	this->_last_name = last;	
}

void		Contact::setNick(std::string nick) {
	this->_nickname = nick;	
}

void		Contact::setPhone(std::string phone) {
	this->_phone = phone;	
}

void		Contact::setSecret(std::string secret) {
	this->_secret = secret;	
}

int			Contact::getIndex(void) const {
	return (this->_index);
}

std::string	Contact::getFirst(void) const {
	return (this->_first_name);
}

std::string	Contact::getLast(void) const {
	return (this->_last_name);
}

std::string	Contact::getNick(void) const {
	return (this->_nickname);
}

std::string	Contact::getPhone(void) const {
	return (this->_phone);
}

std::string	Contact::getSecret(void) const {
	return (this->_secret);
}