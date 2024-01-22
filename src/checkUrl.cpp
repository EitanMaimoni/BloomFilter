#include "Icommand.h"
#include <string>
#include <iostream>
#include "checkUrl.h"

// Constructor
checkUrl::checkUrl(BloomFilter* bloomFilter) {

    this->bloomFilter = bloomFilter;

}

// Execute the command
void checkUrl::execute(std::string& url) {

    check_url(url);
}

// Check if the URL is in the bit array
bool checkUrl::is_on_bit_array(std::string& url) {

    // Get the index of the first hash function
    size_t index = bloomFilter->get_hFunc1().activateFunction(url);
    // Get the bit array
    std::vector<bool>& bit_array = bloomFilter->get_bit_array();

    // Check if the bit is true
    if (bit_array[index % bit_array.size()]) {
        // Check if the second hash function is on
        if (bloomFilter->get_hFunc2Flag()) {  
            // Get the index of the second hash function
            index = bloomFilter->get_hFunc2().activateFunction(url);
            // Check if the bit is true
            if (bit_array[index % bit_array.size()]) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;

}

// Check if the URL is in the black list
bool checkUrl::is_on_black_list(std::string& url) {

    std::vector<std::string>& black_list = bloomFilter->get_black_list();
    // Check if the url is in the black list
    return std::find(black_list.begin(), black_list.end(),url) != black_list.end();

}

// Check if the URL is blacklisted
void checkUrl::check_url(std::string& url) {

    // Print if the URL is in the bit array
    if (this->is_on_bit_array(url)) {
        std::cout << "true ";
    }
    else {
        std::cout << "false" << std::endl;;
        return;
    }

    // Print if the URL is in the black list
    if (this->is_on_black_list(url)) {
        std::cout << "true" << std::endl;   
    }
    else {
        std::cout << "false" << std::endl;;
    }

}