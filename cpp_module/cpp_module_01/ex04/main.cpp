#include <iostream>
#include <string>
#include <fstream>

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Invalid number of parameters." << std::endl;
		return (1);
	}

	int	file_len = strlen(argv[1]);
	int	s1_len = strlen(argv[2]);
	int	s2_len = strlen(argv[3]);

	if (file_len == 0 || s1_len == 0 || s2_len == 0) {
		std::cout << "argv is empty" << std::endl;
		return (1);
	}
	std::ifstream in(argv[1]);
	if (in.is_open()) {
		std::string	input;
		std::string	line;
		while (std::getline(in, line)) {
			if (!in.eof()) {
				line += '\n';
			}
			input += line;
		}
		std::string::size_type	pos;
		pos = input.find(argv[2]);
		while (pos != std::string::npos) {
			input.erase(pos, s1_len);
			input.insert(pos, argv[3]);
			pos = input.find(argv[2]);
		}
		std::ofstream	out(std::string(argv[1]) + ".replace");
		if (out.is_open() == false) {
			std::cout << "failed to open '*.replace' file" << std::endl;
			return (1);
		}
		out.write(input.c_str(), input.size());
	} else {
		std::cout << "failed to open " << argv[1] << std::endl;
		return (1);
	}
}
