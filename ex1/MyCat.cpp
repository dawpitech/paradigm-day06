/*
** EPITECH PROJECT, 2025
** ex1
** File description:
** MyCat.cpp
*/

#include <format>
#include <fstream>
#include <iostream>
#include <string>

static int printError(const std::string& str)
{
    std::cerr << std::format("MyCat: {}: No such file or directory\n", str);
    return 84;
}

[[noreturn]] static void printStdoutStraight()
{
    std::string input;

    while (true) {
        std::getline(std::cin, input);
        std::cout << input << std::endl;
    }
}

static int printFileContent(const std::string &file_path)
{
    std::ifstream file_stream(file_path, std::ios::in | std::ios::ate);

    if (!file_stream.is_open())
        return printError(file_path);
    const auto size = file_stream.tellg();
    std::string str(size, '\0');
    file_stream.seekg(0);
    if (file_stream.read(&str[0], size))
        std::cout << str;
    file_stream.close();
    return 0;
}

static int printFilesContent(const int nb, char *files[])
{
    int rt_value = 0;

    for (int i = 0; i < nb; i++)
    {
        rt_value |= printFileContent(files[i]);
    }
    return rt_value;
}

int main(const int argc, char *argv[])
{
    if (argc == 1)
        printStdoutStraight();
    return printFilesContent(argc - 1, &argv[1]);
}
