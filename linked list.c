//Rana Faheem
#include<stdio.h>
void in_start();
void display();
void del_start();
void in_end();
void del_end();
void in_specific();
void del_specific();
void reverse();
void del_repeat();
void mergelists();
void create_list();
struct Node{
int info;
struct Node *address;

};
typedef struct Node node;
node *external=NULL,*list=NULL,*new_node,*external2,*external3;
int counter;
int main(){

int choice;
printf("\n|1|.Insert a value at start: \n|2|.Insert a value at end: \n|3|.Delete a value from start:\n|4|.Delete a value from End: \n|5|.Insert a value at specific point:\n|6|.Delete a value from specific point: \n|7|.Display List: \n|8|.Reverse List: \n|9|.Delete Repeated value from list: \n|10|.Merge Two Lists:\n ");
scanf("%d",&choice);
while(choice!=11){
switch(choice){

case 1:
in_start();
break;

case 2:
    in_end();
    break;
case 3:
    del_start();
    break;
case 4:
    del_end();
    break;
case 5:
    in_specific();
    break;
case 6:
    del_specific();
    break;
case 7:
    display();
    break;
case 8:
    reverse();
    break;
case 9:
    del_repeat();
    break;

case 10:
   mergelists();
    break;

}
printf("\n|1|.Insert a value at start: \n|2|.Insert a value at end: \n|3|.Delete a value from start:\n|4|.Delete a value from End: \n|5|.Insert a value at specific point:\n|6|.Delete a value from specific point: \n|7|.Display List: \n|8|.Reverse List: \n|9|.Delete Repeated value from list: \n|10|.Merge Two Lists\n ");
scanf("%d",&choice);
}

}
void in_start(){
    new_node=(node*)malloc(sizeof(node));
    printf("\nEnter the value in the node :");
    scanf("%d",&new_node->info);
    counter++;
if(list==NULL){
     new_node->address=NULL;
     list=new_node;
}
else{

    new_node->address=list;
    list=new_node;

}

}
void display(){
external=list;

printf("\n-------------------------------\n");
while(external!=NULL){
    printf("%d ",external->info);
    external=external->address;
}
printf("\n-------------------------------\n");
}

void del_start(){
    if(list==NULL){
        printf("\nTHERE IS NO LIST OR NO NODE AVAILABLE TO DELETE:");
    }
    else{
external=list;
list=list->address;
free(external);
counter--;
    }
    if(counter==0){
        list=NULL;
    }
}
void in_end(){
     new_node=(node*)malloc(sizeof(node));
    printf("\nEnter the value in the node :");
    scanf("%d",&new_node->info);
    counter++;
if(list==NULL){
     new_node->address=NULL;
     list=new_node;
}
else{
    external=list;
    while(external->address!=NULL){
        external=external->address;
    }
    new_node->address=NULL;
    external->address=new_node;
}

}
void del_end(){

if(list==NULL){
        printf("\nTHERE IS NO LIST OR NO NODE AVAILABLE TO DELETE:");
    }
    else{
            external2=list;
external=list;
while(external2->address!=NULL){
    external=external2;
    external2=external2->address;
}
external->address=NULL;
free(external2);
counter--;
    }
    if(counter==0){
        list=NULL;
    }
}
void in_specific(){
    if(list==NULL){
        printf("No linked list found");
    }
    else{
int location=0,i=0;
printf("Enter the location in which you want to insert");
scanf("%d",&location);
if(location>counter||location<=1){
    printf("invalid location you can't add here");
}


else{
        location=location-2;
new_node=(node*)malloc(sizeof(node));
    printf("\nEnter the value in the node :");
    scanf("%d",&new_node->info);
    counter++;
    external=list;

for(i=location;i>0;i--){

external=external->address;

}
new_node->address=external->address;
external->address=new_node;
}}}
void del_specific(){
if(list==NULL){
    printf("No linked List found");
}
else{
int location=0,i=0;
printf("Enter the location at which you want to delete");
scanf("%d",&location);
if(location>=counter||location<=1){
    printf("Location is not valid you can't delete from this location");
}


else{

external=list;
external2=list;
for(i=location;i>0;i--){
external=external2;
external2=external2->address;

}
external->address=external2->address;
free(external2);
counter--;

}}}
void reverse(){
    int counter2=0,counter3=0,i,counter4=0;


 while(counter3!=(counter-1)){

external=list;
external2=list;
while(external2->address!=NULL){

    external=external2;
    external2=external2->address;
}

external->address=NULL;
counter2++;

if(counter2==1){

external2->address=list;
list=external2;
}
else
{
  external=list;
  counter4=counter2;
counter4=counter4-2;
for(i=counter4;i>0;i--){

external=external->address;

}
external2->address=external->address;
external->address=external2;
}

counter3++;

}}
void del_repeat(){
external=list;

while(external!=NULL){
        int check=0;
         external2=external;
        external3=external2;
        external2=external2->address;
//printf("2");

while(external2!=NULL)
    {//printf("1");
   if(external->info==external2->info){
         if(external2->address==NULL){
                //printf("Enterd");
            external3->address=NULL;
            free(external2);
            external2=external3;
            check=1;
         }
         else{
            external3->address=external2->address;
            free(external2);
          external2=external3;


         }

   }

   external3=external2;
         external2=external2->address;
}
check=0;
external=external->address;
}


}

void create_list(){
int choice;
printf("\n|1|.Insert a value at start: \n|2|.Insert a value at end: \n|3|.Delete a value from start: \n|4|.Delete a value at end: \n|5|.Insert a value at specific place:\n|6|.Delete a value from specific place:\n|7|.Display List 1:\n|8|.Create List:\n ");
scanf("%d",&choice);
while(choice!=8){
switch(choice){

case 1:
      in_start();
        break;

case 2:
      in_end();
    break;
case 3:
    del_start();
    break;
case 4:
    del_end();
    break;
case 5:
    in_specific();
    break;
case 6:
    del_specific();
    break;
case 7:
    display();
    break;


}
printf("\n|1|.Insert a value at start: \n|2|.Insert a value at end: \n|3|.Delete a value from start: \n|4|.Delete a value at end: \n|5|.Insert a value at specific place\n|6|.Delete a value from specific place:\n|7|.Display List 1:\n|8|.Create List:\n ");
scanf("%d",&choice);
}

}
void mergelists(){
    node *list1,*list2;
printf("----------------------------------");
printf("\nEnter the values in first list:");
printf("\n----------------------------------\n");
create_list();
list1=list;
list=NULL;
printf("----------------------------------");
printf("\nEnter the values in second list:");
printf("\n----------------------------------\n");
create_list();
list2=list;
list=NULL;
list=list1;
while(list1->address!=NULL){
    list1=list1->address;
}
list1->address=list2;
printf("\nMERGE LIST IS");
display();
}
//}*/


