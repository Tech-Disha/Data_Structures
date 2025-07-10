#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int size = 100;
char stack[100];
int top = -1;
void push(char item);
int is_operator(char symbol);
int precedence(char symbol);
void InfixToPostfix(char infix_exp[], char postfix_exp[]);
int main()
{
char infix[size], postfix[size];
for(int i = 0; i<size; i++){
postfix[i] = '\0';
}
printf("Enter Infix Expression: \n");
gets(infix);
InfixToPostfix(infix, postfix);
printf("\nPostfix Expression: \n");
puts(postfix);
return 0;
}
void push(char item)
{
if(top >= size - 1){
printf("Stack Overflow\n");
}else{
top = top+1;
stack[top] = item;
}
}
void print_stack()
{
for(int i = 0; i<=top; i++){
printf("%c", stack[i]);
}
}
char pop()
{
char item;
if(top<0){
printf("Stack underflow: invalid infix expression");
exit(1);
}else{
item = stack[top];
top = top-1;
return(item);
}
}
int is_operator(char symbol)
{
if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+'
|| symbol == '-'){
return 1;
}else{
return 0;
}
}
int precedence(char symbol)
{
if(symbol == '^'){
return(3);
}else if(symbol == '*' || symbol == '/'){
return(2);
}else if(symbol == '+' || symbol == '-'){
return(1);
}else{
return (0);
}
}
void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
printf("Serial No.\tToken\tStack\tPostfix\n");
printf("0\t\t(\t\n");
int i, j;
char item;
char x;
push('(');
strcat(infix_exp, ")");
i=0;
j=0;
item = infix_exp[i];
int counter = 1;
while(item != '\0'){
if(item == '('){
push(item);
}else if(isdigit(item) || isalpha(item)){
postfix_exp[j] = item;
j++;
}else if(is_operator(item) == 1){
x = pop();
while(is_operator(x) == 1 && precedence(x) >= precedence(item)){
postfix_exp[j] = x;
j++;
x = pop();
}
push(x);
push(item);
}else if(item == ')'){
x = pop();
while(x!= '('){
postfix_exp[j] = x;
j++;
x = pop();
}
}else{
printf("\nInvalid Infix Expression\n");
exit(1);
}
i++;
printf("%d\t", counter);
printf("%c\t", infix_exp[counter - 1]);
print_stack();
printf("\t%s\n", postfix_exp);
counter++;
item = infix_exp[i];
}
if(top >0){
printf("\nInvalid Infix Expression\n");
exit(1);
}
postfix_exp[j] = '\0';
}
