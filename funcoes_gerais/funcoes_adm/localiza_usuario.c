#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

void localiza_usuario(Cadastro *dados)
{
    dados->menu_principal = '1'; // Diz q o arquivo binario será o do usuário.

    int nome_existe;
    do // Repete ate o nome do cadastro ser igual ao nome a ser localizado
    {
        char usuario_procurado[50];

        limpar();
        bordas();
        ir_para(25, 2);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        ir_para(25, 3);
        printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
        ir_para(25, 4);
        printf("%c        Localizar Usuario        %c", 179, 179);
        ir_para(25, 5);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        ir_para(24, 9);

        ir_para(25, 10);
        printf("Nome do Usuario: ");
        fgets(usuario_procurado, 50, stdin);
        usuario_procurado[strcspn(usuario_procurado, "\n")] = '\0';

        nome_existe = verificar_nome(dados, usuario_procurado); // Caso o nome exista no arquivo, retorna 1. Senão retorna 0.

        if (nome_existe == 1)
        {
            ir_para(25, 9);
            printf("Usuario : %s", dados->nome);
            ir_para(25, 10);
            limpar_linha();
            ir_para(25, 10);
            printf("CPF: %s", dados->cpf);
            ir_para(25, 11);
            printf("Email: %s", dados->email);
        }
        else
        {
            // Se o usuario não for encontrado, oferece opcao de tentar de novo ou sair
            char deseja_repetir_nome;
            do
            {
                ir_para(35, 12);
                printf("\033[1;31mUsuario nao encontrado\033[0m");
                ir_para(26, 13);
                printf("Deseja repetir o nome do Usuario?");
                ir_para(30, 14);
                printf("[1] SIM  ou  [2] NAO  : ");
                scanf("%c", &deseja_repetir_nome);
                apaga_buffer();
                switch (deseja_repetir_nome)
                {
                case '1':
                    limpar();
                    break;
                case '2':
                    ir_para(24, 16);
                    printf("\033[1;31mSaindo do programa...\033[0m");
                    exit(0);
                default:
                    break;
                }
            } while (deseja_repetir_nome != '1' && deseja_repetir_nome != '2');
        }

    } while (nome_existe == 0);
}