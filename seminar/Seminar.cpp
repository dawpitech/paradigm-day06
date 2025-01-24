/*
** EPITECH PROJECT, 2025
** seminar
** File description:
** Seminar.cpp
*/

#include <iostream>
#include <format>

#include "Seminar.hpp"

Seminar::Seminar() = default;

void Seminar::addDean(Dean* dean)
{
    if (dean == nullptr)
        return;
    if (this->_dean.size() == 1) {
        std::cout << "Seminar: There can only be one Dean of Studies." << std::endl;
        return;
    }
    this->_dean.push_back(dean);
    std::cout << std::format("Seminar: Dean {} is here.", dean->getName()) << std::endl;
}

void Seminar::addAssistant(Assistant* assistant)
{
    if (assistant == nullptr)
        return;
    for (const auto & _assistant : this->_assistants) {
        if (assistant->getId() == _assistant->getId()) {
            std::cout << std::format("Seminar: Assistant {} is already registered.",
                _assistant->getId()) << std::endl;
            return;
        }
    }
    if (this->_assistants.size() == 2) {
        std::cout << "Seminar: There is only room for two Teaching Assistants." << std::endl;
        return;
    }
    this->_assistants.push_back(assistant);
    std::cout << std::format("Seminar: Assistant {} joined the pedagogical team.",
        assistant->getId()) << std::endl;
}

void Seminar::addStudent(Student* student)
{
    if (student == nullptr)
        return;
    for (const auto & _student : this->_students) {
        if (student->getName() == _student->getName()) {
            std::cout << std::format("Seminar: Student {} is already registered.",
                student->getName()) << std::endl;
            return;
        }
    }
    if (this->_students.size() == 5) {
        std::cout << "Seminar: There is only room for five Students." << std::endl;
        return;
    }
    this->_students.push_back(student);
    std::cout << std::format("Seminar: Student {} joined the seminar.",
        student->getName()) << std::endl;
}

void Seminar::run()
{
    if (this->_dean.empty() || this->_assistants.empty() ||
        this->_students.empty()) {
        std::cout << "Seminar: A C++ seminar needs at least one Dean of Studies, one Assistant and one Student." << std::endl;
        return;
    }

    std::cout << "Seminar: Begining 6th day of seminar." << std::endl;

    std::cout << std::format("Dean of Studies: {}",
        this->_dean.front()->getName()) << std::endl;

    std::cout << "Teaching assistants:";
    for (std::vector<Assistant*>::size_type i = 0; i < this->_assistants.size(); i++) {
        if (i != 0)
            std::cout << ", ";
        else
            std::cout << " ";
       std::cout << this->_assistants.at(i)->getId();
    }

    std::cout << std::endl << "Students:";
    for (std::vector<Student*>::size_type i = 0; i < this->_students.size(); i++) {
        if (i != 0)
            std::cout << ", ";
        else
            std::cout << " ";
        std::cout << this->_students.at(i)->getName();
    }
    std::cout << std::endl;

    this->_dean.front()->timeCheck();
    for (const auto & _assistant : this->_assistants) {
        _assistant->timeCheck();
    }

    int crr_aer = 0;
    for (int day = 0; day < 5; day++) {
        for (const auto & _student : this->_students) {
            this->_dean.front()->teachStudent(_student, "I'm learning C++!");
            this->_assistants.at(crr_aer)->helpStudent(_student);
            if (this->_assistants.size() == 2) {
                if (crr_aer == 0)
                    crr_aer = 1;
                else
                    crr_aer = 0;
            }
        }
    }

    this->_dean.front()->timeCheck();
    for (const auto & _assistant : this->_assistants) {
        _assistant->timeCheck();
    }
}
