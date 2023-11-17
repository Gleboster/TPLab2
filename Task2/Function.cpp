
#include "Function.h"

namespace Task2 {

    const string green = "\033[32m";
    const string red = "\033[31m";
    const string reset = "\033[0m";


    void printLineFromFile(std::string fileName) {
        ifstream file(fileName);

        if (file.is_open()) {
            std::string line;
            bool outputedOne = false;
            std::cout << green;
            while (std::getline(file, line)) {
                if (!hasDoubleDigit(line)) {
                    std::cout << line << std::endl;
                    outputedOne = true;
                }
            }
            std::cout << reset;

            if (!outputedOne)
                std::cout << red << "in file \"" << fileName << "\" there are no strings matching the condition"
                          << reset << std::endl;

            file.close(); // Закрытие файла
        } else {
            std::cout << red << "Could not open file." << reset << std::endl;
        }
    }

    bool hasDoubleDigit(std::string line) {

        std::stringstream sLine(line);

        int number;
        bool hasDoubleDigit = false;

        while (sLine >> line) {
            try {
                number = stoi(line);
            }
            catch (invalid_argument e) {
                continue;
            }

            if (line.length() == 2 && line[0] - '0' == number / 10 && line[1] - '0' == number % 10)
                return true;
        }
        return false;
    }

}
