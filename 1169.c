#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
    int i, j, contador = 0, diamante;
    char areia[1000];
    scanf("%d", &contador);
    while (contador--){
        scanf("%s", areia);
        diamante = 0;
        for (i = 0; i < strlen(areia); i++){
            if (areia[i] == '\0')
                break;
            if (areia[i] == '<'){
                for (j = i; j< strlen(areia); j++){
                    if (areia[j] == '>'){
                        diamante++;
                        areia[j] = '0';
                        break;
                    }
                }
            }
        }
        printf("%d\n", diamante);
        
    }
    return 0;
}