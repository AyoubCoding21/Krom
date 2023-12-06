// Including libraries
#include <stdio.h>
#include "../lib/lexer.h"

int main() {
    // Source code input
    char input[] = "let a = 5;\nlet b = 9;\nif (a < b)\n{\nlet c =5;\n}";
    // Transform it into a char vector
    int input_length = sizeof(input) / sizeof(input[0]);
    lexer_t l;
    l.init(input, input_length);
    l.read_char();
    while (true) {
        token_t token = l.next_token();
        if (token == TOKEN_EOF_) {
            break;
        } else {
            printf("Token converted to int : %d\n", (int)token);
        }
    }
    printf("Character : %c, Position : %d, Read Position : %d\n", l.get_ch(), l.get_position(), l.get_read_position());
    return 0;
}
