# python2llvm

![Python Logo](https://www.python.org/static/community_logos/python-logo-master-v3-TM-flattened.png) ![LLVM Logo](https://llvm.org/img/LLVM-Logo-Derivative-1.png)

#### Introduction:
**LLVM** is a compiler project that can output extremely optimized machine code, with a simple intermediate representation (LLVM IR) that allows developers to create new optimizations passes.

**Python** is an interpreted language that allows for simple and rapid program prototyping, with the downside of being slower to execute due to it's interpreted nature.

**Combining** the two, by writing a Python front-end for LLVM, could produce interesting results, and hopefully a viable option to speed up Python code by producing executable object code. LLVM also provides many other useful features, such as retargeting, optimizations, debugging tools, static analysis tools, and more. See [LLVM's website](http://llvm.org/) for more info.

**Note** that this is different from how Python produces its own bytecode. The object of this compiler is to produce a single executable file given Python source code.

#### Documentation
The spec python2llvm is based on:
https://docs.python.org/3/reference/index.html

Reference implementation of CPython's parser https://devguide.python.org/compiler/

#### Features
This is a rough outline of the order language features will be implemented in the compiler.
* newlines
* comments
* indentation
* literals
* keywords
* escape sequences
* operators
* variables
* arrays
* array operations
* printing
* functions
* if/then
* for/in
* while
* with/in
* try
* import
* decorators

#### Development Outline
This is a quick-and-dirty outline of the stages of the project, and which stage it is currently in.

* Build tokenization/lexer utilities
* Add utilities to print tokenization/lexer output
* Use recursive descent parsing to construct AST
* Add utilities to print AST output
* Add debug attributes to AST objects
* Build code generation for simple operations, control flow, and functions
* Add utilities to print code generation output
* Add final machine targeting and executable output code

General Development:
* Continue adding language features
* Fix any bugs that pop up
* Ensure language is compliant with Python language specifications
* Test compiler executable speed against actual interpreted Python execution speed.
