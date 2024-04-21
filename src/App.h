#ifndef APP_H
#define APP_H

#include <string>
#include <map>
#include "BloomFilter.h"
#include "ICommand.h"

class App {
private:
    BloomFilter myBloomFilter;
    std::map<std::string, ICommand*> commands;

public:
    // Default constructor
    App();
    App(std::string& request);

    std::string processRequest(std::string& request);

    std::string run(std::string& request);
};

#endif  // APP_H