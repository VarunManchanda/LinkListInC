/*
                         Link-List Program and has all Functions like:-
                         1)Insertion(at beginning, at end, after specific element, before specifc element)
                         2)Deletion(from beginning, from end, of specific element, or whole List at a go...)
                         3)Traversing(also, shows Addresse's of Nodes)
*/
#include<stdio.h>
#include<stdlib.h>
int start=0,last=0;
struct node* foundElement(int);
struct node* foundPredecessorElement(struct node*);
int findThatBloodyElement(int);
struct node{
int value;
struct node *next;
};
struct node *head = NULL;

struct node* createNode(){
struct node *temp;
temp = (struct node *)malloc(sizeof(struct node));
return(temp);
}
void traverseList(){
struct node *temp;
if(head==NULL){
printf("List is Empty\n");
}
else{
temp  = head;
printf("------Link List is------>\n");
while(temp->next != NULL){
printf("%d->", temp->value);
temp = temp->next;
}
printf("%d", temp->value);
}
}

void traverseListAddress(){
struct node *temp;
if(head==NULL){
printf("List is Empty\n");
}
else{
temp = head;
while(temp->next != NULL){
printf("\n----------------------");
printf("\n| %d|%p  |------>", temp->value, temp);
printf("\n----------------------");
temp = temp->next;
}
printf("\n----------------------");
printf("\n| %d|%p(NULL)  |", temp->value, temp);
printf("\n----------------------");
}
}

void insertNode(){
struct node *t, *t1;
t = createNode();
printf("Enter a Value\n");
scanf("%d", &t->value);
t->next = NULL;
if(head==NULL){ //Insertion at Beginning.
head = t;
start = t->value;
printf("Insertion Successfully\n");
}
else{ //Insertion at Last.
t1 = head;   
while(t1->next != NULL){
t1 = t1->next;
}
t1->next = t;
last = t->value;
printf("Insertion Successfully\n");
}
}
void insertAfterElement(int value){
struct node *foundElementAddress, *temp1;
if(head==NULL){
printf("List is Empty\n");
}
else{
foundElementAddress = foundElement(value);
temp1 = createNode();
printf("Enter New Value\n");
scanf("%d", &temp1->value);
temp1->next = foundElementAddress->next;
foundElementAddress->next = temp1;
printf("Insertion Successfully\n");
last = temp1->value;
}
}

void insertBeforeElement(int value){
struct node *loc, *ptr, *ploc;
if(head==NULL){
printf("List is Empty\n");
}
else if(value==head->value){
printf("You are Inserting at Starting!, I am intelligently Developed\n");
ptr = createNode();
printf("Enter New Value\n");
scanf("%d", &ptr->value);
ptr->next = head;
head = ptr;
printf("Inserted Successfully at Starting!!!!\n");
start = ptr->value;
}
else{
loc = foundElement(value);
ploc = foundPredecessorElement(loc);
ptr = createNode();
printf("Enter New Value\n");
scanf("%d", &ptr->value);
ptr->next = loc;
ploc->next = ptr;
printf("Insertion Successfully\n");
}
}

void deleteFromBeginning(){
struct node *ptr;
if(head==NULL){
printf("List is already Empty!\n");
}
else{
ptr = head;
head = head->next;
free(ptr);
printf("Deletion Successfully\n");
}
}

void deleteFromEnd(){
struct node *ptr, *ploc;
if(head==NULL){
printf("List is Empty, Sir/Madam\n");
}
else{
ptr = head;
while(ptr->next != NULL){
ptr = ptr->next;
}
ploc = foundPredecessorElement(ptr);
ploc->next = NULL;
free(ptr);
printf("Deletion Successfully\n");
}
}

void deleteSpecificElement(int value){
struct node *loc, *ploc;
int found = 0;
found = findThatBloodyElement(value);
if(found==0){
printf("Element doesn't Exist, So Exiting...\n");
exit(0);
}
else if(start==value){
printf("You are Deleting Starting Element, I am... I am Intelligent!!\n");
deleteFromBeginning();
printf("Deleted!!\n");
}
else if(last==value){
printf("You are Deleting Last Element, As I said I am Intelligent!!\n");
deleteFromEnd();
printf("btw, Deleted Successfully\n");
}
else{
loc = foundElement(value);
ploc = foundPredecessorElement(loc);
ploc->next = loc->next;
free(loc);
printf("Deletion Successfully!!\n");
}
}

void deleteWholeList(){
struct node *ptr;
if(head==NULL){
printf("List is already Empty\n");
}
else{
while(head!=NULL){
ptr = head;
head = head->next;
free(ptr);
}
printf("Whole List is Empty, Now!!\n");
}

}

void main(){
int choice, value, delvalue;
while(1){
printf("\n1)Insertion\n2)Insertion After an Element\n3)Insert Before an Element\n4)Delete From Beginnning\n5)Delete From End\n6)Delete a Specific Element\n7)Traverse Link List\n8)Traverse List with Finding Addresses also\n9)Delete Whole List\n10)Exit\n");
scanf("%d", &choice);
if(choice==1) insertNode();
else if(choice==2){
printf("Enter the Value of that Element After you want to Insert your New Node\n");
scanf("%d", &value);
insertAfterElement(value);
}
else if(choice==3){
printf("Enter the Value of that Element before you want to Insert your New Node\n");
scanf("%d", &value);
insertBeforeElement(value);
}
else if(choice==4){
deleteFromBeginning();
}
else if(choice==5){
deleteFromEnd();
}
else if(choice==6){
printf("Enter the Element you want to Delete!!\n");
scanf("%d", &delvalue);
deleteSpecificElement(delvalue);
}
else if(choice==7){
traverseList();
}
else if(choice==8){
traverseListAddress();
}
else if(choice==9){
deleteWholeList();
}
else if(choice==10){
printf("Exiting....\n");
exit(0);
}
else{
printf("Wrong Choice, you Dump!: Exiting.....\n");
exit(0);
}
}

}//Main End!
struct node* foundElement(int value){
struct node *temp;
temp = head;
while(temp->next != NULL){
if(temp->value==value){
return(temp);
}
temp = temp->next;
}
if(temp->value==value){ //this is for if value is at Last.
printf("You are Inserting in Last, I am Intelligent than You!!!\n");
return(temp);
}
}

struct node* foundPredecessorElement(struct node *loc){
struct node *ploc, *temp;
ploc = head;
temp = head;
while(temp ->next !=NULL){
temp = temp->next;
if(temp==loc){
return(ploc);
}
else{
ploc = temp;
}

}
return(ploc);
}

int findThatBloodyElement(int value){
if(head==NULL){
printf("List is Empty;)\n");
return 0;
}
while(head->next != NULL){
if(head->value==value){
return 1;
}
head = head->next;
}
if(head->value==value)
return 1;
else
return 0;
}
