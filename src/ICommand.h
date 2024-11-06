#ifndef ICOMMAND_H
#define ICOMMAND_H
#include <string>

class ICommand {
    public:

        // Every command must have an execute function
        virtual std::string execute(std::string& url) = 0;

};
#endif // ICOMMAND_H