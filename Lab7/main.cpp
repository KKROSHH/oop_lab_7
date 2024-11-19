#include <iostream>
#include "employees.h"

using namespace std;

int main()
{
    Employee empManager;

    //empManager.printAllEmployees();
    std::cout << std::endl;


    empManager.addEmployee();
    //empManager.addEmployee();

    empManager.printAllEmployees();
    std::cout << std::endl;


    empManager.removeEmployee("Adam Gilber");
    empManager.changeEmployeeAmount(150);

    empManager.printAllEmployees();
    std::cout << std::endl;

    empManager.addEmployee();

    empManager.printAllEmployees();
    std::cout << std::endl;

    empManager.addEmployee();
    empManager.addEmployee();

    empManager.printAllEmployees();
    std::cout << std::endl;

    

}
