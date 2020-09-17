#include "convert_to_csv.h"
#include "read_csv.h"
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
void find_name(const char* csv_filename,const char* name)
{
	int isprint=0;
	FILE *s=fopen(csv_filename,"rt");
	if(s==NULL)exit(1);
	char array[1000];
	fgets(array,999,s);
	while(!feof(s)){
		char temp[1000];
		strcpy(temp,array);
		char *tempnew=strtok(temp,",");
		if(strcmp(tempnew,name)==0)
		{
			printf("%s",array);
			isprint=1;
		}
		fgets(array,999,s);
	}
        if(isprint==0)
	{
		printf("Name not found\n");
	}
	fclose(s);
}


void add_record(const char* csv_filename,const char* name,const int age, const char* city)
{
	FILE *d=fopen(csv_filename,"at");
	if(d==NULL)exit(1);
	fprintf(d,"%s, %d, %s\n",name,age,city);
	fclose(d);

}

void delete_record(const char* csv_filename,const char* name)
{
	FILE *s=fopen(csv_filename,"rt"),*d=fopen("copy.txt","wt");
	if(s==NULL || d==NULL)exit(1);
	char array[1000];
	fgets(array,999,s);
	int isread=0;
	while(!feof(s))
	{
		char temp[1000];
		strcpy(temp,array);
		char *tempnew=strtok(temp,",");
          if((strcmp(tempnew,name)==0) && isread==0)
	  {

		  isread=1;
		  fgets(array,999,s); 
		  continue;
	  }
	  fputs(array,d);
	  fgets(array,999,s);
	}
	fclose(s);
	fclose(d);
	//delete the original file
	remove(csv_filename);
	//change the copy file to csv_filename
	rename("copy.txt",csv_filename);
}
	 





int main()
{
	/*Question1*/
	load_and_convert("input.txt");
	/*Question2*/
	read_csv("output.csv");
        
	/*Question 3.1*/
	find_name("output.csv","Maria");
	find_name("output.csv","Jason");
        
	/*Question 3.2*/
	add_record("output.csv","Jason",36,"Skookumchuk");
	read_csv("output.csv");
	
	/*Question 3.3*/
        delete_record("output.csv","Maria");
        read_csv("output.csv");

	
	return 0;
}
