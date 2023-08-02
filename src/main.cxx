// Including libraries
#include <iostream>
#include "../lib/lexer.h"

int main() {
    // Source code input
    std::string input = "let a = 5;\nlet b = 9;\nif (a < b)\n{\nlet c =5;\n}\n";
    // Transform it into a char vector
    std::vector<char> input_chars(input.begin(), input.end());
    // Start the Lexer with the input
    lexer::Lexer l(input_chars);
    l.read_char();
    while (true) {
        Token token = l.next_token();
        if (token == Token::EOF_) {
            break;
        } else {
            std::cout << "Token converted to int : " << static_cast<int>(token) << std::endl;
        }
    }
    // Printing last character
    std::cout << "Character : " << l.get_ch() << " It's position : " << l.get_position() << " It's read position : " << l.get_read_position() << std::endl;

    return 0;
}
