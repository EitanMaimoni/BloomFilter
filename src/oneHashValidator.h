#ifndef ONEHASHVALIDATOR_H
#define ONEHASHVALIDATOR_H

#include <vector>
#include <string>
#include "iValidator.h" 

class oneHashValidator : public iValidator {
public:

    // Default constructor
    oneHashValidator();

    // Check if the line is valid
    std::vector<std::string> validationCheck(std::string& line);

};

#endif // ONEHASHVALIDATOR_H
