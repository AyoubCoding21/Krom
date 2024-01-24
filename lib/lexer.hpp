// Include guards
#ifndef LEXER_H
#define LEXER_H

// Including necesary libs
#include <vector>
#include "token.h"

// Namespace and class definition
namespace lexer {

	class Lexer {
		public:
		    Lexer(const std::vector<char>& input);
		
		    void read_char();
		    void skip_whitespace();
		    Token next_token();
		
		    char get_ch() const;
		    size_t get_position() const;
		    size_t get_read_position() const;
		
		private:
		    std::vector<char> input;
		    size_t position;
		    size_t read_position;
		    char ch;
		
		    static bool is_letter(char ch);
		    static bool is_digit(char ch);
	};

} // namespace lexer

namespace lexer {
	// Variables in-class (we put inline because they are in a header)
	inline Lexer::Lexer(const std::vector<char>& input) : input(input), position(0), read_position(0), ch('0') {}

	/*
 		@function read_char
   		@args none
     		@usage read a character from read_position in the class
	*/
	inline void Lexer::read_char() {
	    if (read_position >= input.size()) {
	        ch = '0';
	    } else {
	        ch = input[read_position];
	    }
	    position = read_position;
	    // We go to the next position
	    read_position = read_position + 1;
	}

	/*
 		@function skip_whitespace
   		@args none
     		@usage skips a space or \n or \t or \r in the provided input
	*/
	inline void Lexer::skip_whitespace() {
	    char ch = this->ch;
	    if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
	        read_char();
	    }
	}
	/*
 		@function next_token
   		@args none
     		@returns Token antity
     		@usage goes to the next token
	*/
	inline Token Lexer::next_token() {
	    // Indentifier to read
	    auto read_identifier = [this]() -> std::vector<char> {
	        size_t position = this->position;
	        while (this->position < this->input.size() && is_letter(this->ch)) {
	            read_char();
	        }
	        return std::vector<char>(this->input.begin() + position, this->input.begin() + this->position);
	    };
	    // Number to read
	    auto read_number = [this]() -> std::vector<char> {
	        size_t position = this->position;
	        while (this->position < this->input.size() && is_digit(this->ch)) {
	            read_char();
	        }
	        return std::vector<char>(this->input.begin() + position, this->input.begin() + this->position);
	    };
	    // Define token
	    Token tok;
	    // Skip any space
	    skip_whitespace();
	    // Check if the character is equal to a token, therefore return a token type defined in "token.h"
	    switch (ch) {
	        case '=':
	            tok = Token::ASSIGN;
	            break;
	        case '+':
	            tok = Token::PLUS;
	            break;
	        case '-':
	            tok = Token::MINUS;
	            break;
	        case '!':
	            tok = Token::BANG;
	            break;
	        case '/':
	            tok = Token::SLASH;
	            break;
	        case '*':
	            tok = Token::ASTERISK;
	            break;
	        case '<':
	            tok = Token::LT;
	            break;
	        case '>':
	            tok = Token::GT;
	            break;
	        case ';':
	            tok = Token::SEMICOLON;
	            break;
	        case '(':
	            tok = Token::LPAREN;
	            break;
	        case ')':
	            tok = Token::RPAREN;
	            break;
	        case ',':
	            tok = Token::COMMA;
	            break;
	        case '{':
	            tok = Token::LBRACE;
	            break;
	        case '}':
	            tok = Token::RBRACE;
	            break;
	        case '0':
	            tok = Token::EOF_;
	            break;
	        default:
		    // If none of these conditions are followed, read identifier and return wether indentation mark, integer or error.
	            if (is_letter(ch)) {
	                std::vector<char> ident = read_identifier();
	                try {
	                    return get_keyword_token(ident);
	                } catch (const std::invalid_argument&) {
	                    return Token::IDENT;
	                }
	            } else if (is_digit(ch)) {
	                std::vector<char> ident = read_number();
	                return Token::INT;
	            } else {
	                return Token::ILLEGAL;
	            }
	            break;
	    }
	    // Read the character
	    read_char();
	    // Return token
	    return tok;
	}
	/*
 		@function get_ch
   		@args none
     		@returns character gotten
     		@usage gets a character
	*/
	inline char Lexer::get_ch() const {
	    return ch;
	}
	/*
 		@function get_position
   		@args none
     		@returns position
     		@usage gets the position of that character
	*/
	inline size_t Lexer::get_position() const {
	    return position;
	}
	/*
 		@function get_read_position
   		@args none
     		@returns read_position
     		@usage gets the position of the character reader
	*/
	inline size_t Lexer::get_read_position() const {
	    return read_position;
	}
	/*
 		@function is_letter
   		@args character
     		@returns bool
     		@usage check if ch is a letter
	*/
	inline bool Lexer::is_letter(char ch) {
	    return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ch == '_';
	}
	/*
 		@function is_digit
   		@args character
     		@returns bool
     		@usage check if ch is a digit
	*/
	inline bool Lexer::is_digit(char ch) {
	    return '0' <= ch && ch <= '9';
	}

} // namespace lexer

#endif // LEXER_H
