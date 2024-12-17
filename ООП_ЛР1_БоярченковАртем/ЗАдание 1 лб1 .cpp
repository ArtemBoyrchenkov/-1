#include <iostream>
#include <cstdlib>
#include <ctime>
int main() {
	std::srand(static_cast<unsigned>(std::time(0)));
	short* array = new short[10];
	for (int i = 0; i < 10; ++i) {
		array[i] = std::rand() % 100;
	}
	std::cout << "Содержимое массива:\n";
	for (int i = 0; i < 10; ++i) {
		std::cout << "array[" << i << "] = " << array[i]
			<< " (адрес: " << &array[i]
			<< ", расстояние от начала: " << ((char*)&array[i] - (char*)array)
			<< " байт)" << std::endl;
	}
	delete[] array;
	return 0;
}