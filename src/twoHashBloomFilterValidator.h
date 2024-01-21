#ifndef TWO_HASH_BLOOM_FILTER_VALIDATOR_H
#define TWO_HASH_BLOOM_FILTER_VALIDATOR_H

#include <vector>
#include <string>
#include "bloomFilterValidator.h" // Include the header for the base class


class twoHashBloomFilterValidator : public bloomFilterValidator {
public:
    // Default constructor
    twoHashBloomFilterValidator();

    // Member function for validation check
    std::vector<int> validationCheck(std::string& line);
};

#endif // TWO_HASH_BLOOM_FILTER_VALIDATOR_H
