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
		cout << "�������� ����������: ";
		getline(cin, title);
		cout << "���� ����������: ";
		cin >> price;
		cin.ignore();
	}
	void putdata() {
		cout << "��������: " << title << endl;
		cout << "����: " << price << endl;
	}
};
class Book : public Publication {
protected:
	int pages;
public:
	void getdata() {
		Publication::getdata();
		cout << "���������� �������: ";
		cin >> pages;
		cin.ignore();
	}
	void putdata() {
		Publication::putdata();
		cout << "���������� �������: " << pages << endl;
	}
};
class AudioBookType : public Publication {
protected:
	int duration;
public:
	void getdata() {
		
		Publication::getdata();
		cout << "����������������� ������ � �������: ";
		cin >> duration;
		cin.ignore();
	}
	void putdata() {
		Publication::putdata();
		cout << "����������������� ������: " << duration << " �����" << endl;
	}
};
class Sales {
protected:
	float sales[3];
public:
	void getSalesData() {
		for (int i = 0; i < 3; i++) {
			cout << "����� ��������� ������ �� ����� " << i + 1 << ": ";
			cin >> sales[i];
			cin.ignore();
		}
	}
	void putSalesData() {
		cout << "����� ��������� ������ �� 3 ������:" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "����� " << i + 1 << ": " << sales[i] << endl;
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
	cout << "���������� � �����:\n";
	book1.getdata();
	cout << "\n���������� � �����:\n";
	book1.putdata();
	cout << endl;
	AudioBookWithSales audiobook1;
	cout << " ���������� �� ����������:\n";
	audiobook1.getdata();
	cout << "\n���������� �� ����������:\n";
	audiobook1.putdata();
	return 0;
}