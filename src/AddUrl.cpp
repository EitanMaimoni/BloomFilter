#include <string>
#include "ICommand.h"
#include "AddUrl.h"


//constructor
AddUrl::AddUrl(BloomFilter* bloomFilter) {

    this->bloomFilter = bloomFilter;

}
        
// Add URL to the bloom filter
std::string AddUrl::execute(std::string& url) {

    //Add the URL to the black list
    addToBlackList(url);

    // Add the URL to the bit array filter
    addToBitArray(url);

    return "URL added to the bloom filter";
}
   
// Add URL to the black list
void AddUrl::addToBlackList(std::string& url) {

    bloomFilter->getBlackList().push_back(url);

}

// Add URL to the bit array
void AddUrl::addToBitArray(std::string& url) {

        // Get the index of the first hash function
        size_t index = bloomFilter->getHFunc1().activateFunction(url);

        // Set the bit to true
        bloomFilter->getBitArray()[index % bloomFilter->getBitArray().size()] = true;

        // Check if the second hash function is set
        if (bloomFilter->getHFunc2Flag()) {
            // Get the index of the second hash function
            index = bloomFilter->getHFunc2().activateFunction(url);
            // Set the bit to true
            bloomFilter->getBitArray()[index % bloomFilter->getBitArray().size()] = true;
        }
 }