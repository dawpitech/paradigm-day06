/*
** EPITECH PROJECT, 2025
** seminar
** File description:
** Assistant.hpp
*/

#ifndef ASSISTANT_HPP
    #define ASSISTANT_HPP

    #include <Student.hpp>

class Assistant {
    public:
        explicit Assistant(int id);
        ~Assistant();
        void giveDrink(Student* student, std::string drink_name);
        std::string readDrink(Student* student);
        void helpStudent(Student* student);
        void timeCheck();

    protected:
        int _id;
        bool _is_working = false;
};
#endif //ASSISTANT_HPP
