#include <iostream>
#include <vector>
#include <memory>
using namespace std;
class Part {
protected:
	string name;
	Part(const string& n) : name(n) {}
public:
	virtual ~Part() {}
	virtual void print() const = 0;
};
class Assembly : public Part {
protected:
	vector<shared_ptr<Part>> components;
	Assembly(const string& name) : Part(name) {}
	template <typename T>
	friend shared_ptr<Part> createComponent(const string& name);
public:
	void addComponent(shared_ptr<Part> component) {
		components.push_back(component);
	
	}
	void print() const override {
		cout << "������: " << name << endl;
		for (const auto& component : components) {
			component->print();
		}
	}
};
class SimplePart : public Part {
protected:
	// ����������� � protected
	SimplePart(const string& name) : Part(name) {}
	template <typename T>
	friend shared_ptr<Part> createComponent(const string& name);
public:
	void print() const override {
		cout << "������: " << name << endl;
	}
};
template <typename T>
shared_ptr<Part> createComponent(const string& name) {
	static_assert(is_base_of<Part, T>::value, "T ������ ���� ����������� Part");
	return shared_ptr<Part>(new T(name));
}
int main() {
	setlocale(0, "");
	vector<shared_ptr<Part>> storage;

	storage.push_back(createComponent<SimplePart>("������1"));
	storage.push_back(createComponent<SimplePart>("������2"));
	auto assembly = createComponent<Assembly>("������1");
	storage.push_back(assembly);
	auto assemblyPtr = dynamic_pointer_cast<Assembly>(assembly);
	if (assemblyPtr) {
		assemblyPtr->addComponent(createComponent<SimplePart>("������3"));
		assemblyPtr->addComponent(createComponent<SimplePart>("������4"));
	}
	for (const auto& part : storage) {
		part->print();
	}
	return 0;
}