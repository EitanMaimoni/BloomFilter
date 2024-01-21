#include "oneHashBloomFilterValidator.h"
#include <iostream>
#include <sstream>
#include <vector>

// Default constructor
oneHashBloomFilterValidator::oneHashBloomFilterValidator() {
    
}

std::vector<int> oneHashBloomFilterValidator::validationCheck(std::string& line) {
    std::vector<int> result(2);
    std::vector<int> unValid(0);

    std::istringstream iss(line);
        
    if (iss >> result[0] >> result[1]) {
        if ((result[0] <= 0) || (result[1] != 1 && result[1] != 2)) {
            // X is not > 0 or Y is not 1 or 2
            return unValid;
        }

        // If we get here, we successfully read X, Y, and Z
        return result;
    }
    return unValid;
};