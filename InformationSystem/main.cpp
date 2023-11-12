#include <iostream>
#include <vector>
#include <memory>
#include "person.h"
#include "employee.h"

int main()
{
    // a vector unique pointers
    std::vector<std::unique_ptr<is::Person>>v;
    v.emplace_back(std::make_unique<is::Employee>("Sample Name 1", 20, "Developer"));
    v.emplace_back(std::make_unique<is::Employee>("Sample Name 2", 25, "Engineer"));
    v.emplace_back(std::make_unique<is::Employee>("Sample Name 3", 30, "Quality Assurance"));
    v.emplace_back(std::make_unique<is::Employee>("Sample Name 4", 35, "Human Resources"));
    v.emplace_back(std::make_unique<is::Employee>("Sample Name 5", 40, "Manager"));
    v.emplace_back(std::make_unique<is::Employee>("Sample Name 6", 45, "CEO"));

    for (const auto& el: v) {
        el->formatprint();
    }

    std::cout << "Testing..." << "\n";
    is::Employee o1; // default constructor invoked
    is::Employee o2("Sample name 7", 50, "Accountant");
    o1.formatprint();
    o2.formatprint();
    o1 = o2; // copy assignment test;
    o1.formatprint();
    return 0;
}
