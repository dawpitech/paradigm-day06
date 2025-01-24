/*
** EPITECH PROJECT, 2025
** seminar
** File description:
** Assistant.hpp
*/

#ifndef ASSISTANT_HPP
    #define ASSISTANT_HPP

    #include "Student.hpp"

class Assistant {
    public:
        explicit Assistant(int id);
        ~Assistant();
        void giveDrink(Student* student, std::string drink_name);
        std::string readDrink(std::string student_name);
        void helpStudent(Student* student);
        void timeCheck();
        int getId() const { return _id; }

    protected:
        int _id;
        bool _is_working = false;
};
#endif //ASSISTANT_HPP
