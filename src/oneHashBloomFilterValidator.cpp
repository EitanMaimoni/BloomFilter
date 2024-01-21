#include "oneHashBloomFilterValidator.h"
#include <iostream>
#include <sstream>
#include <vector>

// Default constructor
oneHashBloomFilterValidator::oneHashBloomFilterValidator() {
    
};

std::vector<int> oneHashBloomFilterValidator::validationCheck(std::string& line) {
    std::vector<int> result(3);

    std::istringstream iss(line);
        
    if (iss >> result[0] >> result[1] >> result[2]) {
        if ((result[0] <= 0) || (result[1] != 1 && result[1] != 2) || (result[2] != 1 && result[2] != 2 && result[2] != result[1])) {
            // X is not > 0 or Y is not 1 or 2 or Z ins not 1, 2, or equal to Y
            return std::vector<int>();
        }

        // If we get here, we successfully read X, Y, and Z
        return result;
    }

    return result;
};