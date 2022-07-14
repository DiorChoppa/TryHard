#include <iostream>

int main(){
	int a, b, c;
	std::cin >> a >> b;

	while(b != 0){
		c = a % b;
		a = b;
		b = c;
	}
	std::cout << a << std::endl;

	return 0;
}