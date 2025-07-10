#include<stdio.h>
void push();
void pop();
void peek();
void size();
void display();
int s[100];
int max = 0;
int top = -1;
int main()
{
int ch = 0;
printf("1. Push\n2. Pop\n3. Peek\n4. Size\n5. Display\n6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &ch);
while(ch!=6)
{
switch(ch)
{
case 1: if(top == 99){
printf("Overflow\n");
break;
}
push();
break;
case 2: if(top == -1){
printf("Underflow\n");
break;
}
pop();
break;
case 3: if(top == -1){
printf("Stack is empty\n");
break;
}
peek();
break;
case 4: size();
break;
case 5: if(top == -1){
printf("The stack is empty\n");
}else{
display();
}
break;
default: printf("Enter a valid choice\n");
break;
}
printf("Enter your choice: ");
scanf("%d", &ch);
}
}
void push()
{int val;
printf("Enter the element you want to push: ");
scanf("%d", &val);
s[top+1] = val;
max++;
top = max - 1;
}
void pop()
{
printf("The topmost element %d has been popped\n", s[top]);
s[top+1] = 0;
max--;
top = max - 1;
}
void peek()
{
printf("The topmost element is %d\n", s[top]);
}
void size()
{
if(top == -1){
printf("The stack is empty\n");
}else{
printf("The size is %d\n", max);
}
}
void display()
{
int ch = 0;
if(top == -1){
printf("The stack is empty\n");
}else{
printf("In what way do you wish to see the stack?\n");
printf("1. Normal\n2. Reverse\n");
scanf("%d", &ch);
printf("The stack is:\n");
int flag = 1;
while(flag == 1)
{
switch(ch)
{
case 1: for(int i = 0; i<=top; i++){
printf("%d\n", s[i]);
}
flag = 0;
break;
case 2: for(int i = top; i>=0; i--){
printf("%d\n", s[i]);
}
flag = 0;
break;
default: printf("Enter a valid choice\n");
break;
}
}
}
}
