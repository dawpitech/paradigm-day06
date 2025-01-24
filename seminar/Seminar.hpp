/*
** EPITECH PROJECT, 2025
** seminar
** File description:
** Seminar.hpp
*/

#ifndef SEMINAR_HPP
    #define SEMINAR_HPP

    #include <vector>

    #include "Assistant.hpp"
    #include "Dean.hpp"

class Seminar
{
    public:
        explicit Seminar();
        void run();
        void addDean(Dean* dean);
        void addAssistant(Assistant* assistant);
        void addStudent(Student* student);

    protected:
        std::vector<Dean*> _dean;
        std::vector<Assistant*> _assistants;
        std::vector<Student*> _students;
};
#endif //SEMINAR_HPP
