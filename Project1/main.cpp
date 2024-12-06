/* Сформировать новую строку, заменив в исходной строке все вхождения одного заданного
символа на другой заданный символ.*/

#include <iostream>
#include <fstream>


char* func(char* destination, const char* source, const char char_to_change, const char new_char);

const char* ERROR_FILE = "ERROR: Ошибка работы с файлами.";
const char* ERROR_NO_SYMBOL = "ERROR: Введены неверные символы для замены. Остановка программ.";
const char* ERROR_MEMORY = "ERROR: В строке введено больше символов, чем указано.";


int main() {
	setlocale(0, "");
	int source_len;
	char char_to_change;
	char new_char;
	
	try {
		std::ifstream reader("input.txt");
		std::ofstream writer("output.txt");
		if (reader.is_open() && writer.is_open()) {
			reader >> source_len;
			char* source = new char[source_len + 1];
			char* destination = new char[source_len + 1];
			while (reader >> source >> char_to_change >> new_char) {
				if (strlen(source) > source_len)
					throw ERROR_MEMORY;
				func(destination, source, char_to_change, new_char);
				if (!std::strcmp(source, destination))
					throw ERROR_NO_SYMBOL;
				std::cout << destination << '\n';
				writer << destination << '\n';
			}
			reader.close();
			writer.close();
			delete[] source;
			delete[] destination;

		} 
		else 
			throw ERROR_FILE;
	}
	catch (const char* error) {
		std::cout << error;
	}
}


char* func(char* destination, const char* source, const char char_to_change, const char new_char) {
	int i = 0;
	for (; i < strlen(source); i++) {
		if (source[i] == char_to_change)
			destination[i] = new_char;
		else
			destination[i] = source[i];
	}
	destination[i] = '\0';
	return destination;
}