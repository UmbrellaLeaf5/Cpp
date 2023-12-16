#include <fstream>
#include <iostream>
#include <string>  // для std::getline

int main ()
{
    std::string line;
    std::string path = "input.txt";
    std::fstream input(path);
    if (input.is_open())
    {
        std::cout << path + " is open" << std::endl;
        while (std::getline(input, line))
        {
            std::cout << line << std::endl;
            try
            {
                input << std::endl << std::to_string(stoi(line) + 1);
            }
            catch (std::exception& e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    }
    input.close();  // закрываем файл
}