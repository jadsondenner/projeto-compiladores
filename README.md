# Projeto de Compiladores — C-

Implementação acadêmica de um analisador léxico com Flex e de um analisador sintático em C, desenvolvida como parte das atividades da disciplina de Compiladores.

## Arquivos

- `entrada.l`: define as regras léxicas para reconhecer números, operadores aritméticos e parênteses.
- `parser.c`: implementa o analisador sintático de expressões aritméticas.
- `teste.txt`: contém exemplos de expressões sintaticamente válidas.
- `teste_erros.txt`: contém exemplos para testar a identificação de erros sintáticos.
- `.gitignore`: define arquivos gerados e temporários que não devem ser versionados.

## Requisitos

- GCC
- Flex
- Biblioteca `libfl`

## Compilação

Na pasta do projeto, execute:

```bash
flex entrada.l
gcc lex.yy.c parser.c -o analisador -lfl
```

## Execução

Para testar expressões válidas:

```bash
./analisador teste.txt
```

Para testar uma entrada que contém erro sintático:

```bash
./analisador teste_erros.txt
```

O analisador interrompe a execução ao encontrar um erro sintático.

Também é possível executar o programa sem informar um arquivo, utilizando a entrada padrão do terminal.

## Escopo

O projeto implementa a análise léxica e a análise sintática de expressões aritméticas conforme as regras definidas no código. Não se trata de um compilador completo da linguagem C-.
