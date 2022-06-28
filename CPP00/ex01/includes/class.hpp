#ifndef CLASS_H
# define CLASS_H

# include <iostream>
# include <string>
# include <cstring>
# include <stdlib.h>

class Contact {

public :

	Contact(void);
	~Contact(void);
	void		setIndex(int index);
	void		setFirst(std::string first);
	void		setLast(std::string last);
	void		setNick(std::string nick);
	void		setPhone(std::string phone);
	void		setSecret(std::string secret);
	int			getIndex(void) const;
	std::string	getFirst(void) const;
	std::string	getLast(void) const;
	std::string	getNick(void) const;
	std::string	getPhone(void) const;
	std::string	getSecret(void) const;


private :

	int			_index;
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone;
	std::string	_secret;

};

class PhoneBook {

public :

	PhoneBook(void);
	~PhoneBook(void);

	void	new_contact(void);
	void	setSize(int size);
	void	setIndex(int index);
	void	setContacts(Contact *contacts);
	int		getSize(void) const;
	int		getIndex(void) const;
	Contact *getContacts(void) const;

private :

	int			_size;
	int			_index;
	Contact		*_contacts;
	int			_lowest_index(void);
	std::string	_my_getline(void);
	
};

#endif
