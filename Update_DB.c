
#include"main.h"

// update database
int update_database(hash_t *HT_arr)
{
    if(hash_empty(HT_arr) != EMPTY)
    {   
    printf("\nINFO : Database already exists, updating may duplicate data\n");
    return FAILURE;
    }

    char file_name[50];
    printf("Enter the File Name : ");
    scanf("%s", file_name);

    if(validate_file(file_name) == FAILURE)
        {
            printf("\nINFO : Enter Valid File Name\n");
            return FAILURE;
        }
    
    FILE *fptr = fopen(file_name,"r");
    if(fptr == NULL)
    {
        printf("\nINFO : File does not Exist : %s\n",file_name);
        return FAILURE;
    }

    char word[50],fname[50];
    int f_count,w_count,index;

    while(fscanf(fptr," #%d;%[^;];%d;", &index,word,&f_count) == 3)
    {
        to_lower(word);

        MAIN_NODE *main_node = create_main_node(word);

        if(main_node == NULL)
            return FAILURE;

        main_node->file_count = f_count;

        SUB_NODE *last = NULL;

        for(int i = 0; i < f_count; i++)
        {
            if(fscanf(fptr,"%[^;];%d;", fname, &w_count) != 2)
            {
                printf("\nINFO : Corrupted file format\n");
                fclose(fptr);
                return FAILURE;
            }

            SUB_NODE *sub_node = create_sub_node(fname);

            if(sub_node == NULL)
            {
                free(main_node);
                return FAILURE;
            }

            sub_node->word_count = w_count;

            if(main_node->sub_link == NULL)
            {
                main_node->sub_link = sub_node;
            }
            else
            {
             last->sub_link = sub_node;   
            }
            last = sub_node;
        }

        fscanf(fptr,"#");

         if(index < 0 || index >= 28)
        {
            printf("INFO : Invalid index %d skipped\n", index);
            continue;
        }

        if(HT_arr[index].main_link == NULL)
        {
            HT_arr[index].main_link = main_node;
        }
        else
        {
            MAIN_NODE *temp = HT_arr[index].main_link;
            while(temp->main_link != NULL)
            {
                temp = temp->main_link;
            }
            temp->main_link = main_node;
        }
    }
    fclose(fptr);
    printf("\nINFO : Update database successful..\n");
    return SUCCESS;
}