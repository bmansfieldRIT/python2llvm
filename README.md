python llvm frontend:

why this is a good idea/useful:
compiled python is a cool idea

implement feature order:
newlines
comments
indentation
literals
keywords
escape sequences
operators
variables
arrays
array operations
printing
functions
if/then
for/in
while
with/in
try
import
decorators


How to achieve goal:
begin by building tokenization/lexer utilities
add utilities to print out lexer/ast/object code files
use recursive descent parsing to parse semantics
add debug info to ast objects
add code generation for simple operations, control flow, and functions
