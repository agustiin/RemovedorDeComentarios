#include <stdio.h>
int c, cAnterior;
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
			return;
		default:
			putchar(c);
			codigoSinComentarios();
			break;
	}
	return;
}

void barra1(){
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
			putchar(c);
			codigoSinComentarios();
			break;
	}
	return;
}

void barra2(){
	c = getchar();
	switch(c){
		case LF:
			putchar(c);
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
		case EOF:
			break;
		default:
			putchar(c);
			caracter();
			break;
	}
	return;
}

void escapeCaracter(){
	c= getchar();
	switch(c){
		case EOF:
			break;
		default: 
			putchar(c);
			caracter();
			break;
	}
	return;
}

void cadena(){
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
		case EOF:
			break;
		default:
			putchar(c);
			cadena();
			break;
	}
	return;
}
void escapeCadena(){
	c= getchar();
	switch(c){
		case EOF:
			break;
		default: 
			putchar(c);
			cadena();
			break;
	}
	return;
}

int main(){
	codigoSinComentarios();
	return 0;
}