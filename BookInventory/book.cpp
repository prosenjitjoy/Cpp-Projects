#include <iostream>
#include "book.h"

// Constructor
Book::Book(): title{"Default Book Title"}, pages{0} {}
Book::Book(const std::string& atitle, const int& apages): title{atitle}, pages{apages} {}

// Methods
void Book::printdata() {
    std::cout << "The book title is: " << title << ", and the number of pages is: " << pages << "\n";
}

// Getters
std::string Book::gettitle() const {
    return title;
}
int Book::getpages() const {
    return pages;
}

// Setters
void Book::settitle(const std::string& atitle) {
    title = atitle;
}
void Book::setpages(const int& apages) {
    pages = apages;
}
