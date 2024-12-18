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
			throw std::invalid_argument("ID транспортного средства должно быть больше0");
		}
		if (name.empty()) {
			throw std::invalid_argument("Название транспортного средства не может бытьпустым");
		}
	}
	virtual ~Vehicle() = default;
	virtual void printInfo() const = 0;
	virtual std::string getType() const = 0;
};
class Bicycle : public Vehicle {
public:
	Bicycle(int id, const std::string& name) : Vehicle(id, name) {}
	void printInfo() const override { std::cout << "Велосипед ID: " << id << ", Название: " << name << "\n"; }
	
	std::string getType() const override { return "Велосипед"; }
};
class Car : public Vehicle {
public:
	Car(int id, const std::string& name) : Vehicle(id, name) {}
	void printInfo() const override { std::cout << "Автомобиль ID: " << id << ", Название: " << name << "\n"; }
	std::string getType() const override { return "Автомобиль"; }
};
class Truck : public Vehicle {
public:
	Truck(int id, const std::string& name) : Vehicle(id, name) {}
	void printInfo() const override { std::cout << "Грузовик ID: " << id << ", Название: " << name << "\n"; }
	std::string getType() const override { return "Грузовик"; }
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
			throw std::out_of_range("Индекс за пределами массива");
		}
		data[index] = ptr;
	}
	
		T * operator[](size_t index) {
		if (index >= size_ || index < 0) {
			throw std::out_of_range("Индекс за пределами массива");
		}
		return data[index].get();
	}
	const T* operator[](size_t index) const {
		if (index >= size_ || index < 0) {
			throw std::out_of_range("Индекс за пределами массива");
		}
		return data[index].get();
	}
	size_t size() const { return size_; }
	void addVehicle(size_t index, int id, const std::string& name, const std::string& type) {
		if (id <= 0) throw std::invalid_argument("ID должен быть больше 0");
		if (name.empty()) throw std::invalid_argument("Название не может быть пустым");
		if (type.empty()) throw std::invalid_argument("Тип не может быть пустым");
		std::shared_ptr<Vehicle> newVehicle;
		if (type == "Велосипед") newVehicle = std::make_shared<Bicycle>(id, name);
		else if (type == "Автомобиль") newVehicle = std::make_shared<Car>(id, name);
		else if (type == "Грузовик") newVehicle = std::make_shared<Truck>(id, name);
		else throw std::invalid_argument("Неизвестный тип транспортного средства");
		set(index, newVehicle);
	}
};
int main() {
	PointerArray<Vehicle> vehicles(3);
	
		setlocale(0, "");
	try {
		vehicles.addVehicle(0, 1, "Велик №1", "Велосипед");
		vehicles.addVehicle(1, 2, "Машина №2", "Автомобиль");
		vehicles.addVehicle(2, 3, "Грузовик №3", "Грузовик");
		for (size_t i = 0; i < vehicles.size(); ++i) {
			vehicles[i]->printInfo();
		}
		vehicles.addVehicle(3, 4, "Ошибка", "Велосипед");
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Ошибка: " << e.what() << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Ошибка: Неверный аргумент: " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Непредвиденная ошибка: " << e.what() << std::endl;
	}
	return 0;
}