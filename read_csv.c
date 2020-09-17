#include<stdio.h>
#include<stdlib.h>
void read_csv(const char* csv_filename)
{
	FILE *s=fopen(csv_filename,"rt");
	if(s==NULL)exit(1);
	char record[1000];
	fgets(record,999,s);
	while(!feof(s))
	{        
		printf("%s",record);
		fgets(record,999,s);
	}
	fclose(s);
}

