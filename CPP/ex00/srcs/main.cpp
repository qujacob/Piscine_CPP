#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	if (ac == 2) {
		std::ifstream	in(av[1]);
		std::ifstream	datafile("data.csv");
		if (in.is_open() && datafile.is_open()) {

			std::list<BtcEx>	database;
			std::string	line;
			std::getline(datafile, line);
			while (std::getline(datafile, line)) {
				std::string date = line.substr(0, line.find(','));
				float rate = atof(line.substr(line.find(',') + 1).c_str());
				BtcEx	ex(date, rate);
				database.push_back(ex);
			}
			std::getline(in, line);
			while (std::getline(in, line)) {
				std::string f = line.substr(0, line.find(" | "));
				Date date(f, database);
				float value = 0;
				if (line.find(" | ") != line.npos)
					value = atof(line.substr(line.find(" | ") + 3).c_str());
				if (value >= 0 && value <= 1000) {
					if (date.isValid()) {
						std::string	previous = date.previousDate();	
						std::list<BtcEx>::iterator	it = database.begin();
						while (it != database.end()) {
							if (it->getDate() == previous) {
								std::cout << f << " => " << std::fixed << std::setprecision(6) << value << " BTC = ";
								std::cout << std::fixed << std::setprecision(4) << value * it->getExchangeRate() << " $" << std::endl;
								break ;
							}
							it++;
						}
						if (it == database.end()) {
							std::cout << "Error" << std::endl;
						}
					}
					else
						std::cout << "Error: bad input => " << f << std::endl;
				}
				else if (value < 0)
					std::cout << "Error: not a positive number." << std::endl;
				else
					std::cout << "Error: too large number." << std::endl;
			}
			return (0);
		}
	}
	std::cerr << "Error : could not open file." << std::endl;
	return (1);
}