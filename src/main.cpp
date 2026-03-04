#include <iostream>
/*
 * Make sure to do
 * splain() {
 *  splain_ "$BASH_COMMAND"
 * }
 * in the bash during installation
 */
char** tokenisation(std::string arg) {
    std::vector<std::string> tokenList;
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
}
int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: splain [OPTIONS] <INPUT>" << std::endl;
        return 1;
    }

    return 0;
}
