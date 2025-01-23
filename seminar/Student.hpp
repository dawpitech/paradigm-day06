/*
** EPITECH PROJECT, 2025
** ex3
** File description:
** Student.hpp
*/

#ifndef STUDENT_HPP
    #define STUDENT_HPP

    #include <string>

class Student {
    public:
        explicit Student(std::string name);
        ~Student();
        bool learn(std::string text);
        void drink(std::string drink_name);
        std::string getName() { return _name; }

    protected:
        std::string _name;
        unsigned int _energy;
};
#endif //STUDENT_HPP
