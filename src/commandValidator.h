#ifndef COMMANDVALIDATOR_H
#define COMMANDVALIDATOR_H

#include <vector>
#include <string>
#include "iValidator.h" // Include the header for the base class


class commandValidator : public iValidator {
public:
    // Default constructor
    commandValidator();

    // Member function for validation check
    std::vector<std::string> validationCheck(std::string& line);
};

#endif // COMMAND_VALIDATOR_H
