#include <iostream>
#include "../lib/lexer.h"

int main() {
    std::string input = "let a = 5;\nlet b = 9;\nif (a < b)\n{\nlet c =5;\n}\n";
    std::vector<char> input_chars(input.begin(), input.end());
    lexer::Lexer l(input_chars);
    l.read_char();
    while (true) {
        Token token = l.next_token();
        if (token == Token::EOF_) {
            break;
        } else {
            std::cout << static_cast<int>(token) << std::endl;
        }
    }
    std::cout << l.get_ch() << " " << l.get_position() << " " << l.get_read_position() << std::endl;

    return 0;
}
