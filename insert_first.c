
#include"main.h"

// Insertion List 
int insert_first(create **head, char *argv[], int i)
{
        create *new = malloc(sizeof(create));

        if(new == NULL)
            return FAILURE;
        
        strcpy(new->fname,argv[i]);
        new->link = NULL;

        
        if(*head == NULL)
        {
            *head = new;
            return SUCCESS;
        }
        else
        {
            create *temp = *head;
            *head = new;
            new->link = temp;
        }
        return SUCCESS;
}

