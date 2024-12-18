#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
using namespace std;
class Base {
public:
	virtual ~Base() {
		cout << "Base �����\n";
	}
	virtual void show() const {
		cout << "��� ������ ������ Base\n";
	}
};
class Derived : public Base {
public: ~Derived() override {
	cout << "Derived �����\n";

}
	  void show() const override {
		  cout << "��� ������ ������ Derived\n";
	  }
};
int main() {
	setlocale(0, "");
	srand(static_cast<unsigned>(time(0)));
	vector<shared_ptr<Base>> storage;
	int numObjects = 10;
	for (int i = 0; i < numObjects; ++i) {
		if (i % 2 == 0) {
			storage.push_back(make_shared<Base>());
			cout << "������ ������ Base\n";
		}
		else {
			storage.push_back(make_shared<Derived>());
			cout << "������ ������ Derived\n";
		}
	}
	cout << "\n=== ����� �������� �� ��������� ===\n";
	for (const auto& obj : storage) {
		obj->show();
	}
	cout << "\n=== ������������ �������� ===\n";
	return 0;
}