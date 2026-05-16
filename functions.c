
#include"main.h"

// Hash Table Empty 
int hash_empty(hash_t *HT_arr)
{
    int empty = 0;
    for(int i = 0; i < 28; i++)
    {
        if(HT_arr[i].main_link != NULL)
        {
            empty = 1;
            break;
        }
    }
    if(empty == 0)
    {
        return EMPTY;
    }
    return SUCCESS;
}

// Find index
int find_index(char *word)
{
    int alpha = 0, digit = 0, special = 0;
    for(int i = 0; word[i] != '\0'; i++)
    {
        if(isalpha(word[i]))
            alpha = 1;
        else if(isdigit(word[i]))
            digit = 1;
        else 
            special = 1;
    }

    if(alpha && !(digit) && !(special))
        return tolower(word[0]) - 'a';
    else if(!(alpha) && (digit) && !(special))
        return 26;
    else
        return 27;
}

// Upper to Lower
void to_lower(char *word)
{
    for (int i = 0; word[i] != '\0'; i++)
    {
        word[i] = tolower(word[i]);
    }
}

// Validation File
int validate_file(char *file_name)
{
    int len = strlen(file_name);

    if(len <= 4 || strcmp(&file_name[len-4], ".txt") != 0)
    {
        printf("\nINFO : Can't open File without .txt Extension : %s\n",file_name);
        return FAILURE;
    }

    return SUCCESS;
}

// Check Duplicate files are present
int check_duplicate_file(create *head, char *file_name)
{
    create *temp = head;

    while(temp != NULL)
    {
        if(strcmp(temp->fname,file_name) == 0)
        {
            return 1;
        }
        temp = temp->link;
    }
    return 0;
}


