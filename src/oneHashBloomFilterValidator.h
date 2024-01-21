#ifndef ONE_HASH_BLOOM_FILTER_VALIDATOR_H
#define ONE_HASH_BLOOM_FILTER_VALIDATOR_H

#include <vector>
#include <string>
#include "bloomFilterValidator.h" // Include the header for the base class


class oneHashBloomFilterValidator : public bloomFilterValidator {
public:
    // Default constructor
    oneHashBloomFilterValidator();

    // Member function for validation check
    std::vector<int> validationCheck(std::string& line);
};

#endif // ONE_HASH_BLOOM_FILTER_VALIDATOR_H
