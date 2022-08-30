#include"functions.h"


int main()
{
    node*head=NULL;
    unit8 st_id,year,grade[3],course_id[3],op,*subjects,*grades;
    jump5:
	
	printf("\n\n");
    printf("1.Check if the list is full\n");
    printf("2.The number of students in the list\n");
    printf("3.Add student account\n");
    printf("4.Delete student account\n");
    printf("5.check student account with ID\n");
    printf("6.The list of students\n");
    printf("7.The student account is exist or not\n");
    printf("8.Close the program\n");
    scanf("%d",&op);
    switch(op)
    {
  case 1:
        {
           if(SDB_IsFull())
            printf("The database is full\n");
           else
            printf("The data base is not full\n\n");
            goto jump5;
        }
  case 2:
        {
           unit8 n=SDB_GetUsedSize();
           printf("The number of students is %d",n);
           printf("\n\n");
           goto jump5;
        }
  case 3:
        {
           if(SDB_AddEntry(st_id,year,subjects,grades,&head))
           {
               printf("The entry is added successfully\n\n");
           }
           goto jump5;
        }
  case 4:
        {
            SDB_DeleteEntry(&head,st_id);
            goto jump5;
        }
  case 5:
        {
            if(count==0)
            {
                printf("The database is empty\n\n");
                goto jump5;
            }
            if(SDB_ReadEntry(st_id,&year,&subjects,&grades,head))
            {
                printf("The year is %d",year);
                printf("\n");
            for(int i=1;i<4;i++)
              {
                printf("The course %d",i);
                printf(" id %d",subjects[i-1]);
                printf("\n");
                subjects++;
              }
            for(int i=1;i<4;i++)
              {
                printf("The course %d",i);
                printf(" grade %d",grades[i-1]);
                printf("\n");
                grades++;
              }
            }
                goto jump5;
        }
  case 6:
        {
                SDB_GetList(head);
                goto jump5;
        }
  case 7:
        {
                if(IsExist(head,st_id))
                {
                    printf("The id exists in the database\n\n");
                    goto jump5;
                }
                else
                {
                    printf("The id not exist in the database\n\n");
                    goto jump5;
                }
        }
  case 8:
        {
             printf("You are now out\n");
             exit(0);
        }
    }
}