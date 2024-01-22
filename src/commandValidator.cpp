#include "commandValidator.h"
#include <iostream>
#include <sstream>
#include <vector>

// Default constructor
commandValidator::commandValidator() {
    
};

std::vector<std::string> commandValidator::validationCheck(std::string& line) {

    // Create a vector to store the result
    std::vector<std::string> result(2);
    // Create an empty vector of strings to return if the input is invalid
    std::vector<std::string> unValid(0);

    // Create a string stream to read the input
    std::istringstream iss(line);

    // Try to read x and url
    if (!(iss >> result[0] >> result[1])|| (result[0] != "1" && result[0] != "2") || (result[1].length() == 0)) {
        // Extraction failed or not all values were present
        return unValid;
    }

    // If we get here, we successfully read x and url
    return result;
        
};
