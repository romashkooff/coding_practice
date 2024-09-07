#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    std::string title;
    std::string author;
    int year;
    std::string genre;

    Book(const std::string& title, const std::string& author, const int year, const std::string& genre)
        : title(title), author(author), year(year), genre(genre) {}

    std::string to_json() const {
        return "{\"title\":\"" + title + "\",\"author\":\"" + author +
            "\",\"year\":" + std::to_string(year) + ",\"genre\":\"" + genre + "\"}";
    }
};


#endif //BOOK_H
