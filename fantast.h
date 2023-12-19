#pragma once
#include <iostream>
#include <string>

#include "book.h"

class FantasyAuthor {
private:
    std::string fullName;
    std::string literaryWorks;
    bool moviesAdaptation;

public:
    // ����������� ��� ����������
    FantasyAuthor() {
        fullName = "Unknown";
        moviesAdaptation = false;
        std::cout << "Default constructor called for " << fullName << std::endl;
    }

    // ����������� � �����������
    FantasyAuthor(const std::string& newFullName, std::string& newLiteraryWorks, bool newMoviesAdaptation)
        : fullName(newFullName), literaryWorks(newLiteraryWorks), moviesAdaptation(newMoviesAdaptation) {
        std::cout << "Parametrized constructor called for " << fullName << std::endl;
    }

    // ����������� �����������
    FantasyAuthor(const FantasyAuthor& other)
        : fullName(other.fullName), literaryWorks(other.literaryWorks), moviesAdaptation(other.moviesAdaptation) {
        std::cout << "Copy constructor called for " << fullName << std::endl;
    }

    // ����������
    ~FantasyAuthor() {
        std::cout << "Destructor called for " << fullName << std::endl;
    }

    // ������ get � set
    std::string getFullName() {
        return fullName;
    }

    std::string getLiteraryWorks() const {
        return literaryWorks;
    }

    bool hasMoviesAdaptation() const {
        return moviesAdaptation;
    }

    void setFullName(const std::string& newFullName) {
        fullName = newFullName;
    }

    void setLiteraryWorks(std::string& newLiteraryWorks) {
        literaryWorks = newLiteraryWorks;
    }

    void setMoviesAdaptation(bool newMoviesAdaptation) {
        moviesAdaptation = newMoviesAdaptation;
    }
};