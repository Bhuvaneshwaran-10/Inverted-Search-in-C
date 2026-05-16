
#include "main.h"

// validation args
int validate_args(int argc, char *argv[], create **head)
{
    int i,flag = 0;
    for( i = 1; i < argc; i++)
    {
        int len = strlen(argv[i]);
        if(len < 5 || strcmp(&argv[i][len - 4], ".txt") != 0)
        {
            printf("\nINFO : File without extension(.txt) : %s\n", argv[i]);
            continue;
        }
        FILE *file = fopen(argv[i],"r");
        if(file == NULL)
        {
            printf("\nINFO : File does not exist : %s\n", argv[i]);
            continue;
        }

        if(check_duplicate_file(*head, argv[i]))
        {
            printf("\nINFO : Duplicate file removed : %s\n", argv[i]);
            fclose(file);
            continue;
        }
        
        fclose(file);
        insert_first(head,argv,i);
        flag++;
    }

    if(flag == 0)
        return FAILURE;
    
    return SUCCESS;
}
