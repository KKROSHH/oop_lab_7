#include <string>
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

int SIZE = 100;


struct employee_s_t {
    int age;
    std::string name;
    std::string position;
};

class Employee {
    private:
    std::vector<employee_s_t> employees; //Масив співробітників
    int employeeCount = 0; // Лічильник кількості співробітників

    public:
    Employee() { // Конструктор за замовчуванням

        employees.resize(SIZE);

        for (int i = 0; i < SIZE; ++i) { //Ініціалізація за замовчуванням
            employees[i] = {0, "No Name", "No Position"};
        }
    }

    ~Employee(){
         
    }

     // Метод для виведення інформації про співробітників
    void printEmployees() {
        for (int i = 0; i < SIZE; ++i) {
            if (employees[i].name != "No Name") {
                cout << "Employee " << i + 1 << ": " << employees[i].name 
                     << ", Age: " << employees[i].age 
                     << ", Position: " << employees[i].position << endl;
            }
        }
    }

    

    // Метод для додавання співробітника
    bool addEmployee() {
    if (employeeCount >= SIZE) {
        std::cout << "Array is full, cannot add more employees." << std::endl;
        return false; // Якщо масив заповнений
    }

    for (int i = 0; i < SIZE; ++i) {
        if (employees[i].name == "No Name") { // Знаходимо перше вільне місце

            // Введення і перевірка імені
            do {
                std::cout << "Enter employee's name: ";
                getline(std::cin, employees[i].name);
                if (employees[i].name.empty()) {
                    std::cout << "Name cannot be empty. Please try again." << std::endl;
                }
            } while (employees[i].name.empty());

            // Введення і перевірка віку
            do {
                std::cout << "Enter employee's age: ";
                std::cin >> employees[i].age;
                if (std::cin.fail() || employees[i].age <= 0 || employees[i].age > 65) {
                    std::cout << "Invalid age. Please enter a valid age (1-65)." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else {
                    break;
                }
            } while (true);

            // Очистити буфер перед введенням рядка
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Введення і перевірка посади
            do {
                std::cout << "Enter employee's position: ";
                getline(std::cin, employees[i].position);
                if (employees[i].position.empty()) {
                    std::cout << "Position cannot be empty. Please try again." << std::endl;
                }
            } while (employees[i].position.empty());

            employeeCount++;
            return true;
        }
    }

    std::cout << "Unexpected error. Could not add employee." << std::endl;
    return false;
}


    // Метод для видалення співробітника за іменем
    bool removeEmployee(const std::string& name) {
    for (int i = 0; i < SIZE; ++i) {
        if (employees[i].name == name) { // Якщо знайдений співробітник
            // Зсув елементів для уникнення "порожніх" записів посеред списку
            for (int j = i; j < SIZE - 1; ++j) {
                employees[j] = employees[j + 1];
            }
            // Заповнити останній запис "порожнім"
            employees[SIZE - 1] = {0, "No Name", "No Position"};
            employeeCount--;
            return true;
        }
    }
    std::cout << "Employee not found." << std::endl;
    return false;
}



    //Метод для зміни к-сті робітників
    void changeEmployeeAmount(int amount){
        
        SIZE = amount;
        employees.resize(SIZE);

        for (int i = 0; i < SIZE; ++i) { //Ініціалізація за замовчуванням

            if (employees[i].name.empty())
            employees[i] = {0, "No Name", "No Position"};
        }
    }

    // Метод для виведення інформації про співробітників
    void printAllEmployees() const {
        for (int i = 0; i < SIZE; ++i) {

                cout << "Employee " << i + 1 << ": " << employees[i].name 
                     << ", Age: " << employees[i].age 
                     << ", Position: " << employees[i].position << endl;
            
        }
    }

    // Метод для обміну місцями співробітників
    bool swapEmployees(int index1, int index2) {
    if (index1 >= 0 && index1 < SIZE && index2 >= 0 && index2 < SIZE) {
        std::swap(employees[index1 - 1], employees[index2 - 1]);
        return true;
    }
    std::cout << "Invalid index. Swap failed." << std::endl;
    return false;
}




    // Метод для вставки співробітника у конкретну позицію
    bool insertEmployee(int position) {
    if (position < 1 || position > SIZE || employeeCount >= SIZE) {
        std::cout << "Invalid position or array is full. Insert failed." << std::endl;
        return false;
    }
    if (employees[position - 1].name != "No Name") {
        std::cout << "Position already occupied. Insert failed." << std::endl;
        return false;
    }

    std::string name;
    do {
        std::cout << "Enter employee's name: ";
        getline(std::cin, name);
        if (name.empty()) {
            std::cout << "Name cannot be empty. Please try again." << std::endl;
        }
    } while (name.empty());

    int age = 0;
    do {
        std::cout << "Enter employee's age: ";
        std::cin >> age;
        if (std::cin.fail() || age <= 0 || age > 65) {
            std::cout << "Invalid age. Please enter a valid age (1-65)." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    } while (true);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистити буфер

    std::string positionStr;
    do {
        std::cout << "Enter employee's position: ";
        getline(std::cin, positionStr);
        if (positionStr.empty()) {
            std::cout << "Position cannot be empty. Please try again." << std::endl;
        }
    } while (positionStr.empty());

    employees[position - 1] = {age, name, positionStr};
    employeeCount++;
    return true;
}




};