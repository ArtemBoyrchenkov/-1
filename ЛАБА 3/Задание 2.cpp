#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
using namespace std;
class Base {
public:
	virtual ~Base() {
		cout << "Base удалён\n";
	}
	virtual void show() const {
		cout << "Это объект класса Base\n";
	}
};
class Derived : public Base {
public: ~Derived() override {
	cout << "Derived удалён\n";

}
	  void show() const override {
		  cout << "Это объект класса Derived\n";
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
			cout << "Создан объект Base\n";
		}
		else {
			storage.push_back(make_shared<Derived>());
			cout << "Создан объект Derived\n";
		}
	}
	cout << "\n=== Показ объектов из хранилища ===\n";
	for (const auto& obj : storage) {
		obj->show();
	}
	cout << "\n=== Освобождение ресурсов ===\n";
	return 0;
}