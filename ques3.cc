#include <iostream>
#include <string>

int LastWordlength(const std::string& s) {
    int length = 0;

    
    for (int i = s.size() - 1; i >= 0; --i) {
        
        if (s[i] != ' ') {
            while (i >= 0 && s[i] != ' ') {
                
                ++length;
                --i;
            }
            break;
        }
    }

    return length;
}

int main() {
    
    std::string input = "Hello World";
    int result =LastWordlength(input);

    std::cout << "Length of the last word: " << result << std::endl;

    return 0;
}
