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
			throw std::invalid_argument("����� � �������� ����� �� ����� ���� �������.");
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
	std::cout << "����� � ����������:" << std::endl;
	for (const auto& book : library) {
		std::cout << "�����: " << book.getAuthor()
			<< ", ��������: " << book.getTitle()
	
			<< ", ���: " << (book.getType() == BookType::Fiction ? "��������������" : "�����������")
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
	std::cout << "���������� �������������� ����������: " << fictionCount << std::endl;
	std::cout << "���������� ����������� ����������: " << technicalCount << std::endl;
}
int main() {
	setlocale(LC_ALL, "");
	std::vector<Book> library;
	library.emplace_back("������ ��������", "������ � ���������", BookType::Fiction);
	library.emplace_back("������ �� ����-��������", "��������� �����", BookType::Fiction);
	library.emplace_back("������� �����", "����� ���������", BookType::Technical);
	library.emplace_back("���� ������", "�����", BookType::Technical);
	
	library.emplace_back("������ ��������", "������", BookType::Fiction);
	library.emplace_back("������ ������", "���� ���������", BookType::Fiction);
	library.emplace_back("������ ������", "2001 ���: ����������� �������", BookType::Fiction);
	library.emplace_back("������ �� ����", "����� ���� ��������", BookType::Technical);library.emplace_back("������� ������", "��������", BookType::Fiction);
	library.emplace_back("����� ����", "��������� ������������ ���������", BookType::Technical);
	library.emplace_back("�������� ������ ������", "����� ���������", BookType::Fiction);library.emplace_back("���� ����", "�������� ������", BookType::Fiction);
	library.emplace_back("��� ��������", "451 ������ �� ����������", BookType::Fiction);printBooks(library);
	std::cout << std::endl;
	countBooks(library);
	return 0;
}