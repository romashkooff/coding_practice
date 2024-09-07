#include <iostream>
#include <stdexcept>

#include "book.h"
#include "ReadingLog.h"

ReadingLog readingLog;

int menu() {
    while (true) {
        std::cout << "1. Add Book\n";
        std::cout << "2. Print Reading Log\n";
        std::cout << "3. Search by Author\n";
        std::cout << "4. Search by Title\n";
        std::cout << "5. Save Reading Log\n";
        std::cout << "6. Open Reading Log\n";
        std::cout << "7. Create New Reading Log\n";
        std::cout << "8. Exit\n";
        std::cout << "9. Find the oldest book\n";
        std::cout << "------------------------" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        
        std::cout << "------------------------" << std::endl;

        switch (choice) {
        case 1: {
            std::string title, author, genre;
            int year;

            std::cout << "Enter Book Title: ";
            std::cin.ignore();
            std::getline(std::cin, title);

            std::cout << "Enter Author: ";
            std::getline(std::cin, author);

            std::cout << "Enter Year of Publication: ";
            std::cin >> year;

            std::cout << "Enter Genre: ";
            std::cin.ignore();
            std::getline(std::cin, genre);

            std::cout << "------------------------" << std::endl;

            Book book(title, author, year, genre);
            readingLog.addEntry(book);
            break;
        }
        case 2:
            readingLog.printLog();
            break;
        case 3: {
            std::string author;
            std::cout << "Enter Author to search: ";
            std::cin.ignore();
            std::getline(std::cin, author);

            auto result = readingLog.searchByAuthor(author);
            if (result.empty()) {
                std::cout << "No books found by the author." << std::endl;
            }
            else {
                for (const auto& book : result) {
                    std::cout << "Title: " << book.title << std::endl;
                    std::cout << "Year: " << book.year << std::endl;
                    std::cout << "Genre: " << book.genre << std::endl;
                    std::cout << "------------------------" << std::endl;
                }
            }
            break;
        }
        case 4: {
            std::string title;
            std::cout << "Enter Title to search: ";
            std::cin.ignore();
            std::getline(std::cin, title);

            auto result = readingLog.searchByTitle(title);
            if (result.empty()) {
                std::cout << "No books found with the title." << std::endl;
            }
            else {
                for (const auto& book : result) {
                    std::cout << "Author: " << book.author << std::endl;
                    std::cout << "Year: " << book.year << std::endl;
                    std::cout << "Genre: " << book.genre << std::endl;
                    std::cout << "------------------------" << std::endl;
                }
            }
            break;
        }
        case 5: {
            std::string filename;
            std::cout << "Enter filename to save: ";
            std::cin.ignore();
            std::getline(std::cin, filename);
            std::cout << "------------------------" << std::endl;
            try {
                readingLog.saveToFile(filename);
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            std::cout << "------------------------" << std::endl;

            break;
        }
        case 6: {
            std::string filename;
            std::cout << "Enter filename to open: ";
            std::cin.ignore();
            std::getline(std::cin, filename);
            std::cout << "------------------------" << std::endl;

            try {
                readingLog.loadFromFile(filename);
                std::cout << "------------------------" << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            break;
        }
        case 7:
            readingLog.createNewLog();
            std::cout << "------------------------" << std::endl;

            break;
        case 8:
            std::cout << "Exiting program." << std::endl;
            return 0;
        case 9: {
            int year;
            auto result = readingLog.findOldest(year);
            if (result.empty()) {
                std::cout << "No books found in list." << std::endl;
            }
            else {
                for (const auto& book : result) {
                    std::cout << "Author: " << book.author << std::endl;
                    std::cout << "Year: " << book.year << std::endl;
                    std::cout << "Genre: " << book.genre << std::endl;
                    std::cout << "------------------------" << std::endl;
                }
            }
            break;
        }
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
            std::cout << "------------------------" << std::endl;
        }
        
    }
}

int main() {
    menu();

    return 0;
}