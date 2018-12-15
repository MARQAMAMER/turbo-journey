#include<stdio.h>
void pop();
void push(char a);
void display();
void convert();
void prefix();

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
prefix();

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

void prefix(){
int i=0;
char temp;
printf("prefix expression is : ");
char string[20]="(a+b)+(a-b/c*d)";
char string2[20];
int loop=0,p=0,q=0,g=0;

while(string[q]!=NULL){
   loop++;
   q++;
}


for(p=loop-1;p>=0;p--){
    string2[g]=string[p];
    g++;
}
q=0;
char temp1;
for(q=0;q<loop;q++){

        temp1=string2[q];
    if(temp1=='('){

        string2[q]=')';
       }
       else if(temp1==')'){

         string2[q]='(';
       }

       else if(temp1=='{'){
        string2[q]='}';
       }
       else if(temp1=='}'){
        string2[q]='{';
       }
       else if(temp1==']'){
        string2[q]='[';
       }
       else if(temp1=='['){
        string2[q]=']';
       }

       q++;
}

int l;
    for(l=0;l<loop;l++){

          temp=string2[l];

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

                            string1[j]=var;
                            j++;
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


                                string1[j]=var;
                            j++;
                                   }

                              }
                              i=0;
                            }

                    else{

                        string1[j]=temp;
                            j++;

                    }

                }
                  while(s.top!=-1){
                        pop();

                    if(var=='('||var=='{'||var=='['){

                                   }
                                   else{

                                string1[j]=var;
                            j++;
                                   }
                  }
                  i=0;
                  for(i=loop;i>=0;i--){
                    printf("%c",string1[i]);
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
    return 1;
    }
}
