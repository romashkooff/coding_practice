#ifndef READINGLOG_H
#define READINGLOG_H

#include <string>
#include <vector>
#include "book.h"

class ReadingLog {
private:
    std::vector<Book> books;

public:
    void addEntry(const Book& book);

    void printLog() const;

    std::vector<Book> searchByAuthor(const std::string& author) const;

    std::vector<Book> searchByTitle(const std::string& title) const;

    std::vector<Book> findOldest(const int& year) const;

    void saveToFile(const std::string& filename) const;

    void loadFromFile(const std::string& filename);

    void createNewLog();

private:
    Book jsonToBook(const std::string& jsonStr) const {
        size_t titleStart = jsonStr.find("\"title\":\"") + 9;
        size_t titleEnd = jsonStr.find("\"", titleStart);
        std::string title = jsonStr.substr(titleStart, titleEnd - titleStart);

        size_t authorStart = jsonStr.find("\"author\":\"") + 10;
        size_t authorEnd = jsonStr.find("\"", authorStart);
        std::string author = jsonStr.substr(authorStart, authorEnd - authorStart);

        size_t yearStart = jsonStr.find("\"year\":") + 7;
        size_t yearEnd = jsonStr.find(",", yearStart);
        int year = std::stoi(jsonStr.substr(yearStart, yearEnd - yearStart));

        size_t genreStart = jsonStr.find("\"genre\":\"") + 9;
        size_t genreEnd = jsonStr.find("\"", genreStart);
        std::string genre = jsonStr.substr(genreStart, genreEnd - genreStart);

        return Book(title, author, year, genre);
    }
};

#endif //READINGLOG_H
