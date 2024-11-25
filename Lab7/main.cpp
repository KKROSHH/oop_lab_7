#include <iostream>
#include "employees.h"

using namespace std;

int main()
{
    Employee empManager;


    empManager.addEmployee();
    empManager.addEmployee();
    empManager.addEmployee();

    empManager.printEmployees();
    std::cout << std::endl;

    empManager.removeEmployee("2");
    std::cout << std::endl;
    empManager.printAllEmployees();
    std::cout << std::endl;

    empManager.swapEmployees(1, 3);    
    empManager.printEmployees();
    std::cout << std::endl;

    empManager.insertEmployee(1);
    empManager.printEmployees();
    std::cout << std::endl;
    empManager.printAllEmployees();

    empManager.changeEmployeeAmount(50);
    empManager.printAllEmployees();
    std::cout << std::endl;
}
