#include <iostream>
#include <string>
#include <vector>
/*
 * Make sure to do
 * splain() {
 *  splain_ "$BASH_COMMAND"
 * }
 * in the bash during installation
 */
std::vector<std::string> /* char** */ tokenisation(std::string arg) {
    std::vector<std::string> tokenList = {""};
    bool inQuotes = false;
    unsigned char activeToken = 0;
    for (int i = 0; i < arg.length(); i++) {
        if (arg[i] == ' ') {
            if (inQuotes) {
                tokenList[activeToken] += ' ';
            } else {
                activeToken++;
                tokenList.push_back("");
            }
        } else if (arg[i] == '"') {
            if (inQuotes) {
                inQuotes = false;
            } else {
                inQuotes = true;
            }
        } else {
            tokenList[activeToken] += arg[i];
        }
    }
    return tokenList;
}
int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: splain [OPTIONS] <INPUT>" << std::endl;
        return 1;
    }
    std::vector<std::string> tokens = tokenisation(std::string(argv[1]));
    //simple demo
    for (int i = 0; i < tokens.size(); i++) {
        std::cout << i + 1 << ". " << tokens[i] << "\n";
    }
    return 0;
}
