#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct student {
    char name[21];
    int roll;
} s;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	//Given that we have to take input of 10 students
	char destination[] = "C:\\Users\\ABHISHEK\\Documents\\";
    char source[100];
    printf("Please Enter the name of the file:\n");
    scanf("%s",source);
    strcat(destination,source);
   
    //Building the source of file by taking file name from user
    printf("Please enter 1 for file in text format 2 for file in binary format\n");
    int choice;
    scanf("%d",&choice);
    FILE *fptr;
    if(choice==1)
    {
    	 char temp[]= ".txt";
         strcat(destination,temp);
    	 fptr=(fopen(destination,"w"));
	}
	else if(choice==2)
	{
		char temp[]= ".bin";
        strcat(destination,temp);
	   fptr=(fopen(destination,"wb"));
	}
	else
	{
		printf("Invalid Input\n");
		return 0;
	}
    
  
	if(fptr==NULL) 
	{
		printf("Error!");
		exit(1);
	}
	int tot=10;
	int i;
	for (i=0;i<tot;++i) 
	{
		struct student temp;
		printf("\nFor student %d\nEnter name: ",i+1);
		scanf("%s",&temp.name); 
		printf("Enter roll: ");
		scanf("%d",&temp.roll);
		fprintf(fptr,"\nName : %s   Roll : %d\n",temp.name,temp.roll);
	}
	printf("File Created Successfully under the name : %s",source);
	fclose(fptr);
	
    return 0;
}
