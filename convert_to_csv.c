#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void load_and_convert(const char* filename)
{
	FILE *s=fopen(filename,"rt"),*d=fopen("output.csv","wt");
	if(s==NULL || d==NULL)exit(1);
        char name[1000];
        char age[1000];
        char place[1000];
        fgets(name,999,s);
        fgets(age,999,s);
        fgets(place,999,s);
        name[strlen(name)-1]='\0';
        age[strlen(age)-1]='\0';
        place[strlen(place)-1]='\0';
        
        //split the line into words
	char *na;
	char *ag;
	char *pl;
	char *np=name;
	char *ap=age;
	char *pp=place;
	na=strtok_r(np," ",&np);
        ag=strtok_r(ap," ",&ap);
        pl=strtok_r(pp," ",&pp);
        while(na!=NULL && ag!=NULL && pl!=NULL)
	{
	    fprintf(d,"%s, %s, %s\n",na,ag,pl);
            na = strtok_r(np," ",&np);
            ag = strtok_r(ap," ",&ap);
            pl = strtok_r(pp," ",&pp);
        }

	if(na!=NULL || ag!=NULL || pl!=NULL)
	{
		printf("The lines do not have same numbers of field");
		exit(2);
	}

	fclose(s);
	fclose(d);
}

                

