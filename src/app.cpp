#include <iostream>
#include <string>
#include "app.h"
#include "bloomFilter.h"
#include "twoHashValidator.h"
#include "oneHashValidator.h" 
#include "commandValidator.h"
#include "Icommand.h"
#include "addUrl.h"
#include "checkUrl.h"

// Default constructor
app::app() {
    
};

void app::run() {

    // Create a BloomFilter object
    BloomFilter myBloomFilter;

    // Create a map of commands
    std::map<std::string, Icommand*> commands;
    Icommand* addCommand = new addUrl(&myBloomFilter);
    Icommand* checkCommand = new checkUrl(&myBloomFilter);
    commands["1"] = addCommand;
    commands["2"] = checkCommand;

    // Create a validators for the input
    oneHashValidator myValidator1;
    twoHashValidator myValidator2;

    // Create a string to store the input
    std::string firstInput;
    // Create a vector to store the results of the validation
    std::vector<std::string> initInput(3);
    
    // Read the first segment of the input
    while (std::getline(std::cin, firstInput)) {

        // Check if we can read X, Y, and Z
        initInput = myValidator2.validationCheck(firstInput);
        if (initInput != std::vector<std::string>()) {
            // If we get here, we successfully read X, Y, and Z
            myBloomFilter = BloomFilter(std::stoi(initInput[0]), std::stoi(initInput[1]), std::stoi(initInput[2]));
            break;
        }

        // Check if we can read X and Y
        initInput = myValidator2.validationCheck(firstInput);
        if (initInput != std::vector<std::string>()) {
            // If we get here, we successfully read X, Y
            myBloomFilter = BloomFilter(std::stoi(initInput[0]), std::stoi(initInput[1]));
            break;
        }

        // If we get here, we unsuccessfully read X, Y, and Z so we start over
    }

    // Create a validator for the input
    commandValidator myCommandValidator;

    // Create a string to store the input
    std::string secondInput;
    // Create a vector to store the results of the validation
    std::vector<std::string> commandInput(2);
    
    // Run the commands loop
    while (true) {

        // Read the second part of the input
        while (std::getline(std::cin, secondInput)) {

            // Check if we can read x and url
            commandInput = myCommandValidator.validationCheck(secondInput);
            if (commandInput != std::vector<std::string>()) {
                break;
            }

        }

        commands[commandInput[0]]->execute(commandInput[1]);
    }
}
