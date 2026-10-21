
#include <stdio.h>
#include <stdlib.h>

#define NUM 300
#define SOM 302
#define SUB 303
#define MUL 304
#define DIV 305
#define APR 308
#define FPR 309
#define FIM 310
#define ERR 311
#define EOL 312

int yylex(void);
extern char *yytext;

int token;

void erro_sintatico(void)
{
    printf("Erro sintatico.\n");
    exit(1);
}

void avancar(void)
{
    token = yylex();

    if (token == ERR)
        exit(1);
}

void soma(void)
{
    if (token == SOM || token == SUB)
        avancar();
    else
        erro_sintatico();
}

void mult(void)
{
    if (token == MUL || token == DIV)
        avancar();
    else
        erro_sintatico();
}

void expressao(void);
void termo(void);
void fator(void);

void fator(void)
{
    if (token == NUM)
    {
        avancar();
    }
    else if (token == APR)
    {
        avancar();
        expressao();

        if (token == FPR)
            avancar();
        else
            erro_sintatico();
    }
    else
    {
        erro_sintatico();
    }
}

void termo(void)
{
    fator();

    while (token == MUL || token == DIV)
    {
        mult();
        fator();
    }
}

void expressao(void)
{
    termo();

    while (token == SOM || token == SUB)
    {
        soma();
        termo();
    }
}


int main(int argc, char *argv[])
{
    extern FILE *yyin;
    int encontrou_expressao = 0;

    if (argc == 2)
    {
        yyin = fopen(argv[1], "r");

        if (yyin == NULL)
        {
            perror("Erro ao abrir arquivo");
            return 1;
        }
    }

    avancar();

    while (token != FIM)
    {
        if (token == EOL)
        {
            avancar();
            continue;
        }

        expressao();
        encontrou_expressao = 1;

        if (token == EOL)
        {
            printf("Expressao sintaticamente correta.\n");
            avancar();
        }
        else if (token != FIM)
        {
            erro_sintatico();
        }
    }

    if (!encontrou_expressao)
    {
        printf("Nenhuma expressao encontrada.\n");
    }

    return 0;
}

