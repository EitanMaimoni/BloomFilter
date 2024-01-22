#include <iostream>
#include <sstream>
#include <vector>
#include "OneHashValidator.h"


// Default constructor
OneHashValidator::OneHashValidator() {
    
}

std::vector<std::string> OneHashValidator::validationCheck(std::string& line) {

    // Create a vector to store the result
    std::vector<std::string> result(2);
    // Create an empty vector of strings to return if the input is invalid
    std::vector<std::string> unValid(0);

    // Create a string stream to read the input
    std::istringstream iss(line);
        
    // Try to read X, Y
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

