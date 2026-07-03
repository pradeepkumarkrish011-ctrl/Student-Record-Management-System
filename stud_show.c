#include"header.h"
void show_data(struct student *ptr)
{
          pf("\nDisplaying details:");
	  printf("\n-------------------------------------------------\n");
	  printf("roll no\t\tName\t\tpercent\n");
	  printf("\n-------------------------------------------------\n");
          while(ptr!=0)
         {
                 pf("%d\t\t%s\t\t%.2f\n"
			,ptr->rollno
			,ptr->sname
			,ptr->percent);
                 ptr=ptr->next;
	 }
	  printf("----------------------------------------------------\n");

}
