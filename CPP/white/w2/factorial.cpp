#include <iostream>

int factorial(int x){
	if (x < 1)
		return 1;
	else
		x = x * factorial(x - 1);
		return x;
}

int main(){
	int a;
	std::cin >> a;
	std::cout << factorial(a);

	return 0;	
}