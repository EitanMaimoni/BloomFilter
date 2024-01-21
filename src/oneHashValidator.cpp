#include "oneHashValidator.h"
#include <iostream>
#include <sstream>
#include <vector>

// Default constructor
oneHashValidator::oneHashValidator() {
    
}

std::vector<std::string> oneHashValidator::validationCheck(std::string& line) {
    std::vector<std::string> result(2);
    std::vector<std::string> unValid(0);

    std::istringstream iss(line);
        
    

    try {
    if (!(iss >> result[0] >> result[1]) || (std::stoi(result[0]) <= 0) || (result[1] != "1" && result[1] != "2")) {
        // X is not > 0 or Y is not 1 or 2
        return unValid;
    }

    // If we get here, we successfully read X, Y
    return result;
    } catch (std::invalid_argument& e) {
        // result[0] could not be converted to an integer
        return unValid;
    }
};

