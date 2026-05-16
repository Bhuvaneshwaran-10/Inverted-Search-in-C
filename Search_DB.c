
#include "main.h"

// search database
int search_database(hash_t *HT_arr)
{
    if(hash_empty(HT_arr) == EMPTY)
    {
        printf("\nINFO : Database is Empty\n");
        return DATA_NOT_FOUND;
    }
    char Sword[50];
    printf("Enter the word to search: ");
    scanf("%s", Sword);

    to_lower(Sword);

    int index = find_index(Sword);

    if(index < 0 || index >= 28)
        return FAILURE;

    MAIN_NODE *main_temp = HT_arr[index].main_link;

    if(main_temp == NULL)
        return DATA_NOT_FOUND;
    

    while(main_temp != NULL)
    {
        
        if(strcmp(main_temp->word,Sword) == 0)
        {
            printf("\n%-12s %-15s %-15s %-10s\n","Word","File_Count","File_Name","Word_Count");
            printf("------------------------------------------------------\n");
            SUB_NODE *sub_temp = main_temp->sub_link;

            if(sub_temp == NULL)
                return DATA_NOT_FOUND;

            if(sub_temp != NULL)
            {
            printf("%-12s %-15d %-15s %-10d\n", Sword,main_temp->file_count,sub_temp->file_name,sub_temp->word_count);
            sub_temp = sub_temp->sub_link;
            }

            while(sub_temp != NULL)
            {
                printf("%-12s %-15s %-15s %-10d\n","","",sub_temp->file_name, sub_temp->word_count);
                sub_temp = sub_temp->sub_link;
            }
            return SUCCESS;
        }
        main_temp = main_temp->main_link;
    }
    return DATA_NOT_FOUND;
}