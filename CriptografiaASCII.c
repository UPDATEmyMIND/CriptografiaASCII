#include <stdio.h>
#include <string.h>

#define MAX_TAM 100 // Definição do tamanho máximo da string

void criptografar(char *texto) {
    int i = 0;
    while (texto[i] != ';' && texto[i] != '\0') {
        texto[i] = (5 * texto[i] + 100) % 256;//A regra de criptografia deve substituir o código ASCII de cada caractere que compõe a mensagem por: (5*código_ASCII + 100) % 256 
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
            	while (getchar() != '\n'); // Limpa o buffer do teclado (boas praticas padrão Rocky Balboa)
            		continue;}

        printf("\nTexto original: %s\n", texto); //Retorna o texto original

        // Chama função que codifica o texto
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

