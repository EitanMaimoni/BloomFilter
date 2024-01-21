#include "twoHashValidator.h"
#include <iostream>
#include <sstream>
#include <vector>

// Default constructor
twoHashValidator::twoHashValidator() {
    
};

std::vector<std::string> twoHashValidator::validationCheck(std::string& line) {
    std::vector<std::string> result(3);
    std::vector<std::string> unValid(0);

    std::istringstream iss(line);

    try {
    if (iss >> result[0] >> result[1]) {
        if (std::stoi(result[0]) <= 0 || (result[1] != "1" && result[1] != "2")) {
            // X is not > 0 or Y is not 1 or 2
            return unValid;
        }

        while (iss >> result[2]) {
            if ((result[2] == "1" || result[2] == "2") && result[2] != result[1]) {
                // If we get here, we successfully read X, Y, and Z
                return result;
            }
        }
    }
    return unValid;
    } catch (std::invalid_argument& e) {
        // result[0] could not be converted to an integer
        return unValid;
    }
        
    
};