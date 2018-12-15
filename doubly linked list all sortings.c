#include<stdio.h>
#include<stdlib.h>
struct Node{
int info;
struct Node *address_next;
struct Node *address_pre;

};
typedef struct Node node;
node *external=NULL,*list=NULL,*new_node,*external2=NULL,*external3=NULL,*e=NULL;
int counter;
void binary_search();
void instart();
void display();
int partition(int array[],int up,int down);
void select_sort();
void insert_sort();
void bubble_sort();



int main(){
int up=4,down=0;
 int choice;
 printf("\t\t\t\t**********************************************\n");
 printf("\t\t\t\t****Welcome to Farhan Raza Sorting Program****");
 printf("\n\t\t\t\t**********************************************\n");
printf("1.Enter data in Doubly linked list:\n2.Display data in linked list:\n3.Insert Sort:\n4.Select Sort:\n5.Bubble Sort:\n6.Exit:");
scanf("%d",&choice);

while(choice!=6){
switch(choice){

case 1:
instart();
break;

case 2:
   display();
    break;

case 3:

    select_sort();
    printf("\n Data Sorted Successfully:\n");
    break;
case 4:
    insert_sort();
     printf("\n Data Sorted Successfully:\n");
    break;
case 5:
    bubble_sort();
     printf("\n Data Sorted Successfully:\n");
    break;
}
printf("\n1.Enter data in Doubly linked list:\n2.Display data in linked list:\n3.Insert Sort:\n4.Select Sort:\n5.Bubble Sort:\n6.Exit:");
scanf("%d",&choice);
}


}

void instart(){
    new_node=(node*)malloc(sizeof(node));
    printf("\nEnter the value in the node :");
    scanf("%d",&new_node->info);

if(list==NULL){
     new_node->address_next=NULL;
     new_node->address_pre=NULL;
     list=new_node;
}
else{
    new_node->address_pre=NULL;
    new_node->address_next=list;
    list->address_pre=new_node;
      list=new_node;

}

}
void display(){
external=list;
printf("\n*******************\n");

while(external!=NULL){
    printf("%d ",external->info);
    external=external->address_next;
}
printf("\n*******************\n");
}

void select_sort(){
int i,minj,minx,j;
external=list;
external2=list;
while(external!=NULL){
//for(i=0;i<4;i++){
external3=external;
minx=external->info;

   external2=external->address_next;
   while(external2!=NULL){
    if(external2->info<minx){

            external3=external2;
            minx=external2->info;
        }
        external2=external2->address_next;
    }
    external3->info=external->info;
    external->info=minx;
    external=external->address_next;
}}
void insert_sort(){
int count,temp,j;
external=list;
external2=list;
external3=list;
external2=external2->address_next;

while(external2!=NULL){

temp=external2->info;
   external=external2->address_pre;

   while(external!=NULL&&temp<external->info){

   external3=external;
   external3=external3->address_next;
   external3->info=external->info;

       e=external;
       external=external->address_pre;


    }
    if(external!=NULL){
    external3=external;
    external3=external3->address_next;
    external3->info=temp;}
    else{

        external3=e;
    external3->info=temp;}
   external2=external2->address_next;

}
}
void bubble_sort(){
    int temp;
external=list;
external2=list;

while(external!=NULL){
        external2=external;
    external2=external2->address_next;
    while(external2!=NULL){

        if(external->info>external2->info){
            temp=external->info;
            external->info=external2->info;
            external2->info=temp;
        }
        external2=external2->address_next;
    }

    external=external->address_next;



}







}
