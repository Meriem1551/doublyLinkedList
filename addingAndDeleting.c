#include<stdio.h>
#include "linkedlistFunctions.h"
int main(){
    node *l,*p=NULL;
    int choice1,n,pos,lenght=1;
    char choice2,after_before;
          n=getInput();
          l=createNode(n);
    do{
      printf("enter 1 for adding a node at the begining\n");
      printf("enter 2 for adding a node at the end\n");
      printf("enter 3 for adding a node at the middle\n ");
      printf("enter 4 for deleting from the begining \n");
      printf("enter 5 for deleting from the end\n");
      printf("enter 6 for deleting from the middle\n");
      scanf("%d",&choice1);
        switch(choice1){
            case 1:
             n=getInput();
             p=addAtTheBeg(n,l);
             lenght++;
             display(p);
            break;
            case 2:
              n=getInput();
              p=addAtTheEnd(n,l);
              lenght++;
              display(p);
            break;
            case 3:
              pos=getPosition(lenght);
              n=getInput();
              printf("enter a for after this position, enter b for before it \n");
              scanf("%c",&after_before);
              if(after_before=='a'){
                p=addAfter(n,pos,l);
              }
              else{
                p=addBefore(n,pos,l);
              }
              display(p);
            break;
            case 4:
              p=deletFromBeg(l);
              display(p);
            break;
            case 5:
              p=deletFromEnd(l);
              display(p);
            break;
            case 6:
              pos=getPosition(lenght);
             p=deletFromMiddle(pos,l);
             display(p);
            break;
        }
        printf("you want to continue ?  alright enter y for yes or n for n \n");
        scanf("%c",&choice2);
    }
    while(choice2!='n');
}