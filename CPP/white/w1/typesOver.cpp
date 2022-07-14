#include <iostream>
#include <string>
#include <map>
#include <vector>

struct Person {
	std::string name;
	std::string surname;
	int age;
};

int main() {
	std::map<std::string, int> name_to_value;
	name_to_value["one"] = 1;
	name_to_value["two"] = 2;

	std::cout << "Two is: " << name_to_value["two"] << std::endl;

	std::vector<Person> godlike;
	godlike.push_back({"Kirill", "Dvoryadkin", 20});

	std::cout << godlike[0].name;

	return 0;
}