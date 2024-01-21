#include "commandValidator.h"
#include <iostream>
#include <sstream>
#include <vector>

// Default constructor
commandValidator::commandValidator() {
    
};

std::vector<std::string> commandValidator::validationCheck(std::string& line) {
    std::vector<std::string> result(2);
    std::vector<std::string> unValid(0);

    std::istringstream iss(line);


    if (!(iss >> result[0] >> result[1])|| (result[0] != "1" && result[0] != "2") || (result[1].length() == 0)) {
        // Extraction failed or not all values were present
        return unValid;
    }

    // If we get here, we successfully read x and url
    return result;
        
};
