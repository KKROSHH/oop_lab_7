#include <iostream>
#include <vector>
#include <string>

// ��������� ��� ��������� ����� ��� ���������
struct CarInfo {
    int id;
    std::string brand;
    std::string model;
    int year;

    // ����������� ���������
    CarInfo(int id, const std::string& brand, const std::string& model, int year)
        : id(id), brand(brand), model(model), year(year) {}
};

// ���� ��� ��������� ������� ���������
class CarManager {
private:
    std::vector<CarInfo> cars; // ��������� ����� ���������

public:
    // ����������� � ����������
    CarManager() = default;
    ~CarManager() = default;

    // ��������� ������ ���������
    void addCar(int id, const std::string& brand, const std::string& model, int year) {
        if (year < 1886 || year > 2024) {
            std::cerr << "����������� �� ������� ���������!\n";
            return;
        }
        cars.emplace_back(id, brand, model, year);
        std::cout << "��������� ������: ID " << id << ", " << brand << " " << model << ", " << year << " ��\n";
    }

    // ��������� ������ ��� ���������
    void displayCars() const {
        if (cars.empty()) {
            std::cout << "������ ��������� �������.\n";
            return;
        }
        for (const auto& car : cars) {
            std::cout << "ID: " << car.id << ", �����: " << car.brand
                << ", ������: " << car.model << ", г� �������: " << car.year << "\n";
        }
    }

    // ����� ��������� �� ID
    void findCarById(int id) const {
        for (const auto& car : cars) {
            if (car.id == id) {
                std::cout << "�������� ���������: ID " << car.id << ", " << car.brand
                    << " " << car.model << ", " << car.year << " ��\n";
                return;
            }
        }
        std::cout << "��������� �� ID " << id << " �� ��������.\n";
    }

    // ��������� ��������� �� ID
    void deleteCarById(int id) {
        for (auto it = cars.begin(); it != cars.end(); ++it) {
            if (it->id == id) {
                std::cout << "�������� ���������: ID " << it->id << ", " << it->brand
                    << " " << it->model << ", " << it->year << " ��\n";
                cars.erase(it);
                return;
            }
        }
        std::cout << "��������� �� ID " << id << " �� �������� ��� ���������.\n";
    }
};

// ������� ������� ��������
int main() {
    CarManager manager;

    // ��������� ���������
    manager.addCar(1, "Toyota", "Corolla", 2020);
    manager.addCar(2, "Honda", "Civic", 2018);
    manager.addCar(3, "BMW", "X5", 2022);

    // ��������� ��� ���������
    std::cout << "\n������ ��� ���������:\n";
    manager.displayCars();

    // ����� ��������� �� ID
    std::cout << "\n����� ��������� �� ID 2:\n";
    manager.findCarById(2);

    // ��������� ���������
    std::cout << "\n��������� ��������� �� ID 2:\n";
    manager.deleteCarById(2);

    // ��������� ������ ���� ���������
    std::cout << "\n������ ��������� ���� ���������:\n";
    manager.displayCars();

    return 0;
    ... (2 lines left)