#ifndef RESISTOR
#define RESISTOR

#include<server.h>

class Resistor{
 public:
    Resistor();

    //type 1 for sigFig; 2 for mult; 3 for tolerence
    int convert(std::string);

    int sigFig(std::string,std::string,std::string);
    std::string mult(std::string);
    std::string tol(std::string);
    //ucm::json
    std::string resistance(int,std::string,std::string);

    ~Resistor();
};

#endif
