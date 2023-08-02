# Krom

Krom is a hand-written *lexer* in C based-off the Monkey programming language.

# WTF is a Lexer ?

A lexer is a fundemantal part of a compiler that transforms source code character by character into tokens such as keywords, identifiers, literals, operators, and symbols. These tokens serve as input for the next stage of the compiler or interpreter, known as the parser.

# How this lexer is written ?

This lexer is written in *pure* C without any high-level abstraction like LLVM or Lex or any other library, and includes assets for dissasembled, assembled but unlinked and preprocessed code that are the same files as the source but written by the clang compiler to just give you an extra asset, also, the binary is kept + the CMakeFiles as an additionnal asset.

# How to run the lexer

To run the lexer run this :

*Arch users :*

```sh
    sudo pacman -Sy git cmake clang
    git clone https://github.com/AyoubCoding21/Krom
    cd Krom
    chmod u+x build.sh && ./build.sh
```

*Termux users :*

```sh
    pkg upgrade -y && pkg install clang git cmake -y --no-install-recommends
    git clone https://github.com/AyoubCoding21/Krom
    cd Krom
    bash build.sh
```

*Debian-based users :*

```sh
    sudo apt install git cmake clang -y --no-install-recommends
    git clone https://github.com/AyoubCoding21/Krom
    cd Krom
    bash build.sh
```

# Contribution

If you got any issues, please tell us.

This is just a lexer, and we want to upgrade to an AST generator then compiler/interpreter. So if any of you wants to contribute to this coding language. Please contact me on this e-mail : 

ayoubprogramming95@gmail.com

Or on Discord:

Username : Ayoub Coding#1225
Donate :

Payeer : ```P1098557175``` 

See you guys !!