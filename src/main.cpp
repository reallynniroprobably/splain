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

    if (std::getenv("BASH_VERSION")) {
            std::cout << "Running under bash\n";
        } else if (std::getenv("ZSH_VERSION")) {
            std::cout << "Running under zsh\n";
        } else if (std::getenv("FISH_VERSION")) {
            std::cout << "Running under fish\n";
        } else {
            const char* shell = std::getenv("SHELL");
            if (shell) {
                std::cout << "Default shell: " << shell << "\n";
            } else {
                std::cout << "Shell could not be detected\n";
            }
        }
// test
    return 0;
}
