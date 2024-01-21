#include <iostream>
#include <string>
#include "app.h"
#include "bloomFilter.h"
#include "twoHashValidator.h"
#include "oneHashValidator.h" 
#include "commandValidator.h"

// Default constructor
app::app() {
    
};

void app::run() {

    BloomFilter myBloomFilter;
    oneHashValidator myValidator1;
    twoHashValidator myValidator2;

    std::vector<std::string> initInput(3);

    std::string line;
    
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        initInput = myValidator2.validationCheck(line);
        if (initInput != std::vector<std::string>()) {
            // If we get here, we successfully read X, Y, and Z
            myBloomFilter = BloomFilter(std::stoi(initInput[0]), std::stoi(initInput[1]), std::stoi(initInput[2]));
            break;
        }
        initInput = myValidator2.validationCheck(line);
        if (initInput != std::vector<std::string>()) {
            // If we get here, we successfully read X, Y
            myBloomFilter = BloomFilter(std::stoi(initInput[0]), std::stoi(initInput[1]));
            break;
        }
    }

    commandValidator myCommandValidator;

    std::vector<std::string> commandInput(2);
    
    while (true) {
        int x;
        std::string url;
        std::string line;

        while (std::getline(std::cin, line)) {
            std::istringstream iss(line);
            commandInput = myCommandValidator.validationCheck(line);
            if (commandInput != std::vector<std::string>()) {
                break;
            }
        }
    }
}
