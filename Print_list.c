
#include"main.h"

// print list
void print_list(create **head)
{
    if(*head == NULL)
    {
        printf("INFO : List is Empty\n");
        return;
    }
    
    create *temp = *head;

    while(temp != NULL)
    {
        printf("%s -> ", temp->fname);
        temp = temp->link;
    }
    printf("NULL\n");
}
