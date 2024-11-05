#include <iostream>
#include "employees.h"

using namespace std;

int main()
{
    Employee empManager;

    empManager.printAllEmployees();
    std::cout << std::endl;


    empManager.addEmployee(19, "Josh Martin", "Salesman");
    empManager.addEmployee(40, "Adam Gilber", "Superviser");

    empManager.printAllEmployees();
    std::cout << std::endl;


    empManager.removeEmployee("Adam Gilber");
    empManager.changeEmployeeAmount(150);

    empManager.printAllEmployees();
    std::cout << std::endl;

    empManager.addEmployee(20, "Smasher", "Superviser");

    empManager.printAllEmployees();
    std::cout << std::endl;

    empManager.addEmployee(-20, "Rebecca", "Superviser");
    empManager.addEmployee(21, "Lamer", "Superviser");

    empManager.printAllEmployees();
    std::cout << std::endl;

    

}
