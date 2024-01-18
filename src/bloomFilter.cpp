// bloomFilter.cpp

#include "bloomFilter.h"
#include <algorithm>

// Default constructor
BloomFilter::BloomFilter(int ArrayLength ,int firstHash) {
    this->bit_array.assign(ArrayLength, false);
    black_list = std::vector<std::string>();
}

// Constructor with hash functions
BloomFilter::BloomFilter(int ArrayLength , int firstHash,int secondHash) {
    
    this->bit_array.assign(ArrayLength, false);

    for (size_t i = 0; i < ArrayLength; i++) {
       
        this->hash_functions.push_back(i);
    }
    black_list = std::vector<std::string>();
}

// Validate if the provided string is a valid URL
bool BloomFilter::is_valid_url(const std::string& url) {

    // Use a simple regular expression to check if the URL has a valid format
    std::string regexPattern = "www.[a-zA-Z0-9]+.com";

    // Create a regex object
    std::regex pattern(regexPattern);

    return std::regex_search(url, pattern);
}

// Add URL to the black list
void BloomFilter::add_to_black_list(std::string& url) {
    this->black_list.push_back(url);
}

//check if the URL is in the black list
bool BloomFilter::is_on_black_list(std::string& url) {
    return std::find(this->black_list.begin(), this->black_list.end(), url) != this->black_list.end();
}

// Add URL to the bloom filter
void BloomFilter::add_url_to_bloomFilter(std::string& url) {
    // Validate the URL
    if (!is_valid_url(url)) {
        throw std::invalid_argument("Invalid URL: " + url);
    }

    // Add the URL to the black list
    add_to_black_list(url);

    // Add the URL to the bloom filter
    for (size_t i = 0; i < hash_functions.size(); i++) {
        std::string answer = url;
        for (int j = 0; j < hash_functions[i]; j++) {
            answer = std::to_string(std::hash<std::string>{}(answer) % this->bit_array.size());
        }
        this->bit_array[std::stoi(answer)] = true;
    }
}

// Check if the URL is blacklisted
bool BloomFilter::check_url(std::string& url) {
    // Validate the URL
    if (!is_valid_url(url)) {
        throw std::invalid_argument("Invalid URL: " + url);
    }

    // Check if the URL is blacklisted in the bloom filter
    for (size_t i = 0; i < hash_functions.size(); i++) {
        std::string answer = url;
        for (int j = 0; j < hash_functions[i]; j++) {
            answer = std::to_string(std::hash<std::string>{}(answer) % this->bit_array.size());
        }
        if (this->bit_array[std::stoi(answer)] == false) {
            return false;
        }
    }

    // check if the URL is blacklisted in the black list
    return is_on_black_list(url);
}

