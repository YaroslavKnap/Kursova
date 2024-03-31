#pragma once

#include "Person.h"

// Конструктор за замовчуванням
Person::Person() : surname("Не визначено"), firstName("Не визначено"), middleName("Не визначено"),
birthDate("Не визначено"), gender("Не визначено") {}

// Конструктор з параметрами
Person::Person(const string& sur, const string& first, const string& middle, const string& birthdate, const string& gen)
    : surname(sur), firstName(first), middleName(middle), birthDate(birthdate), gender(gen) {}

// Конструктор копіювання
Person::Person(const Person& other)
    : surname(other.surname), firstName(other.firstName), middleName(other.middleName),
    birthDate(other.birthDate), gender(other.gender) {}

// Конструктор переміщення
Person::Person(Person&& other) noexcept
    : surname(move(other.surname)), firstName(move(other.firstName)),
    middleName(move(other.middleName)), birthDate(move(other.birthDate)),
    gender(move(other.gender)) {}

// Деструктор
Person::~Person() {
    cout << firstName << " видалений!\n";
}

// Сетери для безпечного запису даних
void Person::setSurname(const string& sur) { surname = sur; }
void Person::setFirstName(const string& first) { firstName = first; }
void Person::setMiddleName(const string& middle) { middleName = middle; }
void Person::setBirthDate(const string& birthdate) { birthDate = birthdate; }
void Person::setGender(const string& gen) { gender = gen; }

// Геттери для безпечного отримання даних
string Person::getSurname() const { return surname; }
string Person::getFirstName() const { return firstName; }
string Person::getMiddleName() const { return middleName; }
string Person::getBirthDate() const { return birthDate; }
string Person::getGender() const { return gender; }

// Метод для виведення інформації про особу
void Person::printInfo() const {
    cout << "ПІБ: " << firstName << " " << middleName << " " << surname << endl;
    cout << "Дата народження: " << birthDate << endl;
    cout << "Стать: " << gender << endl;
}

// Перевантаження оператора ()
void Person::operator()(const string& sur, const string& first, const string& middle,
    const string& birthdate, const string& gen) {
    surname = sur;
    firstName = first;
    middleName = middle;
    birthDate = birthdate;
    gender = gen;
}

// Перевантаження оператора =
Person& Person::operator=(const Person& other) {
    if (this == &other) {
        return *this;
    }

    surname = other.surname;
    firstName = other.firstName;
    middleName = other.middleName;
    birthDate = other.birthDate;
    gender = other.gender;

    return *this;
}

// Перевантаження оператора переміщення =
Person& Person::operator=(Person&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    surname = move(other.surname);
    firstName = move(other.firstName);
    middleName = move(other.middleName);
    birthDate = move(other.birthDate);
    gender = move(other.gender);

    return *this;
}

// Потокові операції введення » та виведення « об'єктів
ostream& operator<<(ostream& out, const Person& person) {
    out << person.surname << endl;
    out << person.firstName << endl;
    out << person.middleName << endl;
    out << person.birthDate << endl;
    out << person.gender << endl;
    return out;
}

istream& operator>>(istream& in, Person& person) {
    in >> person.surname;
    in >> person.firstName;
    in >> person.middleName;
    in >> person.birthDate;
    in >> person.gender;
    return in;
}
