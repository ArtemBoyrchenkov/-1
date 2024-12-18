#include <iostream>
#include <ctime>
#include <string>
using namespace std;
class Publication {
protected:
	string title;
	float price;
public:
	void getdata() {
		cout << "название публикации: ";
		getline(cin, title);
		cout << "цена публикации: ";
		cin >> price;
		cin.ignore();
	}
	void putdata() {
		cout << "Название: " << title << endl;
		cout << "Цена: " << price << endl;
	}
};
class Book : public Publication {
protected:
	int pages;
public:
	void getdata() {
		Publication::getdata();
		cout << "количество страниц: ";
		cin >> pages;
		cin.ignore();
	}
	void putdata() {
		Publication::putdata();
		cout << "Количество страниц: " << pages << endl;
	}
};
class AudioBookType : public Publication {
protected:
	int duration;
public:
	void getdata() {
		
		Publication::getdata();
		cout << "продолжительность записи в минутах: ";
		cin >> duration;
		cin.ignore();
	}
	void putdata() {
		Publication::putdata();
		cout << "Продолжительность записи: " << duration << " минут" << endl;
	}
};
class Sales {
protected:
	float sales[3];
public:
	void getSalesData() {
		for (int i = 0; i < 3; i++) {
			cout << "общая стоимость продаж за месяц " << i + 1 << ": ";
			cin >> sales[i];
			cin.ignore();
		}
	}
	void putSalesData() {
		cout << "Общая стоимость продаж за 3 месяца:" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "Месяц " << i + 1 << ": " << sales[i] << endl;
		}
	}
};
class BookWithSales : public Book, public Sales {
public:
	void getdata() {
		Book::getdata();
		Sales::getSalesData();
	}
	void putdata() {
		Book::putdata();
		Sales::putSalesData();
	}
};
class AudioBookWithSales : public AudioBookType, public Sales {
public:
	void getdata() {
		AudioBookType::getdata();
		Sales::getSalesData();
	}

		void putdata() {
		AudioBookType::putdata();
		Sales::putSalesData();
	}
};
int main() {
	setlocale(LC_ALL, "RUS");
	BookWithSales book1;
	cout << "информация о книге:\n";
	book1.getdata();
	cout << "\nИнформация о книге:\n";
	book1.putdata();
	cout << endl;
	AudioBookWithSales audiobook1;
	cout << " информация об аудиокниге:\n";
	audiobook1.getdata();
	cout << "\nИнформация об аудиокниге:\n";
	audiobook1.putdata();
	return 0;
}