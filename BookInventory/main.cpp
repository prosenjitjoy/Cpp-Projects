#include <iostream>
#include <vector>
#include <string>
#include "book.h"

int main()
{
    Book defaultbook;
    std::cout << "Default constructor invoked.\n";
    defaultbook.printdata();

    Book mybook{ "My Book Title", 123};
    std::cout << "User-provided constructor invoked.\n";
    mybook.printdata();

    std::cout << "The book title is: " << mybook.gettitle() << "\n";
    std::cout << "The number of pages is: " << mybook.getpages() << "\n";

    std::cout << "Setting the new title...\n";
    mybook.settitle("New Book Title");
    std::cout << "Setting the new number of pages...\n";
    mybook.setpages(456);
    mybook.printdata();

    std::cout << "\nCreating an inventory of books...\n";
    std::vector<Book> v = {
        Book{"Simple Book Title 1", 100},
        Book{"Simple Book Title 2", 200},
        Book{"Simple Book Title 3", 300},
        Book{"Simple Book Title 4", 400},
        Book{"Simple Book Title 5", 500},
    };

    for (auto& el: v) {
        el.printdata();
    }

    return 0;
}
