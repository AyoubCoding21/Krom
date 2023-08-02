#ifndef TOKEN_H
#define TOKEN_H

#include <unordered_map>
#include <vector>
#include <string>
#include <stdexcept>

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

const std::unordered_map<std::string, Token> keywordMap = {
    {"fn", Token::FUNCTION},
    {"let", Token::LET},
    {"true", Token::TRUE},
    {"false", Token::FALSE},
    {"if", Token::IF},
    {"else", Token::ELSE},
    {"return", Token::RETURN}
};

inline Token get_keyword_token(const std::vector<char>& ident) {
    std::string identifier(ident.begin(), ident.end());
    auto it = keywordMap.find(identifier);
    if (it != keywordMap.end()) {
        return it->second;
    }
    throw std::invalid_argument("SyntaxError: Unexpected keyword.");
}

#endif // TOKEN_H
