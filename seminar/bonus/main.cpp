/*
** EPITECH PROJECT, 2025
** ex3
** File description:
** main.cpp
*/

#include "Student.hpp"

int main()
{
    Student student("John");

    for (int i = 0; i < 3; i++)
        student.learn("C++, more C++, don't ever stop C++.");
    student.drink("Red Bull");
    student.drink("Monster");
    student.drink("Toilet Water");
    student.learn("Wow, C++ look sooo cool");
    return 0;
}
