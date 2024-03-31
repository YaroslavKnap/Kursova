// Клас групи використовуємо для групування студентів в 1 масив та додаємо функціонал для зручної роботи з ним.

#pragma once
#ifndef GROUP_H
#define GROUP_H


#include <vector>
#include "Student.h"

// Клас – ітератор для класу Group
class GroupIterator {
private:
    vector<Student>::iterator it;  // Ітератор для перебору елементів вектора students

public:
    // Конструктор, що приймає вектор ітератора.
    GroupIterator(vector<Student>::iterator iterator);

    // Перевантаження оператора розіменування *
    // Цей оператор повертає посилання на поточний елемент вектора
    Student& operator*();

    // Перевантаження оператора інкременту ++
    // Цей оператор переміщує ітератор на наступний елемент вектора
    GroupIterator& operator++();

    // Перевантаження оператора нерівності !=
    // Цей оператор порівнює два ітератори на нерівність
    bool operator!=(const GroupIterator& other) const;
};

// Клас, який представляє групу студентів
class Group {
private:
    vector<Student> students;

public:
    Group();

    void addStudent(const Student& name);

    // Перенесення об'єкта в масив
    void addStudent(Student&& name);

    GroupIterator begin();

    GroupIterator end();

    // Метод для отримання студента за індексом
    Student& getStudent(int index);

    void showStudents();

    void showUnsatisfactoryStudents();

    // Перевантажений оператор виводу для класу Student
    friend ofstream& operator<<(ofstream& file, Group& student);

    // Метод для зчитування даних про студентів із файлу
    int readStudentsFromFile(const string& filename);
};

#endif