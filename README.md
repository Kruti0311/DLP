# DLP
Design of Language Processor

**Practical : 1**
Practical Definition :
String Validation Against Regular Expression 

Objective :
To implement a program that validates a user-input string against the regular expression a*bb. The program should determine whether the input string is valid or invalid based on the defined pattern. 

**Practical : 2**
Practical Definition :
String Validation Using Finite Automata 
 
Objective :
To implement a program that validates a given string against rules defined in terms of finite automata.

**Practical : 3**
Practical Definition :
Implementation of a Lexical Analyzer for C Language Compiler 
 
Objective :
To design and implement a lexical analyser, the first phase of a compiler, for the C programming language. The lexical analyser should perform the following tasks: (1) tokenizing the input string (2) removing comments (3) removing white spaces (4) entering identifiers into the symbol table (5) generating lexical errors. 

**Practical : 4**
Practical Definition :
String validation using Lax tool 
 
Objective - 1 :
Write a program to identify and extract all numbers from input string and display them one by one in new line. 
 
Objective - 2 :
Write a program to replace the word "charusat" with “university” in the input text. 

Objective – 3 :
Write a program to count number of characters, word and lines from the input file. 

 Objective – 4 :
Write a program which validate the password as per given rules. 
➢ length can be 9 to 15 characters  
➢ includes lower case letter, upper case letter, digit, symbols (*, ; # $ @) 
➢ minimum count for each category must be one 

**Practical : 5**
Practical Definition: 
Implementation of a Lexical Analyzer for C Language Compiler 
 
Objective :
To design and implement a lexical analyser to perform 1st, 2nd, 3rd, and 5th task as per the list given in practical 2. 

**Practical : 6**
Practical definition :
String validation using Recursive Descent Parsing (RDP) 
 
Objective :
Implement a Recursive Descent Parser (RDP) to validate an input string against the given grammar. 
S → ( L ) | a 
L → S L’ 
L’ → , S L’ | ϵ 

**Practical : 7**
Program definition :
Computing First and Follow Sets for a Context-Free Grammar (CFG) 
 
Objective :
Develop a program computes the First and Follow sets for all non-terminal symbols in for the below given grammar. 
S → A B C | D 
A → a | ε 
B → b | ε 
C → ( S ) | c 

**Practical : 8**
Program definition :
Predictive Parsing Table Construction and LL(1) Grammar Validation 

Objective :
Develop a program to construct a predictive parsing table for the given grammar. The program should analyse the generated parsing table to determine whether the grammar is LL(1) or not. If the grammar is LL(1), the program should also validate an input string against the givengrammar. 

**Practical : 9**
Program definition :
String parsing using YACC 

Objective :
Develop a YACC program to validate input strings based on the given grammar. The program should parse the string using the grammar rules and determine whether the string is valid or invalid. 
S → i E t S S' | a 
S' → e S | ε 
E → b 

**Practical : 10**
Program definition :
Evaluating Arithmetic Expression with Bottom-Up Approach Using SDD 

Objective :
Develop a program to evaluate arithmetic expressions containing operators using a bottom-up parsing approach and below given Syntax-Directed Definitions (SDD) for semantic evaluation. The program will compute the result of the expression by building a parse tree using and will incorporate semantic rules to evaluate sub-expressions during parsing. 
![image](https://github.com/user-attachments/assets/3b13cdfd-4e16-42c3-abcb-bbbd59f916c6)


**Practical : 11**
Program definition :
Generate Intermediate Code Using Quadruple Table 

Objective :
Develop a program that break down the input string according to the grammar and produce a sequence of quadruples representing the intermediate code for the expression. 
E → E + T | E – T | T 
T → T * F | T / F | F 
F → (E) | digit 

**Practical : 12**
Program definition :
Code Optimization Using Constant Folding 

Objective :
Develop a program that identifies constant expressions at compile-time and replaces them with their evaluated results to enhance execution efficiency. 
