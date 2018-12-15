#include<stdio.h>
struct Node{
struct Node *left;
struct Node *right;
int info;

};
typedef struct Node node;
void insert_value();
void in_order(struct Node *tree);
void pre_order(struct Node *tree);
void post_order(struct Node *tree);
void largest_value();
void smallest_value();

node *tree=NULL,*child=NULL,*parent=NULL,*new_node;
int main(){
    int choice;
printf("1.Add a value in tree : \n2.In-order traversal: \n3.pre-order traversal: \n4.post-order traversal: \n5.Find smallest value: \n6.Find largest value ");
scanf("%d",&choice);
while(choice!=7){
switch(choice){
case 1:
insert();
break;

case 2:
in_order(tree);
break;

case 3:
    pre_order(tree);
    break;

case 4:
    post_order(tree);
    break;

case 5:
    smallest_value();
    break;

case 6:
    largest_value();
    break;



}
printf("1.Add a value in tree : \n2.In-order traversal: \n3.pre-order traversal: \n4.post-order traversal: \n5.Find smallest value: \n6.Find largest value ");
scanf("%d",&choice);
}
}

void insert(){
 new_node=(node*)malloc(sizeof(node));
        printf("Enter the a value to insert in tree :");
        scanf("%d",&new_node->info);
       new_node->left=NULL;
        new_node->right=NULL;
        if(tree==NULL){
        tree=new_node;
        tree->left=NULL;
        tree->right=NULL;
        }
        else{
            parent=tree;
            child=tree;
            while(child!=NULL&&parent->info!=new_node->info){
                parent=child;

                if(new_node->info<parent->info){
                    child=child->left;
                }
                else{
                    child=child->right;
                }

            }
             if(new_node->info==parent->info){
                    printf("THIS VALUE IS ALREADY EXISTING IN TREE :");
                }
            else if(new_node->info<parent->info){
                parent->left=new_node;
            }
            else{
                parent->right=new_node;
            }

        }
}

void in_order(struct Node *tree){

if(tree!=NULL){


    in_order(tree->left);
    printf("%d  ",tree->info);
    in_order(tree->right);
}


}
void pre_order(struct Node *tree){

if(tree!=NULL){

        printf("%d  ",tree->info);
    pre_order(tree->left);

    pre_order(tree->right);
}


}
void post_order(struct Node *tree){

if(tree!=NULL){


    post_order(tree->left);
    post_order(tree->right);
     printf("%d  ",tree->info);
}
}
void smallest_value(){

child=tree;
parent=tree;

while(child!=NULL){
    parent=child;
    child=child->left;

}
printf("\nSmallest value is %d in the tree : ",parent->info);

}
void largest_value(){

child=tree;
parent=tree;

while(child!=NULL){
    parent=child;
    child=child->right;

}
printf("\nLargest value is %d in the tree : ",parent->info);

}
