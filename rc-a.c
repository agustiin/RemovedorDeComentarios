#include <stdio.h>
int c, anterior;
enum caracteres {
	APOSTROFE = 39,
	COMILLAS = 34,
	LF = 10,
	CONTRABARRA=92
};

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

	switch(c = getchar()){
		case '/':
			barra1();
			break;
		case COMILLAS:
			putchar(c);
			cadena();
			break;
		case APOSTROFE:
			putchar(c);
			caracter();
			break;
		case EOF:
			break;
		default:
			putchar(c);
			codigoSinComentarios();
			break;
	}
}

void barra1(void){
	c = getchar();
	switch(c){
		case '/':
			barra2();
			break;
		case '*':
			asterisco();
			break;
		default:
			putchar(c);
			codigoSinComentarios();
			break;
	}
	
}

void barra2(void){
	c = getchar();
	switch(c){
		case LF:
			putchar(c);
			codigoSinComentarios();
			break;
		default:
			barra2();
			break;
	}
}

void asterisco(void){
	c = getchar();
	switch(c){
		case '*':
			asteriscosPalabras();
			break;
		default:
			asterisco();
			break;
	}
}

void asteriscosPalabras(void){
	anterior = c;
	c = getchar();
	switch(c){
		case '/':
			if(anterior == '*'){
				putchar(' ');
				codigoSinComentarios();
				break;
			}
			else{
				asteriscosPalabras();
				break;
			}
		default:
			asteriscosPalabras();
			break;
	}
}
void caracter(void){
	c = getchar();
	switch(c){
		case CONTRABARRA:
			putchar(c);
			escapeCaracter();
			break;
		case APOSTROFE:
			putchar(c);
			codigoSinComentarios();
			break;
		default:
			putchar(c);
			caracter();
			break;
	}
}
void escapeCaracter(void){
	c= getchar();
	putchar(c);
	caracter();
}
void cadena(void){
	c = getchar();
	switch(c){
		case CONTRABARRA:
			putchar(c);
			escapeCadena();
			break;
		case COMILLAS:
			putchar(c);
			codigoSinComentarios();
			break;
		default:
			putchar(c);
			cadena();
			break;
	}
}
void escapeCadena(void){
	c= getchar();
	putchar(c);
	cadena();
}
int main(){
	codigoSinComentarios();
	return 0;
}