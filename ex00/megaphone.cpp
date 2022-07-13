#include <iostream>
void toUppercase(char *str)
{
	for (int i = 0; str[i] != 0; ++i) {
		str[i] = toupper(str[i]);
	}
}

int main(int len, char **argv) {
	if (len == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; i < len; ++i) {
		toUppercase(argv[i]);
		std::cout << argv[i] << ((i < len - 1) ? " " : "");
	}
	std::cout << std::endl;
	return 0;
}