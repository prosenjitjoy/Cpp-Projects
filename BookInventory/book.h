#ifndef BOOK_H
#define BOOK_H
#include <string>

class Book {
private:
    // members
    std::string title;
    int pages;
public:
    // constructor
    Book();
    Book(const std::string& atitle, const int& apages);

    // methods
    void printdata();

    // getters
    std::string gettitle() const;
    int getpages() const;

    // setters
    void settitle(const std::string& atitle);
    void setpages(const int& apages);
};

#endif // BOOK_H
