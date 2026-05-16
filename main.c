

//                                                  INVERTED SEARCH


// Name : Bhuvaneshwaran P
//   ID : 25036B_092
  
// Project Description:
//                     Developed an inverted search system using data structures to enable fast and efficient text retrieval 
//                     from multiple files. The project implements an inverted index mechanism where each unique word is mapped 
//                     to a list of files containing that word. Input files are processed through tokenization, and words are 
//                     stored using efficient structures such as hash tables and linked lists. The system supports quick search 
//                     queries by directly retrieving file references without scanning entire documents. This approach significantly 
//                     improves search performance and demonstrates strong understanding of data structures, file handling, and 
//                     algorithm optimization.




#include "main.h"

int main(int argc, char *argv[])
{
    printf("\n---------------------------------------\n");
    printf("        INVERTED SEARCH         ");
    printf("\n---------------------------------------\n");

    create *head = NULL;
    if(validate_args(argc, argv, &head) == FAILURE)
    {
        printf("\nINFO  : Validation is failed..\n");
        return FAILURE;
    }
    
    print_list(&head);
  
    int option;

    hash_t HT_arr[28];

    for(int i = 0; i < 28; i++)
    {
        HT_arr[i].index = i;
        HT_arr[i].main_link = NULL;
    }
  
    while(1)
    {
        printf("\n1. Create Database\n2. Search Database\n3. Save Database\n4. Update Database\n5. Dispaly Database\n6. Exit\n");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
            {
                // create Database
                if(create_database(HT_arr, &head) == FAILURE)
                {
                    printf("\nINFO : Create Database is Failed\n");
                }
                else
                {
                    printf("\nINFO : Create Database is Successful\n");
                }
            }
            break;
            case 2:
            {
                // search database
                if(search_database(HT_arr) == DATA_NOT_FOUND)
                {
                    printf("\nINFO : Data is not present in the Database\n");
                }
            }
            break;
            case 3:
            {
                // Save database
                int result = save_database(HT_arr);
                if(result == FAILURE)
                {
                    printf("\nINFO : Saving Database is Failed\n");
                }
                else if(result == EMPTY)
                {
                    printf("\nINFO : Hash table is empty, can't save Database\n");
                }
            }
            break;
            case 4:
            {
                // Update database
                if(update_database(HT_arr) == FAILURE)
                {
                    printf("\nINFO : Updation of Database is Failed\n");
                }
            }
            break;
            case 5:
                // Display database
                display_database(HT_arr);
            break;
            case 6:
                return SUCCESS;
            default:
                printf("Enter Valid Choice!!\n");
        }
    }
}
