#include <string>
#include <iostream>
#include "CheckUrl.h"
#include "ICommand.h"

// Constructor
CheckUrl::CheckUrl(BloomFilter* bloomFilter) {

    this->bloomFilter = bloomFilter;

}

// Execute the command
void CheckUrl::execute(std::string& url) {

    checkUrl(url);
}

// Check if the URL is in the bit array
bool CheckUrl::isOnBitArray(std::string& url) {

    // Get the index of the first hash function
    size_t index = bloomFilter->getHFunc1().activateFunction(url);
    // Get the bit array
    std::vector<bool>& bitArray = bloomFilter->getBitArray();

    // Check if the bit is true
    if (bitArray[index % bitArray.size()]) {
        // Check if the second hash function is on
        if (bloomFilter->getHFunc2Flag()) {  
            // Get the index of the second hash function
            index = bloomFilter->getHFunc2().activateFunction(url);
            // Check if the bit is true
            if (bitArray[index % bitArray.size()]) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;

}

// Check if the URL is in the black list
bool CheckUrl::isOnBlackList(std::string& url) {

    std::vector<std::string>& black_list = bloomFilter->getBlackList();
    // Check if the url is in the black list
    return std::find(black_list.begin(), black_list.end(),url) != black_list.end();

}

// Check if the URL is blacklisted
void CheckUrl::checkUrl(std::string& url) {

    // Print if the URL is in the bit array
    if (this->isOnBitArray(url)) {
        std::cout << "true ";
    }
    else {
        std::cout << "false" << std::endl;;
        return;
    }

    // Print if the URL is in the black list
    if (this->isOnBlackList(url)) {
        std::cout << "true" << std::endl;   
    }
    else {
        std::cout << "false" << std::endl;;
    }

}