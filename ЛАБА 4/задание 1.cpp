#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <string>
class Vehicle {
public:
	int id;
	std::string name;
	Vehicle(int id, const std::string& name) : id(id), name(name) {
		if (id <= 0) {
			throw std::invalid_argument("ID ������������� �������� ������ ���� ������0");
		}
		if (name.empty()) {
			throw std::invalid_argument("�������� ������������� �������� �� ����� ����������");
		}
	}
	virtual ~Vehicle() = default;
	virtual void printInfo() const = 0;
	virtual std::string getType() const = 0;
};
class Bicycle : public Vehicle {
public:
	Bicycle(int id, const std::string& name) : Vehicle(id, name) {}
	void printInfo() const override { std::cout << "��������� ID: " << id << ", ��������: " << name << "\n"; }
	
	std::string getType() const override { return "���������"; }
};
class Car : public Vehicle {
public:
	Car(int id, const std::string& name) : Vehicle(id, name) {}
	void printInfo() const override { std::cout << "���������� ID: " << id << ", ��������: " << name << "\n"; }
	std::string getType() const override { return "����������"; }
};
class Truck : public Vehicle {
public:
	Truck(int id, const std::string& name) : Vehicle(id, name) {}
	void printInfo() const override { std::cout << "�������� ID: " << id << ", ��������: " << name << "\n"; }
	std::string getType() const override { return "��������"; }
};
template <typename T>
class PointerArray {
private:
	std::vector<std::shared_ptr<T>> data;
	size_t size_;
public:
	PointerArray(size_t size) : size_(size), data(size) {}
	void set(size_t index, std::shared_ptr<T> ptr) {
		if (index >= size_ || index < 0) {
			throw std::out_of_range("������ �� ��������� �������");
		}
		data[index] = ptr;
	}
	
		T * operator[](size_t index) {
		if (index >= size_ || index < 0) {
			throw std::out_of_range("������ �� ��������� �������");
		}
		return data[index].get();
	}
	const T* operator[](size_t index) const {
		if (index >= size_ || index < 0) {
			throw std::out_of_range("������ �� ��������� �������");
		}
		return data[index].get();
	}
	size_t size() const { return size_; }
	void addVehicle(size_t index, int id, const std::string& name, const std::string& type) {
		if (id <= 0) throw std::invalid_argument("ID ������ ���� ������ 0");
		if (name.empty()) throw std::invalid_argument("�������� �� ����� ���� ������");
		if (type.empty()) throw std::invalid_argument("��� �� ����� ���� ������");
		std::shared_ptr<Vehicle> newVehicle;
		if (type == "���������") newVehicle = std::make_shared<Bicycle>(id, name);
		else if (type == "����������") newVehicle = std::make_shared<Car>(id, name);
		else if (type == "��������") newVehicle = std::make_shared<Truck>(id, name);
		else throw std::invalid_argument("����������� ��� ������������� ��������");
		set(index, newVehicle);
	}
};
int main() {
	PointerArray<Vehicle> vehicles(3);
	
		setlocale(0, "");
	try {
		vehicles.addVehicle(0, 1, "����� �1", "���������");
		vehicles.addVehicle(1, 2, "������ �2", "����������");
		vehicles.addVehicle(2, 3, "�������� �3", "��������");
		for (size_t i = 0; i < vehicles.size(); ++i) {
			vehicles[i]->printInfo();
		}
		vehicles.addVehicle(3, 4, "������", "���������");
	}
	catch (const std::out_of_range& e) {
		std::cerr << "������: " << e.what() << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "������: �������� ��������: " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "�������������� ������: " << e.what() << std::endl;
	}
	return 0;
}