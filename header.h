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
void load_data(struct student **);
extern int count;
