#include <iostream>

int main() {
	int sum = 0;
	for (int i = 50; i <= 100; i++) {
		sum += i;
	}
	std::cout << "(for) Sum of 50 to 100 inclusive "
			  << sum << std::endl;
	return 0;
}
