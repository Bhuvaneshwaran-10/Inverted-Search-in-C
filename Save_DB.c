
#include "main.h"

// save database
int save_database(hash_t *HT_arr)
{
    if(hash_empty(HT_arr) == EMPTY)
    {
        return EMPTY;
    }
    char file_name[50];
    printf("Enter the File Name : ");
    scanf("%s", file_name);

    if(validate_file(file_name) == FAILURE)
    {
        printf("\nINFO : Enter Valid File Name\n");
        return FAILURE;
    }
    
    FILE *fptr = fopen(file_name,"w");
    if(fptr == NULL)
    {
        printf("\nINFO : Unable to open File : %s\n",file_name);
        return FAILURE;
    }

    MAIN_NODE *main_temp; 

    for(int i = 0; i < 28; i++)
    {  
        main_temp = HT_arr[i].main_link;

            while(main_temp != NULL)
            {
                fprintf(fptr,"#%d;%s;%d;",i,main_temp->word,main_temp->file_count);

                SUB_NODE *sub_temp = main_temp->sub_link;
                while(sub_temp != NULL)
                {
                    fprintf(fptr,"%s;%d;",sub_temp->file_name,sub_temp->word_count);
                    sub_temp = sub_temp->sub_link;
                }
                fprintf(fptr,"#\n");
                main_temp = main_temp->main_link;
            }
    }
        fclose(fptr);

    for (int i = 0; i < 100; i++)
    {
        printf("\rSaving file [%s] ............................[%d%%]",file_name, i + 1);
        fflush(stdout);
        usleep(10000);
    }
    printf("\n");

    printf("\nINFO : Database saved successfully\n");
    return SUCCESS;

}
