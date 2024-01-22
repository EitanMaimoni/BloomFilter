#ifndef TWOHASHVALIDATOR_H
#define TWOHASHVALIDATOR_H

#include <vector>
#include <string>
#include "IValidator.h" // Include the header for the base class

class TwoHashValidator : public IValidator {
public:

    // Default constructor
    TwoHashValidator();

    // Check if the line is valid
    std::vector<std::string> validationCheck(std::string& line);
    
};

#endif // TWOHASHVALIDATOR_H
