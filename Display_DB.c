
#include "main.h"

// display database
void display_database(hash_t *HT_arr)
{
    if(hash_empty(HT_arr) == EMPTY)
    {
        printf("\nINFO : Database is Empty\n");
        return;
    }
    printf("--------------------------------------------------------------------\n");
    printf("%-10s %-12s %-15s %-15s %-10s\n","Index","Word","File_Count","File_Name","Word_Count");
    printf("--------------------------------------------------------------------\n");

    for(int i = 0; i < 28; i++)
    {
        if(HT_arr[i].main_link == NULL)
            continue;

            MAIN_NODE *main = HT_arr[i].main_link;
            while(main != NULL)
            {

                SUB_NODE *sub = main->sub_link;

                if(sub != NULL)
                {
                    printf("%-10d %-12s %-15d %-15s %-10d\n",i,main->word,main->file_count,sub->file_name,sub->word_count);
                    sub = sub->sub_link;
                }
                while(sub != NULL)
                {
                    printf("%-10s %-12s %-15s %-15s %-10d\n", " ", " ", " ",sub->file_name,sub->word_count);
                    sub = sub->sub_link;  
                }
                main = main->main_link;
            }
    }
    printf("\nDatabase Displayed Successfully..\n");
}