#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <locale>
enum class BookType {
	Fiction, Technical
	
};
class Book {
public:
	Book(const std::string& author, const std::string& title, BookType type)
		: author(author), title(title), type(type) {
		if (author.empty() || title.empty()) {
			throw std::invalid_argument("Автор и название книги не могут быть пустыми.");
		}
	}
	std::string getAuthor() const {
		return author;
	}
	std::string getTitle() const {
		return title;
	}
	BookType getType() const {
		return type;
	}
private:
	std::string author;
	std::string title;
	BookType type;
};
void printBooks(const std::vector<Book>& library) {
	std::cout << "Книги в библиотеке:" << std::endl;
	for (const auto& book : library) {
		std::cout << "Автор: " << book.getAuthor()
			<< ", Название: " << book.getTitle()
	
			<< ", Тип: " << (book.getType() == BookType::Fiction ? "Художественная" : "Техническая")
			<< std::endl;
	}
}
void countBooks(const std::vector<Book>& library) {
	int fictionCount = 0;
	int technicalCount = 0;
	for (const auto& book : library) {
		switch (book.getType()) {
		case BookType::Fiction:
			fictionCount++;
			break;
		case BookType::Technical:
			technicalCount++;
			break;
		}
	}
	std::cout << "Количество художественной литературы: " << fictionCount << std::endl;
	std::cout << "Количество технической литературы: " << technicalCount << std::endl;
}
int main() {
	setlocale(LC_ALL, "");
	std::vector<Book> library;
	library.emplace_back("Михаил Булгаков", "Мастер и Маргарита", BookType::Fiction);
	library.emplace_back("Антуан де Сент-Экзюпери", "Маленький принц", BookType::Fiction);
	library.emplace_back("Фрэнсис Бэкон", "Новая Атлантида", BookType::Technical);
	library.emplace_back("Стив Котлер", "Поток", BookType::Technical);
	
	library.emplace_back("Кормак Маккарти", "Дорога", BookType::Fiction);
	library.emplace_back("Джордж Мартин", "Игра престолов", BookType::Fiction);
	library.emplace_back("Стэнли Кубрик", "2001 год: Космическая одиссея", BookType::Fiction);
	library.emplace_back("Эдвард Де Боно", "Шесть шляп мышления", BookType::Technical);library.emplace_back("Джулиан Ассанж", "Виктория", BookType::Fiction);
	library.emplace_back("Клаус Шваб", "Четвертая промышленная революция", BookType::Technical);
	library.emplace_back("Габриэль Гарсиа Маркес", "Осень патриарха", BookType::Fiction);library.emplace_back("Джон Грин", "Виноваты звезды", BookType::Fiction);
	library.emplace_back("Рэй Брэдбери", "451 градус по Фаренгейту", BookType::Fiction);printBooks(library);
	std::cout << std::endl;
	countBooks(library);
	return 0;
}