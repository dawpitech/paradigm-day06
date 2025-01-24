/*
** EPITECH PROJECT, 2025
** seminar
** File description:
** Dean.cpp
*/

#include "Dean.hpp"

#include <format>
#include <fstream>
#include <iostream>

Dean::Dean(std::string name)
{
    this->_name = name;
    std::cout << std::format("Dean {}: I'm Dean {}! How do you do, "
        "fellow kids?\n", this->_name, this->_name);
}

Dean::~Dean()
{
    std::cout << std::format("Dean {}: Time to go home.\n",
        this->_name);
}

void Dean::teachStudent(Student* student, std::string lesson)
{
    if (student == nullptr) return;
    if (student->learn(lesson)) return;

    std::cout << std::format("Dean {}: All work and no play makes {} "
        "a dull student.\n", this->_name, student->getName());
    std::ofstream file_stream(student->getName() + ".drink", std::ios::binary);

    std::string drink_name;
    switch (std::rand() % 5) { // NOLINT(*-msc50-cpp)
        default:
        case 0:
            drink_name = "Cristaline";
            break;
        case 1:
            drink_name = "Monster";
            break;
        case 2:
            drink_name = "Evian";
            break;
        case 3:
            drink_name = "Red Bull";
            break;
        case 4:
            drink_name = "Sierra Springs";
            break;
    }


    if (!file_stream.is_open()) return;
    file_stream.write(drink_name.c_str(), drink_name.size());
    file_stream.close();
}

void Dean::timeCheck()
{
    if (!this->_is_working)
        std::cout << std::format("Dean {}: Where is everyone?\n",
            this->_name);
    else
        std::cout << std::format("Dean {}: Don't forget to close the windows "
            "when you leave.\n", this->_name);
    this->_is_working = !this->_is_working;
}
