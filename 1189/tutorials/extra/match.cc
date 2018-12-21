#include <iostream>
#include <string>

bool match(std::string word, std::string line) {
    for (int i = 0; i < line.length(); i++) {
        bool good = true;
        for (int j = 0; j < word.length(); j++) {
            // If we exceed the current line length, no match
            if (i+j-1 >= line.length()) {
                good = false;
                break;
            }
            // Character mismatch -- no match
            if (line[i+j] != word[j]) {
                good = false;
                break;
            }
        }
        if (good) return true;
    }
    return false;
}

int main() {
    std::cout << match("hi", "ohio") << std::endl
              << match("A", "banana") << std::endl
              << match("ba", "aaba") << std::endl
              << match("hy", "hydrogen") << std::endl;
}
