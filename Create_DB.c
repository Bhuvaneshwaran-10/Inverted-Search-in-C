

#include "main.h"

// create database
int create_database(hash_t *HT_arr, create **head)
{
    create *temp = *head;
    while(temp != NULL)
    {
        FILE *fptr = fopen(temp->fname,"r");
        if(fptr == NULL)
        {
            temp = temp -> link;
            continue;
        }
        char word[50];
        while(fscanf(fptr,"%s",word) != EOF)
        {

            to_lower(word);

           int index = find_index(word);

                if(index < 0 || index >= 28)
                    continue;

                MAIN_NODE *main_temp = HT_arr[index].main_link;
                while(main_temp != NULL)
                {
                    if(strcmp(main_temp->word, word) == 0)
                    {
                        SUB_NODE *sub_temp = main_temp->sub_link;
                        int file_found = 0;

                        while(sub_temp != NULL)
                        {
                            if(strcmp(sub_temp->file_name, temp->fname) == 0)
                            {
                                sub_temp->word_count++;
                                file_found = 1;
                                break;
                            }
                            sub_temp = sub_temp->sub_link;
                        }
                        if(file_found == 0)
                        {
                            SUB_NODE *sub = create_sub_node(temp->fname);
                            sub->sub_link = main_temp->sub_link;
                            main_temp->sub_link = sub;
                            main_temp->file_count++;
                        }
                        break;
                    }
                    main_temp = main_temp->main_link;
                }
            if(main_temp == NULL)
            {
                MAIN_NODE *main = create_main_node(word);
                SUB_NODE *sub = create_sub_node(temp->fname);
                
                if(main == NULL || sub == NULL)
                    return FAILURE;

                main->sub_link = sub;
                main->main_link = HT_arr[index].main_link;
                HT_arr[index].main_link = main;
            }
        }
        fclose(fptr);
        temp = temp->link;
    }
    return SUCCESS;
}

// Main node function()
MAIN_NODE *create_main_node(char *word)
{
    MAIN_NODE *new = malloc(sizeof(MAIN_NODE));   
    if(new == NULL)
        return NULL;

    strcpy(new->word,word);
    new->file_count = 1;
    new->len = strlen(word);

    new->sub_link = NULL;
    new->main_link = NULL;

    return new;
}

// Sub node function()
SUB_NODE *create_sub_node(char *fname)
{
    SUB_NODE *new = malloc(sizeof(SUB_NODE));
    if(new == NULL)
        return NULL;

    new->word_count = 1;
    strcpy(new->file_name, fname);

    new->sub_link = NULL;

    return new;
}
