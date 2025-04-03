#include <stdio.h>
#include <string.h>

#define MAX_TAM 100 // Defini��o do tamanho m�ximo da string

void criptografar(char *texto) {
    int i = 0;
    while (texto[i] != ';' && texto[i] != '\0') {
        texto[i] = (5 * texto[i] + 100) % 256;//A regra de criptografia deve substituir o c�digo ASCII de cada caractere que comp�e a mensagem por: (5*c�digo_ASCII + 100) % 256 
        i++;
    }
}

int main() {
    	char texto[MAX_TAM];
    	char continuar;

    do 	{
        printf("\nEntre com o texto a ser codificado (finalize com ';'): ");
        scanf(" %99[^\n]", texto); // Le a string ate bater a quebra de linha (enter)

        // Verifica se a entrada termina com ponto e virgula
        if (strchr(texto, ';') == NULL) {
            printf("Erro: O texto precisa terminar com ';'.\n");
            	while (getchar() != '\n'); // Limpa o buffer do teclado (boas praticas padr�o Rocky Balboa)
            		continue;}

        printf("\nTexto original: %s\n", texto); //Retorna o texto original

        // Chama fun��o que codifica o texto
        criptografar(texto);
        
        printf("Texto codificado: %s\n", texto);

        // Pergunta ao usuario se deseja continuar
        printf("Continua? (S/N): ");
        scanf(" %c", &continuar);
        	while (getchar() != '\n'); // Limpador de buffer novamente
    	} 
	while (continuar == 'S' || continuar == 's'); //Aguarda 

    return 0;
}

