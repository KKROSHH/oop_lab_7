#include <iostream>
#include <vector>
#include <string>

// Структура для зберігання даних про автомобіль
struct CarInfo {
    int id;
    std::string brand;
    std::string model;
    int year;

    // Конструктор структури
    CarInfo(int id, const std::string& brand, const std::string& model, int year)
        : id(id), brand(brand), model(model), year(year) {}
};

// Клас для управління списком автомобілів
class CarManager {
private:
    std::vector<CarInfo> cars; // Динамічний масив автомобілів

public:
    // Конструктор і деструктор
    CarManager() = default;
    ~CarManager() = default;

    // Додавання нового автомобіля
    void addCar(int id, const std::string& brand, const std::string& model, int year) {
        if (year < 1886 || year > 2024) {
            std::cerr << "Некоректний рік випуску автомобіля!\n";
            return;
        }
        cars.emplace_back(id, brand, model, year);
        std::cout << "Автомобіль додано: ID " << id << ", " << brand << " " << model << ", " << year << " рік\n";
    }

    // Виведення списку всіх автомобілів
    void displayCars() const {
        if (cars.empty()) {
            std::cout << "Список автомобілів порожній.\n";
            return;
        }
        for (const auto& car : cars) {
            std::cout << "ID: " << car.id << ", Марка: " << car.brand
                << ", Модель: " << car.model << ", Рік випуску: " << car.year << "\n";
        }
    }

    // Пошук автомобіля за ID
    void findCarById(int id) const {
        for (const auto& car : cars) {
            if (car.id == id) {
                std::cout << "Знайдено автомобіль: ID " << car.id << ", " << car.brand
                    << " " << car.model << ", " << car.year << " рік\n";
                return;
            }
        }
        std::cout << "Автомобіль із ID " << id << " не знайдено.\n";
    }

    // Видалення автомобіля за ID
    void deleteCarById(int id) {
        for (auto it = cars.begin(); it != cars.end(); ++it) {
            if (it->id == id) {
                std::cout << "Видалено автомобіль: ID " << it->id << ", " << it->brand
                    << " " << it->model << ", " << it->year << " рік\n";
                cars.erase(it);
                return;
            }
        }
        std::cout << "Автомобіль із ID " << id << " не знайдено для видалення.\n";
    }
};

// Головна функція програми
int main() {
    CarManager manager;

    // Додавання автомобілів
    manager.addCar(1, "Toyota", "Corolla", 2020);
    manager.addCar(2, "Honda", "Civic", 2018);
    manager.addCar(3, "BMW", "X5", 2022);

    // Виведення всіх автомобілів
    std::cout << "\nСписок усіх автомобілів:\n";
    manager.displayCars();

    // Пошук автомобіля за ID
    std::cout << "\nПошук автомобіля із ID 2:\n";
    manager.findCarById(2);

    // Видалення автомобіля
    std::cout << "\nВидалення автомобіля із ID 2:\n";
    manager.deleteCarById(2);

    // Виведення списку після видалення
    std::cout << "\nСписок автомобілів після видалення:\n";
    manager.displayCars();

    return 0;
    ... (2 lines left)