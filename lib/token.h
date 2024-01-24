// Include guards
#ifndef TOKEN_H
#define TOKEN_H

// Include required libs
#include <unordered_map>
#include <vector>
#include <string>
#include <stdexcept>

// Enumeration for a type of token
enum class Token {
    ILLEGAL,
    EOF_,
    IDENT,
    INT,
    STRING,
    ASSIGN,
    PLUS,
    COMMA,
    SEMICOLON,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    FUNCTION,
    LET,
    TRUE,
    FALSE,
    IF,
    ELSE,
    RETURN,
    MINUS,
    BANG,
    ASTERISK,
    SLASH,
    LT,
    GT
};

// Key-value unordered map that has some text that is token
const std::unordered_map<std::string, Token> keywordMap = {
    {"fn", Token::FUNCTION},
    {"let", Token::LET},
    {"true", Token::TRUE},
    {"false", Token::FALSE},
    {"if", Token::IF},
    {"else", Token::ELSE},
    {"return", Token::RETURN}
};

/*
 		@function get_keyword_token
   		@args vector of characters 
     	@returns token
        @usage reads character by character and returns it's corresponding token.
*/
inline Token get_keyword_token(const std::vector<char>& ident) {
    std::string identifier(ident.begin(), ident.end());
    auto it = keywordMap.find(identifier);
    if (it != keywordMap.end()) {
        return it->second;
    }
    throw std::invalid_argument("SyntaxError: Unexpected keyword.");
}

#endif
