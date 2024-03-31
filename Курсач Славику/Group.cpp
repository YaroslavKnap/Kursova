#pragma once
#include "Group.h"

// �����������, �� ������ ������ ���������.
GroupIterator::GroupIterator(vector<Student>::iterator iterator) : it(iterator) {}

// �������������� ��������� ������������ *
// ��� �������� ������� ��������� �� �������� ������� �������
Student& GroupIterator::operator*() {
    return *it;
}

// �������������� ��������� ����������++
// ��� �������� ������� �������� �� ��������� ������� �������
GroupIterator& GroupIterator::operator++() {
    ++it;
    return *this;
}

// �������������� ��������� �������� !=
// ��� �������� ������� ��� ��������� �� ��������
bool GroupIterator::operator!=(const GroupIterator& other) const {
    return it != other.it;
}

// ����������� �� �������������
Group::Group() {}

// ���� �������� �� ������
void Group::addStudent(const Student& name) {
    students.push_back(name);
}

// ����������� ��'���� � �����
void Group::addStudent(Student&& name) {
    students.push_back(move(name));
}

// ������� ������� ������
GroupIterator Group::begin() {
    return GroupIterator(students.begin());
}

// ������� ����� ������
GroupIterator Group::end() {
    return GroupIterator(students.end());
}

// ����� ��� ��������� �������� �� ��������
Student& Group::getStudent(int index) {
    if (index >= 0 && index < students.size()) {
        return students[index];
    }
    else {
        // ��������� ������� ��������, ���� ������ �����������
        cout << "Index out of range, returning the first student." << endl;
        return students[0];
    }
}

// ������� ���������� ��� ��������
void Group::showStudents() {
    cout << "-----------C����� ���������------------" << endl;
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

// ������� ���������� ��� �������� � ������������ �������
void Group::showUnsatisfactoryStudents() {
    cout << "-������� � �������������������� ��������-" << endl;
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

// �������������� �������� ������ ��� ����� Student
ofstream& operator<<(ofstream& file, Group& student) {
    for (GroupIterator it = student.students.begin(); it != student.students.end(); ++it) {
        Student& student = *it;
        file << student;
    }
    cout << "Done file.\n";
    return file;
}

// ����� ��� ���������� ����� ��� �������� �� �����
int Group::readStudentsFromFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        throw "������� �������� ����� ��� �������!";
        return 1;
    }

    while (true) {
        string lastName, firstName, middleName, birthdate, gender, university, faculty, group, course;
        double averageGrade;
        int studentID;

        // ������� ��� ������� �������� �� �����
        if (!(file >> lastName >> firstName >> middleName >> birthdate >> gender
            >> university >> faculty >> course >> group >> studentID >> averageGrade)) {
            break; // ���������� ���� ���� �� ������� �������� ���
        }

        Student a(lastName, firstName, middleName, birthdate, gender,
            university, faculty, course, group, studentID, averageGrade);

        this->addStudent(move(a));
    }

    // ������� �������
    system("cls");

    file.close();
    return 0;
}

