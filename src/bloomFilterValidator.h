// MyInterface.h
#ifndef BLOOM_FILTER_VALIDATOR_H
#define BLOOM_FILTER_VALIDATOR_H

#include <vector>
#include <string>

class bloomFilterValidator {
public:
    virtual std::vector<int> validationCheck(std::string& line) = 0; 
};

#endif // BLOOM_FILTER_VALIDATOR_H