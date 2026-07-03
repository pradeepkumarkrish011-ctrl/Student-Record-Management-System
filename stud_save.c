#include"header.h"
void save_data(struct student *ptr)
{
	struct student *temp;
	FILE *fp=fopen("student.dat","w");
	if(fp==NULL)
	{
		pf("\nunable to open the file");
	        return;
	}
         pf("\nSaving data");
          while(ptr!=0)
         {
                 fprintf(fp, "%d %s %.2f\n",ptr->rollno
				 ,ptr->sname,
				 ptr->percent);
		 ptr=ptr->next;
	 }
	 fclose(fp);
}
