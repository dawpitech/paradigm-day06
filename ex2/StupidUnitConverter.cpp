/*
** EPITECH PROJECT, 2025
** ex2
** File description:
** StupidUnitConverter.cpp
*/

#include <format>
#include <iomanip>
#include <iostream>

static float FToC(const float celsius_temp)
{
    return 5.0f / 9.0f * ( celsius_temp - 32.0f);
}

static float CToF(const float fahrenheit_temp)
{
    return (9 * fahrenheit_temp + 160) / 5;
}

int main()
{
    std::string input;
    std::string unit;
    float temp;

    while (std::getline(std::cin >> std::ws, input)) {
        std::stringstream(input) >> temp >> unit;

        if (unit == "Celsius") {
            unit = "Fahrenheit";
            temp = CToF(temp);
        } else if (unit == "Fahrenheit") {
            unit = "Celsius";
            temp = FToC(temp);
        } else
            continue;

        std::cout << std::fixed
            << std::setprecision(3)
            << std::setw(16)
            << temp
            << std::setw(16)
            << unit
            << std::endl;
        unit.clear();
    }
    return 0;
}
