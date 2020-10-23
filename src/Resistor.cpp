#include <Resistor.h>

    Resistor::Resistor(){
        
    }//Constructer

//Change from color to number; 0-Digits;1-multiply; 2-Tolerence
int Resistor::convert(std::string color){
    if(color == "Black")
        return 0;
    else if(color == "Brown")
        return 1;
    else if(color == "Red")
        return 2;
    else if(color == "Orange")
        return 3;
    else if(color == "Yellow")
        return 4;
    else if(color == "Green")
        return 5;
    else if(color == "Blue")
        return 6;
    else if(color == "Violet")
        return 7;
    else if(color == "Grey")
        return 8;
    else if(color == "White")
        return 9;
    else if(color == "Silver")
        return 10;
    else if(color == "Gold")
        return 11;
    return 0;
}

//Creates Significant Figures
int Resistor::sigFig(std::string x, std::string y, std::string z){
    return (convert(x) * 100) + (convert(y) * 10) + (convert(z));
}

//Create Multiplier
std::string Resistor::mult(std::string color){
    if(color == "Black")
        return "1";
    else if(color == "Brown")
        return "10";
    else if(color == "Red")
        return "100";
    else if(color == "Orange")
        return "1k";
    else if(color == "Yellow")
        return "10k";
    else if(color == "Green")
        return "100k";
    else if(color == "Blue")
        return "1M";
    else if(color == "Violet")
        return "10M";
    else if(color == "Silver")
        return "0.01";
    else if(color == "Gold")
        return "0.1";
    return "";
}

std::string Resistor::tol(std::string color){
    if(color == "Black")
        return "";
    else if(color == "Brown")
        return "1%";
    else if(color == "Red")
        return "2%";
    else if(color == "Orange")
        return "";
    else if(color == "Yellow")
        return "";
    else if(color == "Green")
        return "0.5%";
    else if(color == "Blue")
        return "0.25%";
    else if(color == "Violet")
        return "0.1%";
    else if(color == "Grey")
        return "0.05%";
    else if(color == "Silver")
        return "10%";
    else if(color == "Gold")
        return "5%";
    return "";
}
//ucm::json
std::string Resistor::resistance(int sigificantFig, std::string multiplier, std::string tolerance){
    if(multiplier == "" || tolerance == "")
       return " Invalid";

    std::string ans =" "+ std::to_string(sigificantFig) + " x " + multiplier +"  \u03A9 "+ tolerance;
    return ans;
}