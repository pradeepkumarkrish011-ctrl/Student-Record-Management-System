#include"header.h"
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
