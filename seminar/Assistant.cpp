/*
** EPITECH PROJECT, 2025
** seminar
** File description:
** Assistant.cpp
*/

#include <iostream>
#include <format>
#include <fstream>

#include "Assistant.hpp"

Assistant::Assistant(int id)
{
    this->_id = id;
    std::cout << std::format("Assistant {}: 'morning everyone *sip coffee*\n",
        this->_id);
}

Assistant::~Assistant()
{
    std::cout << std::format("Assistant {}: see you tomorrow at 9.00 *sip "
        "coffee*\n", this->_id);
}

void Assistant::timeCheck()
{
    if (this->_is_working)
        std::cout << std::format("Assistant {}: Enough teaching for today *sip coffee*\n",
            this->_id);
    else
        std::cout << std::format("Assistant {}: Time to teach some serious "
            "business *sip coffee*\n", this->_id);
    this->_is_working = !this->_is_working;
}

void Assistant::giveDrink(Student* student, std::string drink_name)
{
    if (student == nullptr)
        return;
    std::cout << std::format("Assistant {}: drink this, {} *sip coffee*\n",
        this->_id, student->getName());
    student->drink(drink_name);
}

std::string Assistant::readDrink(std::string student_name)
{
    std::ifstream file_stream(student_name + ".drink", std::ios::in |
        std::ios::ate);

    if (!file_stream.is_open())
        return "";
    const auto size = file_stream.tellg();
    std::string content(size, '\0');
    file_stream.seekg(0);
    file_stream.read(&content[0], size);
    file_stream.close();
    std::cout << std::format("Assistant {}: {} needs a {} *sip coffee*\n",
        this->_id,student_name, content);
    return content;
}

void Assistant::helpStudent(Student* student)
{
    if (student == nullptr)
        return;
    const std::string drink = this->readDrink(student->getName());
    if (drink.empty()) {
        std::cout << std::format("Assistant {}: {} seems fine *sip coffee*\n",
            this->_id, student->getName());
        return;
    }
    this->giveDrink(student, drink);
}
