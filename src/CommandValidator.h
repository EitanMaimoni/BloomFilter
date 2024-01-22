#ifndef COMMANDVALIDATOR_H
#define COMMANDVALIDATOR_H

#include <vector>
#include <string>
#include "IValidator.h" 


class CommandValidator : public IValidator {
public:

    // Default constructor
    CommandValidator();

    // Member function for validation check
    std::vector<std::string> validationCheck(std::string& line);

};

#endif // COMMAND_VALIDATOR_H
