#include <stdio.h>
int c, anterior;
enum caracteres {
	apostrofe = 39,
	comillas = 34,
	LF = 10,
	contraBarra=92
};

int main(){
	
	goto codigoSinComentarios;
	
	codigoSinComentarios: {

		switch(c = getchar()){
			case '/':
				goto barra1;
			case comillas:
				putchar(c);
				goto cadena;
			case apostrofe:
				putchar(c);
				goto caracter;
			case EOF:
				return 0;
			default:
				putchar(c);
				goto codigoSinComentarios;
		}
	}

	barra1: {
		c = getchar();
		switch(c){
			case '/':
				goto barra2;
			case '*':
				goto asterisco;
			default:
				putchar(c);
				goto codigoSinComentarios;
		}
		
	}

	barra2: {
		c = getchar();
		switch(c){
			case LF:
				putchar(c);
				goto codigoSinComentarios;
			default:
				goto barra2;
		}
	}

	asterisco: {
		c = getchar();
		switch(c){
			case '*':
				goto asteriscosPalabras;
			default:
				goto asterisco;
		}
	}

	asteriscosPalabras: {
		anterior = c;
		c = getchar();
		switch(c){
			case '/':
				if(anterior == '*'){
					putchar(' ');
					goto codigoSinComentarios;
				}
				else{
					goto asteriscosPalabras;
				}
			default:
				goto asteriscosPalabras;
		}
	}
	caracter: {
		c = getchar();
		switch(c){
			case contraBarra:
				putchar(c);
				goto escapeCaracter;
			case apostrofe:
				putchar(c);
				goto codigoSinComentarios;
			default:
				putchar(c);
				goto caracter;
		}
	}
	escapeCaracter: {
		c= getchar();
		putchar(c);
		goto caracter;
	}
	cadena: {
		c = getchar();
		switch(c){
			case contraBarra:
				putchar(c);
				goto escapeCadena;
			case comillas:
				putchar(c);
				goto codigoSinComentarios;
			default:
				putchar(c);
				goto cadena;
		}
	}
	escapeCadena: {
		c= getchar();
		putchar(c);
		goto cadena;
	}

	return 0;
	
}