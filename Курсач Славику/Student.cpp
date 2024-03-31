#pragma once
#include "Student.h"

// ����������� �� �������������, �������� studentID � averageGrade ��������� ����������
Student::Student() : studentID(0), averageGrade(0) {}

// ����������� �� �����������, �������� �� ���� ����� Student
Student::Student(const string& sur, const string& first, const string& middle,
    const string& birthdate, const string& gen, const string& VNZ,
    const string& faculty, const string& course, const string& group, int id, double grade)
    :Person(sur, first, middle, birthdate, gen) {
    this->VNZ = VNZ;
    this->faculty = faculty;
    this->course = course;
    this->group = group;
    studentID = id;
    averageGrade = grade;
}

// ����������� ��������� ����� �� ���� � ������ ��'���� Student
Student::Student(const Student& other)
    :Person(other), VNZ(other.VNZ), faculty(other.faculty), course(other.course),
    group(other.group), studentID(other.studentID), averageGrade(other.averageGrade) {}

// ����������� ����������, ������� ������� �� ����� ��'��� Student
Student::Student(Student&& other) noexcept
    :Person(move(other)), VNZ(move(other.VNZ)), faculty(move(other.faculty)),
    course(move(other.course)), group(move(other.group)),
    studentID(move(other.studentID)), averageGrade(move(other.averageGrade)) {}

// �� ������������� ����������
Student::~Student() {}

// ��������� ���������� ��� �������� � �������
void Student::printInfo() const {
    Person::printInfo();
    cout << "����� ���: " << VNZ << endl;
    cout << "���������: " << faculty << endl;
    cout << "����: " << course << endl;
    cout << "�����: " << group << endl;
    cout << "������������ ID: " << studentID << endl;
    cout << "������� ���: " << averageGrade << endl;
}

// �������������� ��������� ������ ��� ����� Student
ostream& operator<<(ostream& out, const Student& student) {
    out << static_cast<const Person&>(student);
    out << student.VNZ << endl;
    out << student.faculty << endl;
    out << student.course << endl;
    out << student.group << endl;
    out << student.studentID << endl;
    out << student.averageGrade << endl;
    return out;
}

// �������������� ��������� ��������� ��� �����Student
Student& Student::operator=(const Student& other) {
    if (this == &other) {
        return *this;
    }
    Person::operator=(other);
    studentID = other.studentID;
    averageGrade = other.averageGrade;
    VNZ = other.VNZ;
    faculty = other.faculty;
    course = other.course;
    group = other.group;
    return *this;
}

// �������������� ��������� �������� ��� ����� Student
istream& operator>>(istream& in, Student& student) {
    in >> static_cast<Person&>(student);
    in >> student.VNZ;
    in >> student.faculty;
    in >> student.course;
    in >> student.group;
    in >> student.studentID;
    in >> student.averageGrade;
    return in;
}

// �������������� ��������� () ��� ����� Student, ��������������� ��� ���� ������� ����
void Student::operator()(const string& sur, const string& first, const string& middle,
    const string& birthdate, const string& gen, const string& vnz, const string& fac,
    const string& crs, const string& grp, int id, double grade) {
    Person::operator()(sur, first, middle, birthdate, gen);
    studentID = id;
    averageGrade = grade;
    VNZ = vnz;
    faculty = fac;
    course = crs;
    group = grp;
}

// ������ ��� ��������� ������� ����
string Student::getVNZ() const { return VNZ; }
string Student::getFaculty() const { return faculty; }
string Student::getCourse() const { return course; }
string Student::getGroup() const { return group; }
int Student::getStudentID() const { return studentID; }
double Student::getAverageGrade() const { return averageGrade; }

// ������ ��� ������������ ������� ����
void Student::setVNZ(const std::string& vnz) { VNZ = vnz; }
void Student::setFaculty(const std::string& fac) { faculty = fac; }
void Student::setCourse(const std::string& crs) { course = crs; }
void Student::setGroup(const std::string& grp) { group = grp; }
void Student::setStudentID(int id) { studentID = id; }
void Student::setAverageGrade(double grade) { averageGrade = grade; }
