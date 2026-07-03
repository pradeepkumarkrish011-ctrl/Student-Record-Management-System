#include"header.h"
void sort_list(struct student **ptr)
{
	struct student *temp,*temp1;
	char ch;
       int flag;
       int rollno;
       char name[30];
       float percent;
       if((*ptr==0)||((*ptr)->next==0))
	       pf("No record to sort\n");
       pf("'n'/'N' : sort by name \n");
       pf("'p'/'P' : sort by percent\n");
       pf("\nenter the choice to sort :");
      sf(" %c",&ch);
     switch(ch)
     {
	case 'n':
	case 'N':
	    do
	    {
		   flag=0;
		  temp=*ptr;
		 //temp1=temp->next;
		while(temp->next)

		{
			temp1=temp->next;
			if(strcmp(temp->sname,temp1->sname)>0)
			{
				rollno=temp1->rollno;
				temp1->rollno=temp->rollno;
				temp->rollno=rollno;


				strcpy(name,temp1->sname);
				strcpy(temp1->sname,temp->sname);
				strcpy(temp->sname,name);

				percent=temp1->percent;
				temp1->percent=temp->percent;
				temp->percent=percent;

				flag=1;

			}

			temp=temp->next;
		}
		}while(flag);
		pf("Sorted by Name Successfully\n");
		break;
		    case 'p':
		    case 'P':
			do
			{
				flag=0;
				temp=*ptr;
				//temp1=temp->next;
				while(temp->next)
				{
					temp1=temp->next;
					if(temp->percent>temp1->percent)
					{

						rollno=temp1->rollno;
						temp1->rollno=temp->rollno;
						temp->rollno=rollno;


						strcpy(name,temp1->sname);
						strcpy(temp1->sname,temp->sname);
						strcpy(temp->sname,name);

						percent=temp1->percent;
						temp1->percent=temp->percent;
						temp->percent=percent;

						flag=1;
					}


					temp=temp->next;
				}
			}while(flag);

			       		pf("Sorted by percent Successfully\n");
				break;
     }
}
