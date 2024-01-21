#ifndef TWOHASHVALIDATOR_H
#define TWOHASHVALIDATOR_H

#include <vector>
#include <string>
#include "iValidator.h" // Include the header for the base class


class twoHashValidator : public iValidator {
public:
    // Default constructor
    twoHashValidator();

    // Member function for validation check
    std::vector<std::string> validationCheck(std::string& line);
};

#endif // TWOHASHVALIDATOR_H
