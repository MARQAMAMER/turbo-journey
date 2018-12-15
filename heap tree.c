#include<stdio.h>
int heap[10],left,right,position,parent,number=0,last,first,sort[10],q=0,number2;
void insert_heap();
void display();
void sort1();

int main(){
int choice;
printf("1.Insert value in tree: \n2.Display heap tree: \n3.Display sortheap: \n4.Exit");
scanf("%d",&choice);
while(choice!=4){
switch(choice){
case 1:
insert_heap();
break;

case 2:
   display();
    break;
case 3:
    sort1();
    break;

}
printf("1.Insert value in tree: \n2.Display heap tree: \n3.Display sortheap: \n4.Exit");
scanf("%d",&choice);
}}
void insert_heap(){
    int value,temp,n=0;
printf("Enter the value in heap tree:");
scanf("%d",&value);
number++;
number2=number;
position=number;
heap[number]=value;
while(position>1&&n!=1){
         parent=position/2;
         if(heap[parent]<heap[position]){
            temp=heap[parent];
            heap[parent]=heap[position];
            heap[position]=temp;
            position=parent;
         }
         else{
           n=1;
         }


}
}
void display(){
    int i;
for(i=1;i<=number;i++){

    printf("%d  ",heap[i]);
}
}
void delete_heap(){
int check=0,temp2;
last=heap[number];
number--;
first=1;
left=2;
right=3;
sort[q]=heap[first];
q++;
heap[first]=last;
while(left<=number&&check!=1){
if(heap[first]>heap[left]&&heap[first]>heap[right]){
    check=1;
}
else if(heap[left]>=heap[right]){
    temp2=heap[left];
    heap[left]=heap[first];
    heap[first]=temp2;
    first=left;
}
else{
  temp2=heap[right];
    heap[right]=heap[first];
    heap[first]=temp2;
    first=right;
}
left=2*first;
right=left+1;
}

}

void sort1(){
    int w;
for(w=0;w<=number2;w++){
    delete_heap();
}
int j=0;
printf("\n");
for(j=q-1;j>0;j--){
    printf("%d  ",sort[j]);
}

}
