%token SET IF IDENTIFIER NUMBER PRINT
%%
assignment: SET IDENTIFIER "to" expression ;
if_statement: IF expression "is" comparison "then" statement ;
for_loop: "For each" IDENTIFIER "in" IDENTIFIER "do" statement ;
expression: NUMBER | IDENTIFIER ;
comparison: "greater than" | "less than" ;
statement: PRINT expression | assignment ;
%%
