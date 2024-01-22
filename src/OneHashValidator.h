#ifndef ONEHASHVALIDATOR_H
#define ONEHASHVALIDATOR_H

#include <vector>
#include <string>
#include "IValidator.h" 

class OneHashValidator : public IValidator {
public:

    // Default constructor
    OneHashValidator();

    // Check if the line is valid
    std::vector<std::string> validationCheck(std::string& line);

};

#endif // ONEHASHVALIDATOR_H
