#include "twoHashBloomFilterValidator.h"
#include <iostream>
#include <sstream>
#include <vector>

// Default constructor
twoHashBloomFilterValidator::twoHashBloomFilterValidator() {
    
};

std::vector<int> twoHashBloomFilterValidator::validationCheck(std::string& line) {
    std::vector<int> result(3);
    std::vector<int> unValid(0);

    std::istringstream iss(line);
        
    if (iss >> result[0] >> result[1]) {
        if (result[0] <= 0 || (result[1] != 1 && result[1] != 2)) {
            // X is not > 0 or Y is not 1 or 2
            return unValid;
        }

        while (iss >> result[2]) {
            if ((result[2] == 1 || result[2] == 2) && result[2] != result[1]) {
                // If we get here, we successfully read X, Y, and Z
                return result;
            }
        }
    }
    return unValid;
};