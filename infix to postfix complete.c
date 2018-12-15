#include<stdio.h>
void pop();
void push(char a);
void display();
void convert();
void postfix();
int priority_check(char i);
char string1[20];
int j=0;
int counter=0;
char var;

struct stack{

char sta[10];
int top;

}s;
main(){


s.top=-1;
postfix();

}
void pop(){
int temp;
if(s.top==-1){
    printf("\nstack is empty");
}
else{
   var=s.sta[s.top];
   s.top--;
}
}
void push(char a){
    s.top++;
    s.sta[s.top]=a;
}
void display(){
int i;
for(i=s.top;i>=0;i--){
    printf("%c  ",s.sta[i]);
}
}

void postfix(){
int i=0;
char temp;
printf("your postfix expression is : ");
char string[20]="(a+b)+(a-b/c*d)";
    while(string[i]!=NULL){

          temp=string[i];
          if(temp=='('||temp=='{'||temp=='['){
                push(temp);
             }
             else if(temp=='*'||temp=='^'||temp=='/'||temp=='-'||temp=='+'){


                if(s.top==-1||s.sta[s.top]=='('||s.sta[s.top]=='{'||s.sta[s.top]=='['){
                    push(temp);}
                                   else if(priority_check(temp)>priority_check(s.sta[s.top])){
                            push(temp);
                           }

                    else{

                        while(priority_check(s.sta[s.top])>= priority_check(temp)){

                            pop();
                            printf("%c",var);
                            }
                             push(temp);
                           }

                    }

                   else if(temp==')'||temp=='}'||temp==']'){
                        int i;
                        while(i!=-1){
                                pop();

                                if(var=='('||var=='{'||var=='['){
                                    i=-1;
                                   }
                                   else{

                                printf("%c",var);
                                   }

                              }
                              i=0;
                            }

                    else{
                        printf("%c",temp);

                    }
                    i++;
                }
                  while(s.top!=-1){
                        pop();

                    if(var=='('||var=='{'||var=='['){

                                   }
                                   else{

                                printf("%c",var);
                                   }
                  }
}
int priority_check(char i){
if(i=='('){
    return 0;
   }
    else if(i=='^'){
        return 3;
    }
  else if(i=='*'||i=='/'){
    return 2;}
    else if(i=='+'||i=='-'){
    return 1;;
    }
}

