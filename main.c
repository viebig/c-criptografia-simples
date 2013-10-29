#include <stdio.h>
#include <stdlib.h>
 
int main()
{
 
    FILE *origem, *destino; // Declarando ponteiros para abertura de arquivos
    int opcao; // Inteiro que designa a opcao de criptografar ou descriptografar
 
    puts("Programa de criptografia");
    puts("Digite 1 ou 2 conforme abaixo:");
    puts("  1 - Criptografar");
    puts("  2 - Descriptografar");
 
    scanf("%d", &opcao);
 
    if (opcao == 1) // Se for para criptografia
    {
 
        origem = fopen("origem.txt", "r"); // Tenta abrir origem.txt para leitura
        destino = fopen("destino.txt", "w"); // Tenta abrir o arquivo destino.txt para escrita, e o cria se ele nao existir
 
        if(origem != NULL && destino != NULL) // Se o arquivo de origem existe e se o de destino existe ou conseguiu ser criado
        {
            char c; // Define a variavel c, para ler caractere por caractere do arquivo
            int contador = 0; // Define contador que indicara a posicao do arquivo
            int i = 0; // Variavel inteira que utilizaremos para mostrar a representacao ASCII do caractere
 
            // Faz enquanto o fgetc nao retornar o fim do arquivo
            while(( c = fgetc(origem)) != EOF)
            {
                contador++; // Mesma coisa que contador = contador + 1;
                printf("%c", c); // Mostra o caractere na tela
 
                i = c; // i sera o codigo numerico do caractere c em ASCII;
                i = i * contador; // Multiplicando i pela posicao do caractere no arquivo;
 
                fprintf(destino,"%i ", i); // Escreve a representacao numerica de i e um espaco a frente no arquivo de destino
            }
 
            fclose(origem); // Fecha o arquivo de origem
            fclose(destino); // Fecha o arquivo de destino
 
        }
        else
        {
            puts("Erro de leitura/escrita nos arquivos...");
        }
 
    }
    else if(opcao == 2) // Se for descriptografia
    {
        origem = fopen("destino.txt", "r"); // Tenta abrir destino.txt para leitura
        destino = fopen("descriptografado.txt", "w"); // Tenta abrir o arquivo descriptografado.txt para escrita, e o cria se ele nao existir
 
        if(origem != NULL && destino != NULL) // Se o arquivo de origem existe e se o de destino existe ou conseguiu ser criado
        {
            int contador = 0; // Define contador que indicara a posicao do arquivo
            char c[100]; // Utilizaremos para armazenar cada codigo que leremos
            int i = 0; // Variavel inteira que utilizaremos para representacao numerica lida do codigo lido no arquivo
 
            while(fscanf(origem, "%s", c) != EOF)  // Faz enquanto o fscanf nao retornar o fim do arquivo
            {
                contador++; // Mesma coisa que contador = contador + 1;
 
                i = atoi(c); // Converte um char* para inteiro e atribui a i
                i /= contador; // Mesma coisa que i = i / contador;
 
                printf("%c", i); // Mostra o caractere na tela
 
                fprintf(destino,"%c", i); // Escreve a representacao numerica de i no arquivo de destino
            }
 
            fclose(origem); // Fecha o arquivo de origem
            fclose(destino); // Fecha o arquivo de destino
        }
    }
    else // Se a opcao for invalida
    {
        puts("Opcao invalida...");
    }
 
 
    puts("\n"); // Pula duas linhas
    system("pause"); // Pausa o sistema em ambiente windows
    return 0;
}