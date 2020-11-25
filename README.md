Projeto didatíco

Como força o usuário digitar um ponto ou uma virgula em c

Usando uma expressão regular (regex) eu posso escolher uma string com o formato exato que eu quero

Expressão Regular para preços:

"(\\+|-)?([[:digit:]]+)?(\\.|,)[[:digit:]][[:digit:]]"

Resultado da regex para :

1234567.89
234567.89
34567.89
4567.89
567.89
67.89
7.89
.89

A regex configurada para aceitar virgulas no lugar de ponto também:


1234567,89
234567,89
34567,89
4567,89
567,89
67,89
7,89
,89

Regex com dois dígitos depois da virgula obrigatório

Em c eu não consegui usar a ancora antes da regex para selecionar a string mas acabei encontrando um algoritmo no stackoverflow que me permitia produzir o mesmo efeito

Então a string só é aceita se tiver apenas números e uma virgula ou ponto, nada mais passa

No código em c a string é digitada pelo usuário e se aceita pela regex a string é convertida para double, para usar como preço dentro da aplicação

Antes de fazer em c tinha feito em c++ com um código bem menor usando as bibliotecas já prontas da linguagem 

se eu subir o código em c++ vou deixar os links aqui pra quem quiser conferir também 
