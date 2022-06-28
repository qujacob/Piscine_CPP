#include <string>
#include <fstream>
#include <iostream>

int		main(int ac, char **av) {
	std::fstream	in;
	std::ofstream	out;
	std::string		oldstr, newstr, line, outfile;

	if (ac != 4 || !av[2][0]) {
		std::cerr <<  "Error." << std::endl << "Usage : ./sed [file] [old] [new]" << std::endl;
		return (1);
	}
	in.open(av[1]);
	if (in.is_open()) {
		outfile = std::string(av[1]) + ".replace";
		out.open(outfile.c_str());
		oldstr = std::string(av[2]);
		newstr = std::string(av[3]);
		while (std::getline(in, line)) {
			while (line.size()) {
				if (!line.compare(0, oldstr.size(), oldstr)) {
					out << newstr;
					line = &line[oldstr.size()];
				}
				else {
					out << line[0];
					line = &line[1];
				}
			}
			out << std::endl;
		}
		out.close();
		in.close();
		return (0);
	}
	std::cerr << "Error : Unvalid File." << std::endl;
	return(1);
}