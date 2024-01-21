#include <iostream>
#include <string>
#include "app.h"
#include "bloomFilter.h"
#include "twoHashBloomFilterValidator.h"
#include "oneHashBloomFilterValidator.h" 

// Default constructor
app::app() {
    
};

void app::run() {

    BloomFilter myBloomFilter;
    oneHashBloomFilterValidator myValidator1;
    twoHashBloomFilterValidator myValidator2;

    std::vector<int> result(3);

    std::string line;
    
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        result = myValidator2.validationCheck(line);
        if (result != std::vector<int>()) {
            // If we get here, we successfully read X, Y, and Z
            myBloomFilter = BloomFilter(result[0], result[1], result[2]);
            break;
        }
        result = myValidator2.validationCheck(line);
        if (result != std::vector<int>()) {
            // If we get here, we successfully read X, Y
            myBloomFilter = BloomFilter(result[0], result[1]);
            break;
        }
    }

    while (true) {
        int x;
        std::string url;
        std::string line;

        while (std::getline(std::cin, line)) {
            std::istringstream iss(line);

            if (!(iss >> x >> url) || (x != 1 && x != 2) || (url.length() == 0)) {
                // Extraction failed or not all values were present
                continue;
            }

            // If we get here, we successfully read x and url
            break;
        }

        switch (x) {
            case 1:
                myBloomFilter.add_url_to_bloomFilter(url);

                break;
            case 2:    
                myBloomFilter.check_url(url);

                break;
            default:
                // Go to the next iteration
                continue;
        }
    }
}
