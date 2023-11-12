#include <iostream>
#include "employee.h"

namespace is {
    // Constructors
    Employee::Employee(): Person(), jobtitle{"The default Role"} {}
    Employee::Employee(const std::string& aname, const int& aage, const std::string& ajobtitle): Person(aname, aage), jobtitle{ajobtitle} {}
    Employee::Employee(const Employee& rhs): Person(rhs), jobtitle{rhs.jobtitle} {}
    Employee& Employee::operator=(const Employee& rhs) {
        Person::operator=(rhs);
        jobtitle = rhs.jobtitle;
        return *this;
    }
    Employee::Employee(Employee&& rhs) noexcept: Person(std::move(rhs)), jobtitle{std::move(rhs.jobtitle)} {}
    Employee& Employee::operator=(Employee&& rhs) noexcept {
        Person::operator=(std::move(rhs));
        jobtitle = std::move(rhs.jobtitle);
        return *this;
    }

    // Methods
    void Employee::formatprint() {
        std::cout << "Employee's name: " << getname() << ", age: " << getage() << ", job title: " << jobtitle << "\n";
    }

    // Getters Setters
    std::string Employee::getjobtitle() const {
        return jobtitle;
    }
    void Employee::setjobtitle(const std::string& ajobtitle) {
        jobtitle = ajobtitle;
    }
}
