#pragma once
#include "Group.h"

// Конструктор, що приймає вектор ітератора.
GroupIterator::GroupIterator(vector<Student>::iterator iterator) : it(iterator) {}

// Перевантаження оператора розіменування *
// Цей оператор повертає посилання на поточний елемент вектора
Student& GroupIterator::operator*() {
    return *it;
}

// Перевантаження оператора інкременту++
// Цей оператор переміщує ітератор на наступний елемент вектора
GroupIterator& GroupIterator::operator++() {
    ++it;
    return *this;
}

// Перевантаження оператора нерівності !=
// Цей оператор порівнює два ітератори на нерівність
bool GroupIterator::operator!=(const GroupIterator& other) const {
    return it != other.it;
}

// Конструктор за замовчуванням
Group::Group() {}

// Додає студента до масиву
void Group::addStudent(const Student& name) {
    students.push_back(name);
}

// Перенесення об'єкта в масив
void Group::addStudent(Student&& name) {
    students.push_back(move(name));
}

// Поверне початок масиву
GroupIterator Group::begin() {
    return GroupIterator(students.begin());
}

// Поверне кінець масиву
GroupIterator Group::end() {
    return GroupIterator(students.end());
}

// Метод для отримання студента за індексом
Student& Group::getStudent(int index) {
    if (index >= 0 && index < students.size()) {
        return students[index];
    }
    else {
        // Повертаємо першого студента, якщо індекс некоректний
        cout << "Index out of range, returning the first student." << endl;
        return students[0];
    }
}

// Вивести інформацію про студентів
void Group::showStudents() {
    cout << "-----------Cписок студентов------------" << endl;
    cout << "|                                     |" << endl;
    cout << "V                                     V" << endl;
    for (GroupIterator it = students.begin(); it != students.end(); ++it) {
        cout << "=======================================" << endl;
        Student& student = *it;
        student.printInfo();
        cout << "=======================================" << endl;
    }
    cout << "---------------------------------------" << endl;
}

// Вивести інформацію про студентів з незадовільною оцінкою
void Group::showUnsatisfactoryStudents() {
    cout << "-Ученики с неудолетворительными оценками-" << endl;
    cout << "|                                       |" << endl;
    cout << "V                                       V" << endl;
    for (GroupIterator it = students.begin(); it != students.end(); ++it) {
        Student& student = *it;
        if (student.getAverageGrade() < 60) {
            cout << "=========================================" << endl;
            student.printInfo();
            cout << "=========================================" << endl;
        }
    }
    cout << "-----------------------------------------" << endl;
}

// Перевантажений оператор виводу для класу Student
ofstream& operator<<(ofstream& file, Group& student) {
    for (GroupIterator it = student.students.begin(); it != student.students.end(); ++it) {
        Student& student = *it;
        file << student;
    }
    cout << "Done file.\n";
    return file;
}

// Метод для зчитування даних про студентів із файлу
int Group::readStudentsFromFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        throw "Помилка відкриття файлу для читання!";
        return 1;
    }

    while (true) {
        string lastName, firstName, middleName, birthdate, gender, university, faculty, group, course;
        double averageGrade;
        int studentID;

        // Зчитуємо дані кожного студента із файлу
        if (!(file >> lastName >> firstName >> middleName >> birthdate >> gender
            >> university >> faculty >> course >> group >> studentID >> averageGrade)) {
            break; // Припиняємо цикл якщо не вдалося рахувати дані
        }

        Student a(lastName, firstName, middleName, birthdate, gender,
            university, faculty, course, group, studentID, averageGrade);

        this->addStudent(move(a));
    }

    // Чистимо консоль
    system("cls");

    file.close();
    return 0;
}

