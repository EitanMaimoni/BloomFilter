// MyInterface.h
#ifndef IBLOOM_FILTER_VALIDATOR_H
#define IBLOOM_FILTER_VALIDATOR_H

#include <vector>
#include <string>

class iValidator {
public:
    virtual std::vector<std::string> validationCheck(std::string& line) = 0; 
};

#endif // IBLOOM_FILTER_VALIDATOR_H