/*
** EPITECH PROJECT, 2025
** seminar
** File description:
** Dean.hpp
*/

#ifndef DEAN_HPP
    #define DEAN_HPP

    #include "Student.hpp"

class Dean {
    public:
        explicit Dean(std::string name);
        ~Dean();
        void teachStudent(Student* student, std::string lesson);
        void timeCheck();
        std::string getName() { return _name; }

    protected:
        std::string _name;
        bool _is_working = false;
};
#endif //DEAN_HPP
