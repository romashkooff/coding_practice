#include <iostream>
#include <fstream>

#include "ReadingLog.h"

void ReadingLog::addEntry(const Book& book) {
    books.push_back(book);
}

void ReadingLog::printLog() const {
    if (books.empty()) {
        std::cout << "Reading log is empty." << std::endl;
        std::cout << "------------------------" << std::endl;
        return;
    }

    std::cout << "Reading Log:" << std::endl;
    for (const auto& book : books) {
        std::cout << "Title: " << book.title << std::endl;
        std::cout << "Author: " << book.author << std::endl;
        std::cout << "Year: " << book.year << std::endl;
        std::cout << "Genre: " << book.genre << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}

std::vector<Book> ReadingLog::searchByAuthor(const std::string& author) const {
    std::vector<Book> result;
    for (const auto& book : books) {
        if (book.author == author) {
            result.push_back(book);
        }
    }
    return result;
}

std::vector<Book> ReadingLog::searchByTitle(const std::string& title) const {
    std::vector<Book> result;
    for (const auto& book : books) {
        if (book.title == title) {
            result.push_back(book);
        }
    }
    return result;
}

std::vector<Book> ReadingLog::findOldest(const int& year) const
{
    std::vector<Book> result;
    int min = 3000;
    for (const auto& book : books) {
        if (book.year < min) {
            min = book.year;
        }
    }
    for (const auto& book : books) {
        if (book.year == min) {
            result.push_back(book);
        }
    }
    return result;
}



void ReadingLog::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening file for writing.");
    }

    for (const auto& book : books) {
        file << book.to_json() << std::endl;
    }

    file.close();
    std::cout << "Reading Log saved successfully." << std::endl;
}

void ReadingLog::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening file for reading.");
    }

    books.clear();
    std::string line;
    while (std::getline(file, line)) {
        Book book = jsonToBook(line);
        books.push_back(book);
    }

    file.close();
    std::cout << "Reading Log loaded successfully." << std::endl;
}


void ReadingLog::createNewLog() {
    books.clear();
    std::cout << "New Reading Log created." << std::endl;
}