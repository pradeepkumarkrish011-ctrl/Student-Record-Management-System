#include"header.h"
void add_data(struct student **ptr)
{
     
        struct student *temp;
        temp=(struct student*)malloc(sizeof(struct student));
        temp->rollno=count++;
        pf("\nStudent name:");
        sf("%s",temp->sname);
        pf("\nStudent percent:");
        sf("%f",&temp->percent);
        if(*ptr==0)
        {
          temp->next=0;
          *ptr=temp;
        }
        else
        {
         struct student *last=*ptr;
         while(last->next!=0)
             last=last->next;
         temp->next=0;
         last->next=temp;
        }
}
