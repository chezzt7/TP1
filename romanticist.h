#pragma once

#include "book.h"

#include <iostream>
#include <string>


class Romanticist : public Book {
private:
    std::string fullName;
    std::string lifeYears;
    std::string literaryWorks;
    std::string biography;

public:
    // Конструктор без параметров
    Romanticist() {
        fullName = "Unknown";
        lifeYears = "Unknown";
        biography = "No biography available";
        std::cout << "Default constructor called for " << fullName << std::endl;
    }

    // Конструктор с параметрами
    Romanticist(const std::string& newFullName, const std::string& newLifeYears, std::string& newLiteraryWorks, const std::string& newBiography)
        : fullName(newFullName), lifeYears(newLifeYears), literaryWorks(newLiteraryWorks), biography(newBiography) {
        std::cout << "Parametrized constructor called for " << fullName << std::endl;
    }

    // Конструктор копирования
    Romanticist(const Romanticist& other)
        : fullName(other.fullName), lifeYears(other.lifeYears), literaryWorks(other.literaryWorks), biography(other.biography) {
        std::cout << "Copy constructor called for " << fullName << std::endl;
    }

    // Деструктор
    ~Romanticist() {
        std::cout << "Destructor called for " << fullName << std::endl;
    }

    // Методы get и set
    std::string getFullName() {
        return fullName;
    }

    std::string getLifeYears() const {
        return lifeYears;
    }

    std::string getLiteraryWorks() const {
        return literaryWorks;
    }

    std::string getBiography() const {
        return biography;
    }

    void setFullName(const std::string& newFullName) {
        fullName = newFullName;
    }

    void setLifeYears(const std::string& newLifeYears) {
        lifeYears = newLifeYears;
    }

    void setLiteraryWorks(std::string& newLiteraryWorks) {
        literaryWorks = newLiteraryWorks;
    }

    void setBiography(const std::string& newBiography) {
        biography = newBiography;
    }
};