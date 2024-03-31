// ���� ����� ������������� ��� ���������� �������� � 1 ����� �� ������ ���������� ��� ������ ������ � ���.

#pragma once
#ifndef GROUP_H
#define GROUP_H


#include <vector>
#include "Student.h"

// ���� � �������� ��� ����� Group
class GroupIterator {
private:
    vector<Student>::iterator it;  // �������� ��� �������� �������� ������� students

public:
    // �����������, �� ������ ������ ���������.
    GroupIterator(vector<Student>::iterator iterator);

    // �������������� ��������� ������������ *
    // ��� �������� ������� ��������� �� �������� ������� �������
    Student& operator*();

    // �������������� ��������� ���������� ++
    // ��� �������� ������� �������� �� ��������� ������� �������
    GroupIterator& operator++();

    // �������������� ��������� �������� !=
    // ��� �������� ������� ��� ��������� �� ��������
    bool operator!=(const GroupIterator& other) const;
};

// ����, ���� ����������� ����� ��������
class Group {
private:
    vector<Student> students;

public:
    Group();

    void addStudent(const Student& name);

    // ����������� ��'���� � �����
    void addStudent(Student&& name);

    GroupIterator begin();

    GroupIterator end();

    // ����� ��� ��������� �������� �� ��������
    Student& getStudent(int index);

    void showStudents();

    void showUnsatisfactoryStudents();

    // �������������� �������� ������ ��� ����� Student
    friend ofstream& operator<<(ofstream& file, Group& student);

    // ����� ��� ���������� ����� ��� �������� �� �����
    int readStudentsFromFile(const string& filename);
};

#endif