#ifndef IVALIDATOR_H
#define IVALIDATOR_H

#include <vector>
#include <string>

class iValidator {
public:

    // Every Validator must have a validationCheck function
    virtual std::vector<std::string> validationCheck(std::string& line) = 0; 

};
#endif // IVALIDATOR_H