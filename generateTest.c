#include <stdio.h>
#include<string.h>
#include<math.h>

int crearArchivo(char * nombreArchivo,char * orden){
	FILE *fp;
	int lim;
	if (strcmp(orden,"kilo") == 0)
		 lim = pow(2,10-3);
	else if (strcmp(orden,"mega") == 0)
		 lim = pow(2,20-3);
		else if (strcmp(orden,"giga") == 0)
			 lim = pow(2,30-3);

	fp=fopen(nombreArchivo,"w");
	if (fp == NULL)
	{
		printf("Error opening %s!\n",nombreArchivo);
		return 0;
	}
	fprintf(fp, "/*\n");
	for(int i=0;i<lim;i++){
		fputs("aaaaaa",fp);			
		fputc('\n',fp);
	};
	fprintf(fp, "*\\\n");
	fclose(fp);
	return 0;
	}
	
int main(void){

	crearArchivo("testKilo.c","kilo");
	crearArchivo("testMega.c","mega");
	crearArchivo("testGiga.c","giga");
	return 0;
}