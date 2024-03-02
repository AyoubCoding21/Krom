# The Krom Programming Language
**_Built from the ground up to be fast, concise and intuitive._**

Based off Sophie Winter's Pinecone archived repo and William Savage's vim config for the coding language.

Krom is a new compiled programming language. Its goal is to combine the simplicity of a dynamic language with the performance of a compiled one.

It can also interop and transpile into C++ code.

__If you want to program in Krom now, see the [tutorials](tutorials/index.md) for how to get started.__

## Example
Here is the common demo program FizzBuzz written in Krom. It prints the numbers from 1 to 20, but it prints "Fizz" if the number is divisible by 3, "Buzz" if it is divisable by 5 and "FizzBuzz" if it is divisible by both. You can find more samples in the [examples directory](https://github.com/AyoubCoding21/Krom/tree/master/examples) or the [tutorials](https://github.com/AyoubCoding21/Krom/tree/master/tutorials).

```
# FizzBuzz

# call the function defined below
fizzBuzz: 1, 20

# define the FizzBuzz function
fizzBuzz :: {start: Int, end: Int}: (

	# loop i from start to end
	i: in.start | i <= in.end | i: i+1 @ (

		# use conditionals to print the right thing

		i % 3 = 0 && i % 5 = 0 ?
			print: "FizzBuzz"
		|
		i % 3 = 0 ?
			print: "Fizz"
		|
		i % 5 = 0 ?
			print: "Buzz"
		|
			print: i
	)
)
```

## Why?
This is probably the most common reaction to hearing about a new language. I realize that there are a __lot__ of programming languages, and that the reason for that is that there are so many assholes like me who keep making them. I do truly think, though, that Krom fills a previously empty niche.

Krom aims to have similar capabilities to modern object oriented compiled languages such as C++, Swift and Rust. It's primary attraction is the simplicity and consistency of it's syntax. Here are some examples of how Krom is different from other popular languages:

* Variable creation is implicit, just set a variable and it is created.
* Variables are statically typed, but type deduction is automatic.
* Calling a function that takes no arguments is the same syntax as accessing a variable (just writing it's name).
* Calling a function that takes one argument is the same syntax as setting or creating a variable (`funcOrVar: input`).
* Calling a function that takes multiple arguments is the same syntax as setting or creating a tuple (`funcOrTuple: input1, input2`).
* White space is ignored _and_ semicolons are not necessary
* `:` is used for assignment, which leaves `=` free for comparison, rather than the often confusing `==`.
* Tuples, structs and classes are all basically the same thing
* Functions can be sent arguments from the left side, right side or both (`inputLeft.function: inputRight`), which is used for class methods but can also allow you to define functions for any type (even primitive).
* Program control is done with operators instead of keywords (`?` instead of `if`)

## Compatibility
Krom currently requires zero external dependencies. You will need a C++ compiler to build it, and the process is easier with GCC and Make. Krom has been successfully tested on Linux, MacOS and Windows.

## Current State
The features that are currently implemented are as follows:

* Primitive data types `Bool`, `Int` and `Dub`
* All the operators you would expect (`+`, `*`, `%`, `:`, `=`, `>`, `<=`, `&&`, etc.)
* Single and multi line comments
* Flow control (if, if/else, while loop, for loop)
* Constants
* Data structs
* Tuples
* Int arrays
* Functions
* Strings and various String operations
* User input
* Running system commands
* Interpreter for rapid development and simplicity
* Transpiler to C++ for max performance
* Whatev type (equivalent to templates or generics in other languages)
* Operator overloading

## Contributing
Pull requests and contributions are welcome.
