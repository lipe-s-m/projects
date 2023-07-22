strcat(page, txt);
            entrada = fopen(page, "r");
            if(entrada == NULL)
            {
                printf("Caminho Inválido");
                return final(page, jogador1);
            }
            while(!feof(entrada))
            {
                    fscanf(entrada, "%c", &c);
                    if(c != '$')
                        printf("%c", c);        
            }