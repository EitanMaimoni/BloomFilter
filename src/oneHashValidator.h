#ifndef ONE_HASH_BLOOM_FILTER_VALIDATOR_H
#define ONE_HASH_BLOOM_FILTER_VALIDATOR_H

#include <vector>
#include <string>
#include "iValidator.h" // Include the header for the base class


class oneHashValidator : public iValidator {
public:
    // Default constructor
    oneHashValidator();

    // Member function for validation check
    std::vector<std::string> validationCheck(std::string& line);
};

#endif // ONE_HASH_BLOOM_FILTER_VALIDATOR_H
