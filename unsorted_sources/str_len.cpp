#include <iostream>

unsigned str_len(const char *str) {
	int len = 0;
	while (*str++) len++;
	return len;
}

int main() {
	int len = str_len("Hello!");
	std::cout << len << "\n";
	return 0;
}

/*
*str - получает символ, записанный по указателю
*str++ - получает символ, записанный по указателю, после чего сдвигает указатель на следующий элемент
этот символ - char - можно также интерпретировать как число от 0 до скольки-то-там
в сях есть неявное преобразование типов, число (и char тоже) можно преобразовать к bool : 0 - это false, всё остальное - это true
то есть, *str++ возвращает true, если по указателю ненулевой символ, и false, если нулевой (с нулевым кодом, он как раз соответствует окончанию C-style строки). После этого этот же оператор сдвигает указатель на следующий char
ну и, дальше очевидно - пока строка не окончена, увеличиваем счетчик.
*/
