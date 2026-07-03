#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#define pf printf
#define sf scanf

struct student
{
        int rollno;
        char sname[20];
        float percent;
        struct student *next;
};
void add_data(struct student **);
void delete_data(struct student**);
void show_data(struct student*);
void save_data(struct student*);
void modify_data(struct student**ptr);
void sort_list(struct student**ptr);
void load_data(struct student **ptr);



int main()
{
        char ch,op,ch1,cname,ch2;
        int n;
        struct student *hptr=0;
        pf("*********************STUDENT RECORD MENU***************************");
        pf("\nA/a : Add New Record");
        pf("\nD/d : Delete a Record");
        pf("\nS/s : Show the List");
        pf("\nM/m : Modify a Record");
        pf("\nV/v : Save");
        pf("\nT/t : Sort the List");
        pf("\nE/e : Exit");
        pf("\n");
	load_data(&hptr);
do
{
        pf("\nEnter your choice:");
        sf(" %c",&ch);
        switch(ch)
        {
                case 'A':
                case 'a':
			add_data(&hptr);
			break;
    
                case 'D':
                case 'd':delete_data(&hptr);
                                  break;
                        
                case 'S':
                case 's':show_data(hptr);
                         break;
                case 'M':
                case 'm':
                         modify_data(&hptr);
                         break;
                case 'V':
                case 'v':
                         save_data(hptr);
                         break;
                case 'E':
              case 'e':
			 pf("'s'/'S' : save and exit \n");
			 pf("'e'/'E' : exit without save \n");
                        pf("Enter your choice:");
                        sf(" %c",&ch2);
                        switch(ch2)
                        {
                         case 'S':
                         case 's':
                         pf("\nsave and exit" );
                         save_data(hptr);
			 exit(0);
                         case 'E':
                         case 'e':
                         pf("\nexit");
			 exit(0);
		       }

        }
}while((ch!='E')||(ch!='e'));
}


void load_data(struct student **ptr)
{
    FILE *fp;
    struct student *temp, *last = NULL;

    fp = fopen("student.dat", "rb");

    if(fp == NULL)
    {
        printf("No previous data found.\n");
        return;
    }

    while(1)
    {
        temp = (struct student *)malloc(sizeof(struct student));

        if(fread(temp, sizeof(struct student), 1, fp) != 1)
        {
            free(temp);
            break;
        }

        temp->next = NULL;

        if(*ptr == NULL)
        {
            *ptr = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }

    fclose(fp);
}

void add_data(struct student **ptr)
{
        static int count=1;
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

void show_data(struct student *ptr)
{
          pf("\nDisplaying details:");
	  printf("\n-------------------------------------------------\n");
	  printf("roll no\t\tName\t\tpercent\n");
	  printf("\n-------------------------------------------------\n");
          while(ptr!=0)
         {
                 pf("%d\t\t%s\t\t%f\n"
			,ptr->rollno
			,ptr->sname
			,ptr->percent);
                 ptr=ptr->next;
	 }
	  printf("----------------------------------------------------\n");

}


void modify_data(struct student **ptr)
{
    struct student *temp;
    temp=*ptr;
    char ch, op, name[30];
    int rollno;
    float percent;
    int found = 0;

    printf("\nR/r : Search by Roll Number");
    printf("\nN/n : Search by Name");
    printf("\nP/p : Search by Percentage");
    printf("\nEnter Your Choice : ");
    scanf(" %c", &ch);

    switch(ch)
    {
        case 'R':
        case 'r':

            printf("Enter Roll Number : ");
            scanf("%d", &rollno);

            temp=*ptr;
	    

            while(temp)
            {
                if(temp->rollno == rollno)
                {
                    found = 1;
                    break;
                }
                temp = temp->next;
            }

            if(found == 0)
            {
                printf("Record Not Found.\n");
                return;
            }

            break;

        case 'N':
        case 'n':

            printf("Enter Name : ");
            scanf("%s", name);

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

        case 'P':
        case 'p':

            printf("Enter Percentage : ");
            scanf("%f", &percent);

            temp = *ptr;

            printf("\nMatching Records\n");
            printf("------------------------------------------\n");
            printf("Roll\tName\tPercentage\n");
            printf("------------------------------------------\n");

            while(temp)
            {
                if(temp->percent == percent)
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

        default:
            printf("Invalid Choice.\n");
            return;
    }

    printf("\nN/n : Modify Name");
    printf("\nP/p : Modify Percentage");
    printf("\nEnter Your Choice : ");
    scanf(" %c", &op);

    switch(op)
    {
        case 'N':
        case 'n':

            printf("Enter New Name : ");
            scanf("%s", temp->sname);

            printf("Name Updated Successfully.\n");
            break;

        case 'P':
        case 'p':

            printf("Enter New Percentage : ");
            scanf("%f", &temp->percent);

            printf("Percentage Updated Successfully.\n");
            break;

        default:
            printf("Invalid Choice.\n");
    }
}

void save_data(struct student *ptr)
{
	struct student *temp;
	*temp=*ptr;
	FILE *fp=fopen("data1.txt","w");
         pf("\nSaved data");
          while(ptr!=0)
         {
                 fprintf(fp, "\n%d %s %f",ptr->rollno
				 ,ptr->sname,
				 ptr->percent);
		 ptr=ptr->next;
	 }
	 fclose(fp);
}
/*
void sort_list(struct student **ptr)
{
	struct student *temp,*temp1;
	char ch;
       int flag;
       int rollno;
       char name[30];
       float percent;
       if(*ptr==0||*ptr->next==0)
	       pf("No record to sort\n");
       pf("'n'/'N' : sort by name \n");
       pf("'p'/'P' : sort by percent\n");
       pf("\nenter the choice to sort :");
      sf("%c",&ch);
     switch(ch)
	case 'n':
	case 'N':
	    do
	    {
		   flag=0;
		  temp=*ptr;
		 temp1=temp->next;
		while(temp->next)

		{
			if(strcmp(temp->sname,temp1->sname)>0)
			{
				rollno=temp1->rollno;
				temp1->rollno=temp->rollno;
				temp->rollno=rollno;


				name=temp1->sname;
				temp1->sname=temp->sname;
				temp->sname=name;

}
}
}
} 
*/
