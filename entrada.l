
%{
#include <stdio.h>

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

%}

DIGITO [0-9]
NUMERO {DIGITO}+

%%

{NUMERO}           { return NUM; }

"+"                { return SOM; }
"-"                { return SUB; }
"*"                { return MUL; }
"/"                { return DIV; }
"("                { return APR; }
")"                { return FPR; }

\n                 { return EOL;  }
\t                 { }
[ ]+               { }

<<EOF>>            { return FIM; }

.                  {
                     printf("ERRO LÉXICO: \"%s\"\n", yytext);
                     return ERR;
                   }

%%

