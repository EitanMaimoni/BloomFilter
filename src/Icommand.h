#ifndef ICOMMAND_H
#define ICOMMAND_H
#include <string>

class Icommand {
    public:
        virtual void execute(std::string& url) = 0;
};
#endif // ICOMMAND_H