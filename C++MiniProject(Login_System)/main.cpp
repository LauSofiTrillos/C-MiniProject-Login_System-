#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

void opt_Selected(const int& option);

int main(){

	int opt;

	puts("WELCOME!");
	std::cout << "1. Log In\n" << "2. Register\n" << "1 or 2 ?";
	std::cin >> opt;

	opt_Selected(opt);
}

void opt_Selected(const int& option) {

	std::string username, password, user, ps;

	if (option == 1) {

		puts("LOG IN");
		puts("username: "); std::cin >> username;
		puts("password: "); std::cin >> password;

		std::ifstream read(username + ".txt");
		getline(read, user);
		getline(read, ps);

		if (username == user && password == ps) {

			puts("Login Successful!!");
		}
		else {
			puts("Wrong User or Password");
			main();
		}
	}
	else if (option == 2) {
		puts("REGISTER");
		puts("username: "); std::cin >> username;
		puts("password: "); std::cin >> password;

		user = username;
		ps = password;

		std::ofstream file;
		file.open(username + ".txt");
		file << username << "\n" << password;
		puts("Registration successful!!");
		main();
	}
	else {
		puts("Choose an available option");
		main();
	}
}
