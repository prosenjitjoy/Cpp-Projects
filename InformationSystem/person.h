#ifndef PERSON_H
#define PERSON_H

#include <iostream>

namespace is {
    // base class Person
    class Person {
    private:
        std::string name;
        int age;
    public:
        // constructor
        Person();
        Person(const std::string& aname, const int& aage);
        Person(const Person& rhs);
        Person& operator=(const Person& rhs);
        Person(Person&& rhs) noexcept;
        Person& operator=(Person&& rhs) noexcept;

        // methods
        void printname();
        void printage();
        void printdata();
        virtual void formatprint();

        // getters setters
        std::string getname() const;
        int getage() const;
        void setname(const std::string& aname);
        void setage(const int& aage);

        // destructor
        virtual ~Person() {};
    };
}

#endif // PERSON_H
