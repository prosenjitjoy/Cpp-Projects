#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include "person.h"

namespace is {
    // derived class Employee
    class Employee: public Person {
    private:
        std::string jobtitle;
    public:
        // constructor
        Employee();
        Employee(const std::string& aname, const int& aage, const std::string& ajobtitle);
        Employee(const Employee& rhs);
        Employee& operator=(const Employee& rhs);
        Employee(Employee&& rhs) noexcept;
        Employee& operator=(Employee&& rhs) noexcept;

        // methods
        void formatprint() override;

        // getters setters
        std::string getjobtitle() const;
        void setjobtitle(const std::string& ajobtitle);
    };
}

#endif // EMPLOYEE_H
