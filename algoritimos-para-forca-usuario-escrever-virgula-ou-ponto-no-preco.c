/* 
 *  mapa do codigo: 
 *
 *	char * replace(char const * const,char const * const,char const * const)
 * 	int    match_patterns(char *,char *) 
 * 	double pedirPreco(void)
 * 	int    main(void)
*/

/*
 *  		
 *  abaixo é o codigo de replace do stackoverflow
 *
 *  https://stackoverflow.com/questions/779875/what-function-is-to-replace-a-substring-from-a-string-in-c
 *  
*/

#include <string.h>
#include <stdlib.h>


char * replace(
    char const * const original, 
    char const * const pattern, 
    char const * const replacement
) {
  size_t const replen = strlen(replacement);
  size_t const patlen = strlen(pattern);
  size_t const orilen = strlen(original);

  size_t patcnt = 0;
  const char * oriptr;
  const char * patloc;

  // find how many times the pattern occurs in the original string
  for (oriptr = original; patloc = strstr(oriptr, pattern); oriptr = patloc + patlen)
  {
    patcnt++;
  }

  {
    // allocate memory for the new string
    size_t const retlen = orilen + patcnt * (replen - patlen);
    char * const returned = (char *) malloc( sizeof(char) * (retlen + 1) );

    if (returned != NULL)
    {
      // copy the original string, 
      // replacing all the instances of the pattern
      char * retptr = returned;
      for (oriptr = original; patloc = strstr(oriptr, pattern); oriptr = patloc + patlen)
      {
        size_t const skplen = patloc - oriptr;
        // copy the section until the occurence of the pattern
        strncpy(retptr, oriptr, skplen);
        retptr += skplen;
        // copy the replacement 
        strncpy(retptr, replacement, replen);
        retptr += replen;
      }
      // copy the rest of the string.
      strcpy(retptr, oriptr);
    }
    return returned;
  }
}


/* 
 *  abaixo é o codigo de de regex do stackoverflow
 *
 *  https://stackoverflow.com/questions/14237772/suggest-c-regex-scanner-stream-reader
 *
*/

#include<regex.h>
#include<string.h>



int match_patterns(char *pch,char *pattern)
{
    regex_t             *regex;
    regmatch_t          *result;
    int                 err_no = 0;
    int                 start = 0;

    regex = (regex_t *) calloc(1,sizeof(regex_t));
    if((err_no = regcomp(regex, pattern, REG_EXTENDED)) != 0)
    {
        size_t          length;
        char            *buffer;
        length = regerror (err_no, regex, NULL, 0);
        buffer = malloc(length);
        regerror (err_no, regex, buffer, length);
        free(buffer);
        regfree(regex);
        return -1; //error
    }
    result = (regmatch_t *) calloc(1,sizeof(regmatch_t));
    if(result == NULL)
    {
        return -1; //error
    }
    while(regexec(regex, pch+start, 1, result, 0) == 0)
    {
        start +=result->rm_eo;
    }
    regfree(regex);
    free(regex);
    if((result->rm_so == 0)&&(result->rm_eo == strlen(pch)))
    {
        return 1; //OK
    }
    return 0; //error
}


/*
 * abaixo é o codigo para aceitar somente numeros que tenha o padrão de preço, podendo usar virgula também
 *
*/


double pedirPreco()
{
    // criar ponteiro não nulo para usar no input
    char *input = calloc(20,sizeof(char));
    
    // criar a expressão regular (regex)
    char *regex = "(\\+|-)?([[:digit:]]+)?(\\.|,)[[:digit:]][[:digit:]]";
    
    // entrar no loop
    do{
        
        // mensagem para pedir preço
        printf("digite um preço\n");
        
        // capturando o que o usuaro digitou
        scanf("%s",input);
        
        // fazendo teste se bate com minha regex
        if (match_patterns(input, regex)){
            
            // tudo certo só agradecer e ir embora
            printf("obrigado!\n");
            
            // sai desse loop
            break;
        }
        
        // deu rui a regex não bate com o que o usuario digitou
               
        // mostrar o ero pra o usuario
        printf("%s não é um preço valido!\n\n",input);

    // voltar lá pra cima no loop infinito
    }while(1);
    
    // passar a virgula para ponto 
    input = replace(input,",",".");
    
    // esse ponteiro é só proque a função abaixo vai precisar dele 
    char *finaldaconversao;
    
    // convertendo string para double
    double preco = strtod(input, &finaldaconversao) ;
    
    // liberar memoria alocada nessa função
    free(input);
    
    // pra mim era pra desalocar essa também mas dar erro quando faço isso
    //free(regex);
    
    // entregar o resultado
    return preco;
}

/*
 * 
 * função  principal
 * 
*/
int main(){
    printf("Quanto de troco?\n");
    
    // double é melhor do que float para preços 
    double troco = pedirPreco();
    
    printf("o valor do troco é: %g\n", troco);
    return 0;   
}
