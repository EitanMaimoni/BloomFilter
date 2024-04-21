#include <iostream>
#include <string>
#include "App.h"
#include "BloomFilter.h"
#include "TwoHashValidator.h"
#include "OneHashValidator.h"
#include "CommandValidator.h"
#include "ICommand.h"
#include "AddUrl.h"
#include "CheckUrl.h"

// Default constructor
App::App() {
    // Create a map of commands
    ICommand* addCommand = new AddUrl(&myBloomFilter);
    ICommand* checkCommand = new CheckUrl(&myBloomFilter);
    commands["1"] = addCommand;
    commands["2"] = checkCommand;
}

//  Constructor
App::App(std::string& request) {

    // Create a map of commands
    ICommand* addCommand = new AddUrl(&myBloomFilter);
    ICommand* checkCommand = new CheckUrl(&myBloomFilter);
    commands["1"] = addCommand;
    commands["2"] = checkCommand;

    // Create a validators for the input
    OneHashValidator myValidator1;
    TwoHashValidator myValidator2;

    // Create a vector to store the results of the validation
    std::vector<std::string> initInput(3);

    // Check if we can read X, Y, and Z
    initInput = myValidator2.validationCheck(request);
    if (initInput != std::vector<std::string>()) {
        // If we get here, we successfully read X, Y, and Z
        myBloomFilter = BloomFilter(std::stoi(initInput[0]), std::stoi(initInput[1]), std::stoi(initInput[2]));
        return;
    }

    // Check if we can read X and Y
    initInput = myValidator1.validationCheck(request);
    if (initInput != std::vector<std::string>()) {
        // If we get here, we successfully read X, Y
        myBloomFilter = BloomFilter(std::stoi(initInput[0]), std::stoi(initInput[1]));
        return;
    }

};

std::string App::processRequest(std::string& request) {
    // Process the request and generate the response
    std::string response;
    // For example, you might parse the request, execute commands, and generate a response
    // Assuming your current run method returns a string response:
    response = run(request); // Assuming run method processes the request and returns a response

    return response;
}

std::string App::run(std::string& request) {

    std::string response;

    // Create a validator for the input
    CommandValidator myCommandValidator;

    // Create a vector to store the results of the validation
    std::vector<std::string> commandInput(2);

    // Check if we can read x and url
    commandInput = myCommandValidator.validationCheck(request);
    if (commandInput != std::vector<std::string>()) {
        response = commands[commandInput[0]]->execute(commandInput[1]);
    }
    return response;
}






