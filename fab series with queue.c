#include<stdio.h>
int queue[5]={0};
int F=-1,R=-1;
void insert(int in);
void Remove();
void series();

int main(){
int number,loop,first=0,second=1;
printf("How many number of series do u want to print:");
scanf("%d",&number);
insert(first);
insert(second);

for(loop=0;loop<number;loop++){
 series();
}

}

void insert(int in){

   if(F==0&&R==4){
                printf("\nQueue is overflow");
                 }
   else if(F==R+1)
                 {
                printf("\nQueue is overflow");
                 }
   else if(F==-1&&R==-1)
                 {
                   F=0;
                   R=0;
                   queue[R]=in;
                 }
   else if(R==4&&F!=0)
                 {
                   R=0;
                   queue[R]=in;
                 }
    else
         {
           R++;
           queue[R]=in;
         }
}//Ending of insert function....
void Remove(){

     if(F==-1&&R==-1){
                       printf("\nERROR UNDER FLOW QUEUE IS EMPTY");
                     }
     else if(F==R){
                    queue[F]='\0';
                    F=-1;
                    R=-1;
                  }
     else if(F==4){
                    queue[F]='\0';
                    F=0;
                 }
     else{
           queue[F]='\0';
           F++;
         }
}//ENDINF OF REMOVE FUCTION.....
void series(){
               int next;
               next=queue[F]+queue[R];
               insert(next);
               printf("%d ",queue[F]);
               Remove();
}//ENDINF OF SEREIES FUCTION.....

