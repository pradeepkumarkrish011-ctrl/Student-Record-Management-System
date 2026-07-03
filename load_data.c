#include "header.h"

void load_data(struct student **ptr)
{
    FILE *fp;
    struct student *temp, *last = NULL;

    fp = fopen("student.dat", "r");

    if(fp == NULL)
        return;

        // Reset before loading

    while(1)
    {
        temp = malloc(sizeof(struct student));

        if(temp == NULL)
        {
            printf("Memory Allocation Failed\n");
            fclose(fp);
            return;
        }

        if(fscanf(fp, "%d %s %f",
                  &temp->rollno,
                  temp->sname,
                  &temp->percent) != 3)
        {
            free(temp);
            break;
        }

        temp->next = NULL;

        /* Update next roll number */
        if(temp->rollno >= count)
            count = temp->rollno + 1;

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
/*
#include"header.h"
void load_data(struct student **ptr)
{
    FILE *fp;
    struct student *temp, *last = NULL;

    fp = fopen("student.dat", "r");

    if(fp == NULL)
    {
        return;
    }

    while(1)
    {
        temp = malloc(sizeof(struct student));

	if(temp == NULL)
        {
            printf("Memory Allocation Failed\n");
            fclose(fp);
            return;
        }

	if(fscanf(fp, "%d %s %f",
			&temp->rollno,
			temp->sname,
                        &temp->percent)!=3)
	{
		free(temp);
		break;
	}

       /* if(fread(temp, sizeof(struct student), 1, fp) != 1)
        {
            free(temp);
            break;
        }
	*/

       /* temp->next = NULL;

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
*/
