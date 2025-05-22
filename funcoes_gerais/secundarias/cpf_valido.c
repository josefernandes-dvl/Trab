#include <stdio.h>
#include <string.h>
#include <ctype.h> // para isdigit
#include "prototipos.h"

int cpf_valido(const char *cpf) // const para garantir q o cpf seja fixo e não alterado.
{
    if (strlen(cpf) != 11)
    {
        ir_para(25, 15);
        printf("\033[1;31mQuantidade de digitos invalida.\033[0m");
        return 0; // tem que ter 11 caracteres
    }
    for (int i = 0; i < 11; i++)
    {
        /*O isdigit verifica caractere por caractere de uma string
        (ou de qualquer entrada) e responde se aquele caractere individual é um número entre '0' e '9'.
        Se for diferentre retorna 0, se for igual retorna 1 "normalmente", pode retornar outra coisa.*/
        if (isdigit(cpf[i]) == 0)
        {
            ir_para(25, 15);
            limpar_linha();
            ir_para(25, 15);
            printf("\033[1;31mDigitos invalidos!\033[0m");
            return 0;
        }
        
    }
    return 1;
}