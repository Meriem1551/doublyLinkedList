#include<stdlib.h>
#include<stdio.h>
#include"structures.h"
int getInput(){
    int num;
    printf("please,give me the data ");
    scanf("%d",&num);
    return num;
}
node *createNode(int theData){
node *firstNode=NULL;
firstNode = (node*)malloc(sizeof(node));
firstNode->data=theData;
firstNode->next=NULL;
firstNode->previous=NULL;
head=firstNode;
return head;
}
node *addAtTheBeg(int Data,node*start){
    node *newnode=NULL;
    if(start==NULL){
        start=createNode(Data);
    }
    else{
      newnode = (node*)malloc(sizeof(node));
     newnode->data=Data;
     newnode->next=start;
     newnode->previous=NULL;
     start->previous=newnode;
     start->next=NULL;
     start=newnode;
    }
    return start;
}
node *addAtTheEnd(int Data,node*start){
    node *newnode=NULL;
    if(start==NULL){
        start=createNode(Data);
    }
    else{
     newnode = (node*)malloc(sizeof(node));
     newnode->data=Data;
     newnode->next=NULL;
     newnode->previous=start;
     start->next=newnode;
     start->previous=NULL;
    }
    return start;
}
int getPosition(int lenght){
    int pos,error;
    printf("enter the position \n ");
    scanf("%d",&pos);
    if (pos>lenght || pos<1){
       printf("please enter a valid position \n ");
    }
    else{
      return pos;
    }
}
node *addAfter(int Data,int position,node *start){
    int i;
    node*ptr=start,*newnode=NULL;
    if(start==NULL){
        createNode(Data);
    }
    else{
       for(i=0;i<position-1;i++){
           ptr=ptr->next;
       }
       newnode=(node*)malloc(sizeof(node));
       newnode->data=Data;
       newnode->next=ptr->next;
       ptr->next->previous=newnode;
       ptr->next=newnode;
       newnode->previous=ptr;
    }
    return start;
}
node *addBefore(int Data,int position,node* start){
    int i;
    node *ptr=start,*newnode=NULL;
    if (start==NULL)
    {
        createNode(Data);
    }
    else{
        for(i=0;i<position-1;i++){
           ptr=ptr->next;
        } 
       newnode=(node*)malloc(sizeof(node));
       newnode->data=Data;

       newnode->next=ptr;
       ptr->previous->next=newnode;
       newnode->previous=ptr->previous;
       ptr->previous=newnode;
    }
    return start;
}
node *deletFromBeg(node *start){
    node *ptr=start;
    if(start==NULL){
        printf(" list is empty \n");
    }
    else{
        if(start->next==NULL){
            start=NULL;
        }
        else{
            start=ptr->next;
            start->previous=NULL;
            free(ptr);
        }
    }
    return start;
}
node *deletFromEnd(node *start){
    node *ptr=start;
    if(start==NULL){
        printf("list is empty \n");
    }
    else{
        if(start->next==NULL){
            start=NULL;
        }
        else{
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->previous->next=NULL;
            free(ptr);
        }
    }
    return start;
}
node * deletFromMiddle(int position,node *start){
    int i;
    node * ptr=start;
    if(start==NULL){
        printf("empty list \n");
    }
    else{
        for(i=0;i<position-1;i++){
            ptr=ptr->next;
        }
        ptr->previous->next=ptr->next;
        ptr->next->previous=ptr->previous;
        free(ptr);
    }
    return start;
}
void display(node *pointer){
    while(pointer!=NULL){
        printf("%d -> \n",pointer->data);
        pointer=pointer->next;
    }
}