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
    void printEmployees() const {
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
        
        
            if (employeeCount < SIZE) {
                for (int i = 0; i < SIZE; ++i) {
                    if (employees[i].name == "No Name") { // Знаходимо перше вільне місце
                    std::cout << "Enter employee's name: "<< std::endl;
                    getline(std::cin, employees[i].name);

                    std::cout << "Enter employee's age: " << std::endl;
                    std::cin >> employees[i].age;

                    std::cout << "Enter employee's position: " << std::endl;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    getline(std::cin, employees[i].position);

                    
                    employeeCount++;
                    return true;
                }
            }
        }
            std::cout << "Array is full, cannot add more employees." << std::endl;
            return false; // Якщо масив заповнений
        

        std::cout << "Invalid type for age, name or position." << std::endl;
        return false;


    }

    // Метод для видалення співробітника за іменем
    bool removeEmployee(const std::string& name) {
        for (int i = 0; i < SIZE; ++i) {
            if (employees[i].name == name) { // Якщо знайдений співробітник
                employees[i] = {0, "No Name", "No Position"}; // Очищуємо запис
                employeeCount--;
                return true;
            }
        }
        cout << "Employee not found." << std::endl;
        return false; // Якщо співробітника не знайдено
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


};