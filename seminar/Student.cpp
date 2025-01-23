/*
** EPITECH PROJECT, 2025
** ex3
** File description:
** Student.cpp
*/

#include <format>
#include <iostream>

#include "Student.hpp"

Student::Student(std::string name)
{
    this->_energy = 100;
    this->_name = name;
    std::cout << std::format("Student {}: I'm ready to learn C++.\n", name);
}

Student::~Student()
{
    std::cout << std::format("Student {}: Wow, much learning today, very "
        "smart, such C++.\n", this->_name);
}

bool Student::learn(std::string text)
{
    if (this->_energy < 42) {
        while (text.find("C++") != std::string::npos)
            text.replace(text.find("C++"), 3, "shit");
        std::cout << std::format("Student {}: {}\n", this->_name, text);
        return false;
    }
    std::cout << std::format("Student {}: {}\n", this->_name, text);
    this->_energy -= 42;
    return true;
}

void Student::drink(std::string drink_name)
{
    std::string msg = "ah, yes... enslaved moisture.";
    int energy = 1;

    if (drink_name == "Red Bull") {
        msg = "Red Bull gives you wings!";
        energy = 32;
    } else if (drink_name == "Monster") {
        msg = "Unleash The Beast!";
        energy = 64;
    }
    this->_energy += energy;
    std::cout << std::format("Student {}: {}\n", this->_name, msg);
}
