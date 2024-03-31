//Класс людини який ми юзаємо тільки для наслідування

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Person {
protected:
    string surname;
    string firstName;
    string middleName;
    string birthDate;
    string gender;

public:
    // Конструктори
    Person();
    Person(const string& sur, const string& first, const string& middle, const string& birthdate, const string& gen);
    Person(const Person& other);
    Person(Person&& other) noexcept;

    // Деструктор
    ~Person();

    // Сетеры
    void setSurname(const string& sur);
    void setFirstName(const string& first);
    void setMiddleName(const string& middle);
    void setBirthDate(const string& birthdate);
    void setGender(const string& gen);

    // Геттери
    string getSurname() const;
    string getFirstName() const;
    string getMiddleName() const;
    string getBirthDate() const;
    string getGender() const;

    // Методи
    virtual void printInfo() const;

    // Перегрузка операторів
    void operator()(const string& sur, const string& first, const string& middle,
        const string& birthdate, const string& gen);
    Person& operator=(const Person& other);
    Person& operator=(Person&& other) noexcept;

    // Потокові операції
    friend ostream& operator<<(ostream& out, const Person& person);
    friend istream& operator>>(istream& in, Person& person);
};

#endif