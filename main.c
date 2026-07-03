#include"header.h"
int count=1;
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
        pf("Enter your choice:");
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
		case 'T':
		case 't':
			 sort_list(&hptr);
			 break;

                case 'E':
                case 'e':
			 pf("'s'/'S' : save and exit :\n");
			 pf("'e'/'E' : exit without save : \n");
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
