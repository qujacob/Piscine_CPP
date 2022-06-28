#include "class.hpp"

int		mini_stoi(std::string str) {
	int	i, res = 0;

	for (i = 0; std::isspace(str[i]); i++);
	for (; std::isdigit(str[i]); i++)
		res =  res * 10 + (str[i] - 48);
	return (res);
}

void	print_contact(Contact c) {
	std::cout << "Prénom : " << c.getFirst() << std::endl;
	std::cout << "Nom : " << c.getLast() << std::endl;
	std::cout << "Surnom : " << c.getNick() << std::endl;
	std::cout << "Numéro : " << c.getPhone() << std::endl;
	std::cout << "Secret : " << c.getSecret() << std::endl;
}

void	print_rep(std::string str) {
	int spaces = 10 - str.size();

	while (--spaces >= 0)
		std::cout << ' ';
	for (int i = 0; str[i]; i++) {
		if (i == 9 && str.size() > 10) {
			std::cout << '.';
			break ;
		}
		else
			std::cout << str[i];
	}
}

void	search(PhoneBook rep){
	std::string	line;

	if (rep.getSize() > 0) {
		std::cout << std::endl << "Choisissez le contact désiré : " << std::endl << std::endl;
		for (int i = 0; i < rep.getSize(); i++) {
			std::cout << i << " | ";
			print_rep(rep.getContacts()[i].getFirst());
			std::cout << " | ";
			print_rep(rep.getContacts()[i].getLast());
			std::cout << " | ";
			print_rep(rep.getContacts()[i].getNick());
			std::cout << " | " << std::endl;
		}
		std::cout << std::endl << "Saisissez l'index du contact désiré : ";
		if (!std::getline(std::cin, line))
			std::exit(0);
		if (line.size() == 1 && std::isdigit(line[0]) && line[0] - 48 < rep.getSize())
			print_contact(rep.getContacts()[mini_stoi(line)]);
		else
			std::cout << "Index inexistant, veuillez réessayer." << std::endl;
	}
	else
		std::cout << "Aucun contact enregistré. Veuillez utiliser la commande ADD." << std::endl;
}

int		main(void) {
	std::string	str;
	PhoneBook	rep;
	Contact		contacts[8];

	rep.setContacts(contacts);
	while (std::getline(std::cin, str)) {
		if (!str.compare("EXIT"))
			return (0) ;
		else if (!str.compare("ADD"))
			rep.new_contact();
		else if (!str.compare("SEARCH"))
			search(rep);
		else
			std::cout << "Commande inexistante. Veuillez essayer ADD, SEARCH ou EXIT." << std::endl;
	}
	return (0);
}