#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void converter(int n){
        int a[1000];
        int i;
	for(i=0;n>0;i++)
        {
                a[i]=n%2;
                n=n/2;
        }
         for(i=i-1;i>=0;i--)
        {       
                printf("%d",a[i]);
        }
}


void main(){
	char *data=getenv("QUERY_STRING");
	int n;
	sscanf(data,"number=%d",&n);
   
        
        printf("Content-Type:text/html\n\n");
	printf("<html>");
	printf("<head><title>output</title></head>");
	printf("<body>");
	converter(n);
	printf("</body>");

	printf("</html>");
}


