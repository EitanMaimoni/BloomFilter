#include <iostream>
#include <sstream>
#include <vector>
#include "TwoHashValidator.h"

// Default constructor
TwoHashValidator::TwoHashValidator() {
    
};

std::vector<std::string> TwoHashValidator::validationCheck(std::string& line) {

    // Create a vector of strings to store the result
    std::vector<std::string> result(3);
    // Create an empty vector of strings to return if the input is invalid
    std::vector<std::string> unValid(0);
    
    // Create a string stream to read the input
    std::istringstream iss(line);

    // Try to read X, Y, and Z
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

        // If we get here, we unsuccessfully read X, Y, and Z
        return unValid;

    } catch (std::invalid_argument& e) {

        // result[0] could not be converted to an integer
        return unValid;

    }
};