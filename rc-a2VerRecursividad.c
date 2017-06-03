#include <stdio.h>
int c, cAnterior;
enum caracteres {
	APOSTROFE = 39,
	COMILLAS = 34,
	LF = 10,
	CONTRABARRA=92
};
FILE *fp;
FILE *fpe;
void codigoSinComentarios(void);
void barra1(void);
void barra2(void);
void cadena(void);
void escapeCadena(void);
void asterisco(void);
void asteriscosPalabras(void);
void caracter(void);
void escapeCaracter(void);

void codigoSinComentarios(){
	fputs("codigoSinComentarios\n",fpe);
	switch(c = getchar()){
		case '/':
			barra1();
			break;
		case COMILLAS:
			fputc(c,fp);
			cadena();
			break;
		case APOSTROFE:
			fputc(c,fp);
			caracter();
			break;
		case EOF:
			return;
		default:
			fputc(c,fp);
			codigoSinComentarios();
			break;
	}
	return;
}

void barra1(){
	fputs("\tbarrra1\n",fpe);
	c = getchar();
	switch(c){
		case '/':
			barra2();
			break;
		case '*':
			asterisco();
			break;
		case EOF:
			break;
		default:
			fputc(c,fp);
			codigoSinComentarios();
			break;
	}
	return;
}

void barra2(){
	fputs("\t\tbarra2\n",fpe);
	c = getchar();
	switch(c){
		case LF:
			fputc(c,fp);
			codigoSinComentarios();
			break;
		case EOF:
			return;
		default:
			barra2();
			break;
	}
	return;
}

void asterisco(){
	fputs("\t\t\tasterisco\n",fpe);
	c = getchar();
	switch(c){
		case '*':
			asteriscosPalabras();
			break;
		case EOF:
			break;
		default:
			asterisco();
			break;
	}
	return;
}

void asteriscosPalabras(){
	fputs("\t\t\t\tasteriscosPalabras\n",fpe);
	cAnterior = c;
	c = getchar();
	switch(c){
		case '/':
			if(cAnterior == '*'){
				putchar(' ');
				codigoSinComentarios();
				break;
			}
			else{
				asteriscosPalabras();
				break;
			}
		case EOF:
			break;
		default:
			asteriscosPalabras();
			break;
	}
	return;
}

void caracter(){
	fputs("\t\t\t\t\tcaracter\n",fpe);
	c = getchar();
	switch(c){
		case CONTRABARRA:
			fputc(c,fp);
			escapeCaracter();
			break;
		case APOSTROFE:
			fputc(c,fp);
			codigoSinComentarios();
			break;
		case EOF:
			break;
		default:
			fputc(c,fp);
			caracter();
			break;
	}
	return;
}

void escapeCaracter(){
	fputs("\t\t\t\t\t\tescapeCaracter\n",fpe);
	c= getchar();
	switch(c){
		case EOF:
			break;
		default: 
			fputc(c,fp);
			caracter();
			break;
	}
	return;
}

void cadena(){
	fputs("\t\t\t\t\t\t\tcadena\n",fpe);
	c = getchar();
	switch(c){
		case CONTRABARRA:
			fputc(c,fp);
			escapeCadena();
			break;
		case COMILLAS:
			fputc(c,fp);
			codigoSinComentarios();
			break;
		case EOF:
			break;
		default:
			fputc(c,fp);
			cadena();
			break;
	}
	return;
}
void escapeCadena(){
	fputs("\t\t\t\t\t\t\t\tescapeCadena\n",fpe);
	c= getchar();
	switch(c){
		case EOF:
			break;
		default: 
			fputc(c,fp);
			cadena();
			break;
	}
	return;
}

int main(){

	fp = fopen("resultadoa.txt","w");
	fpe = fopen("ejecucion.txt","w");
	codigoSinComentarios();
	return 0;
}