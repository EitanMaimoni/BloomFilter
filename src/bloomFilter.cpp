#include "bloomFilter.h"
#include <regex>
#include <iostream>
#include <stdexcept>

// Validate if a given string is a valid URL
bool isValidURL(const std::string& url) {
    // Regular expression for a simple URL validation
    std::regex urlPattern("^(www\\.[a-zA-Z0-9]+\\.[a-zA-Z0-9]+\\.com)$");
    return std::regex_match(url, urlPattern);
}

// Default constructor
BloomFilter::BloomFilter() {
    this->bit_array.assign(1, false);
    black_list = std::vector<std::string>();
}

// Constructor
BloomFilter::BloomFilter(std::vector<int> args) {
    for (size_t i = 0; i < args.size(); i++) {
        if (i == 0) {
            this->bit_array.assign(args[0], false);
            break;
        };
        this->hash_functions.push_back(args[i]);
    }
    black_list = std::vector<std::string>();
}

// Add URL to the bloom filter
void BloomFilter::addUrl(std::string& url) {
    // Check if the URL is valid before adding it to the black list
    if (!isValidURL(url)) {
        std::cerr << "Invalid URL: " << url << std::endl;
        return;
    }

    add_to_black_list(url);

    for (size_t i = 0; i < hash_functions.size(); i++) {
        std::string answer = url;
        for (int j = 0; j < hash_functions[i]; j++) {
            answer = std::to_string(std::hash<std::string>{}(answer) % this->bit_array.size());
        }
        this->bit_array[std::stoi(answer)] = true;
    }
}

// Add URL to the black list
void BloomFilter::add_to_black_list(std::string& url) {
if (!isValidURL(url)) {
        throw std::invalid_argument("URL cannot be added to the blacklist");
        return;
    }    
    this->black_list.push_back(url);
}

// Check if the URL is blacklisted
bool BloomFilter::check_url(std::string& url) {
    for (size_t i = 0; i < hash_functions.size(); i++) {
        std::string answer = url;
        for (int j = 0; j < hash_functions[i]; j++) {
            answer = std::to_string(std::hash<std::string>{}(answer) % this->bit_array.size());
        }
        if (this->bit_array[std::stoi(answer)] == false) {
            return false;
        }
    }
    return double_check_url(url);
}

// Double check if the URL is blacklisted
bool BloomFilter::double_check_url(std::string& url) {
    for (size_t i = 0; i < this->black_list.size(); i++) {
        if (this->black_list[i] == url) {
            return true;
        }
    }
    return false;
}
