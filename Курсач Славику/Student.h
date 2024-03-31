// Класс Студента которий запозичує функціонал класу людини та розширює його новим функціоналом

#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person {
private:
    int studentID;
    double averageGrade;
    std::string VNZ;
    std::string faculty;
    std::string course;
    std::string group;

public:
    // Конструктори
    Student();
    Student(const std::string& sur, const std::string& first, const std::string& middle,
        const std::string& birthdate, const std::string& gen, const std::string& VNZ,
        const std::string& faculty, const std::string& course, const std::string& group,
        int id, double grade);
    Student(const Student& other);
    Student(Student&& other) noexcept;

    // Деструктор
    ~Student();

    // Методи
    void printInfo() const override;

    // Перегрузка операторів
    friend std::ostream& operator<<(std::ostream& out, const Student& student);
    Student& operator=(const Student& other);
    friend std::istream& operator>>(std::istream& in, Student& student);

    void operator()(const std::string& sur, const std::string& first, const std::string& middle,
        const std::string& birthdate, const std::string& gen, const std::string& vnz,
        const std::string& fac, const std::string& crs, const std::string& grp,
        int id, double grade);

    // Геттери
    std::string getVNZ() const;
    std::string getFaculty() const;
    std::string getCourse() const;
    std::string getGroup() const;
    int getStudentID() const;
    double getAverageGrade() const;

    // Сетери
    void setVNZ(const std::string& vnz);
    void setFaculty(const std::string& fac);
    void setCourse(const std::string& crs);
    void setGroup(const std::string& grp);
    void setStudentID(int id);
    void setAverageGrade(double grade);
};

#endif
