#ifndef functions   //file guard
#define functions   //file guard

#include <stdio.h>
#include <stdlib.h>
#define max 10
#define size 5

typedef char unit8;
typedef enum{false,true}bool;
typedef struct simple_DB node;
struct simple_DB {
	
	unit8 student_ID ;
	unit8 student_year ;
	unit8 course_ID[size];
	unit8 course_grade[size];
	node *next;
};

unit8 count = 0;

unit8 Position_Node(node*head,unit8 id){
	unit8 position = 1;
	while(head){
		if(head->student_ID==id){
			return position;
		}
		else{
			position++;
		}
		head = head->next;
	}
	return -1;
}

bool SDB_IsFull(void){
	if(count == max){
		return true;
	}
	else{
		return false;
	}
}
unit8 SDB_GetUsedSize(){
	return count;
}
bool SDB_AddEntry(unit8 id,unit8 year,unit8*subjects,unit8*grades,node**head){
	 if (SDB_IsFull())
    {
        printf("\nThe data base is already full\n\n");
        return false;
    }
	else{
		node*st = (node*)malloc(sizeof(node));
		subjects = st->course_ID;
		grades = st->course_grade;
		printf("Enter the ID of student number %d	\n",count+1);
		jump:
		scanf("%d",&id);
		st->student_ID = id;
		unit8 pos=Position_Node(*head,st->student_ID);
		if(pos==-1){
			count++;
			printf("\nEnter the year:\n");
			scanf("%d",&year);
			st->student_year=year;
			for(int i = 1 ; i < 4 ; i++){
				printf("\nEnter the course %d ID\n",i);
				scanf("%d",&subjects[i-1]);
				subjects++;
			}
			subjects=st->course_ID;
			for(int i = 1 ; i < 4 ; i++){
				printf("\nEnter the course %d grade\n",i);
				printf("from 0 to 100\n");
				label:
				scanf("%d",&grades[i-1]);
				if(grades[i-1] > 100 || grades[i-1] < 0){
					printf("invalid grade!!\n");
					printf("please enter a valid grade : \n");
					goto label;
				}
				grades++;
			}
			grades=st->course_grade;
			 if(*head==NULL)
        {
            *head=st;
            (*head)->next=NULL;
        }
        else
        {
            node*ptr=*head;
            while(ptr->next)
            {
                ptr=ptr->next;
            }
            ptr->next=st;
            (st)->next=NULL;
        }
        return true;
        }
        else
        {
            printf("\nThe id is already created\n");
            printf("Enter another id\n");
            goto jump;
		}
	}
}
void SDB_DeleteEntry(node**head,unit8 id){
	if(count==0){
		printf("\nThe database is empty\n\n");
		return;
	}
	unit8 p;
	node *p1=*head;
	node *p2=*head;
	printf("\nEnter the ID that you want to delete\n");
	jump1:
	scanf("%d",&id);
	p=Position_Node(*head,id);
	if(p<0)
    {
        printf("Invalid ID\n");
        printf("Please Enter another ID\n");
        goto jump1;
    }
	else{
		if(p==1)
        {
            node*ptr=*head;
            *head=(*head)->next;
            free(ptr);
        }
        for(int i=0;i<p-2;i++)
        {
            p2=p2->next;
            p1=p1->next;
        }
        p1=p1->next;
        p2->next=p1->next;
        count--;
        printf("The ID is successfully deleted\n\n");
	}
}
bool IsExist(node*head,unit8 id){
	printf("Enter the ID that you want to check\n");
	scanf("%d",&id);
	while(head)
    {
        if(head->student_ID==id)
            return true;
        else
            head=head->next;
    }
          return false;
}
bool SDB_ReadEntry(unit8 id,unit8*year,unit8**subject,unit8**grade,node*head)
{
    printf("Enter ID of student\n");
    scanf("%d",&id);
    unit8 p=Position_Node(head,id);
    if(p<0)
    {
        printf("invalid ID\n\n");
        return false;
    }
  else
    {
        for(int i=0;i<p-1;i++)
        head=head->next;
        *year=head->student_year;
        *subject=head->course_ID;
        *grade=head->course_grade;
    }
}
void SDB_GetList(node*head)
{
    if(count==0)
    {
        printf("The database is empty\n\n");
        return;
    }
    for(int i=0;i<count;i++)
    {
        printf("The student number %d",i+1);
        printf(" his id is = %d\n",head->student_ID);
        printf("\n");
        head=head->next;
    }
    printf("\n");
}

#endif
	 