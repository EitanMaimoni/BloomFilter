#include <iostream>
#include <string>
#include "bloomFilter.h" 


int main() {
    int X, Y, Z;
    std::string line;
    bool isZInitialized = false;

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        
        if (iss >> X >> Y) {
            if ((Y != 1 && Y != 2) || (X <= 0)) {
                // X is not > 0 or Y is not 1 or 2
                continue;
            }

            if (iss >> Z) {
                if (Z != 1 && Z != 2) {
                    // Z is present but not 1 or 2
                    continue;
                }
                isZInitialized = true;
            }

            // If we get here, we successfully read X, Y, and optionally Z
            break;
        }
    }

    BloomFilter myBloomFilter;
    if (isZInitialized) {
        myBloomFilter = BloomFilter(X, Y, Z);
    } else {
        myBloomFilter = BloomFilter(X, Y);
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
    return 0;
}
