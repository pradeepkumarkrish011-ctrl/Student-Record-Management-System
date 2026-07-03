#include"header.h"
void delete_data(struct student **ptr)
{
	int n,found,rollno;
	char ch ,name[20];

        struct student *temp,*temp1,*prev=0;
        temp=*ptr;
	temp1=*ptr;
	//pf("Enter the choice to delete the data\n");
	pf("'r'/'R' :delete by the roll no \n");
	pf("'n'/'N' : delete by the name \n");
	//pf("enter the option to delete :\n");
	sf(" %c",&ch);
	switch(ch)
	{
	case 'r':
	case 'R':
		pf("enter the roll no to delete :");
		sf("%d",&n);

        while(temp)
        {
                if(temp->rollno==n)
                {
                  if(temp==*ptr)
                    *ptr=temp->next;
                  else
                    prev->next=temp->next;
		  free(temp);
		  return;
                }
                else
                {
                        prev=temp;
                        temp=temp->next;
                }
        }
	pf("not found");
	break;
	case 'n':
	case 'N':
		pf("enter the name to delete data :");
		sf("%s",name);
		 temp = *ptr;

            printf("\nMatching Records\n");
            printf("------------------------------------------\n");
            printf("Roll\tName\tPercentage\n");
            printf("------------------------------------------\n");

            while(temp)
            {
                if(strcasecmp(temp->sname, name) == 0)
                {
                    printf("%d\t%s\t%.2f\n",
                           temp->rollno,
                           temp->sname,
                           temp->percent);
                    found = 1;
                }
                temp = temp->next;
            }

            if(found == 0)
            {
                printf("No Record Found.\n");
                return;
            }
	    printf("\nEnter Roll Number : ");
            scanf("%d", &rollno);

            temp = *ptr;

            while(temp)
            {
                if(temp->rollno == rollno)
                    break;

                temp = temp->next;
            }

            break;


		while(temp1)
		{
			if(strcasecmp(temp1->sname,name)==0)
					{
					if(temp1==*ptr)
					*ptr=temp1->next;
					else
					prev->next=temp1->next;
					free(temp);
					return;
					
		             		}
				else
				{
				prev=temp1;
				temp1=temp1->next;
				}
		}
		pf("not found");
		break;
	}



		

}
