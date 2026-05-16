#ifndef INVERTED_SEARCH
#define INVERTED_SEARCH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define SUCCESS 0
#define FAILURE -1
#define EMPTY -2
#define DATA_NOT_FOUND -3

typedef struct node
{
    char fname[50];
    struct node *link;
}create;

typedef struct HT_arr
{
    int index;
    struct main_node *main_link;
}hash_t;

typedef struct main_node
{
    char word[50];
    int file_count;
    int len;
    struct sub_node *sub_link;
    struct main_node *main_link; 
}MAIN_NODE;

typedef struct sub_node
{
    int word_count;
    char file_name[50];
    struct sub_node *sub_link;
}SUB_NODE;


int create_database(hash_t *HT_arr, create **head);
void display_database(hash_t *HT_arr);
int search_database(hash_t *HT_arr);
int save_database(hash_t *HT_arr);
int update_database(hash_t *HT_arr);
int validate_args(int argc, char *argv[], create **head);
void print_list(create **head);
int insert_first(create **head, char *argv[], int i);
int find_index(char *word);
void to_lower(char *word);
int hash_empty(hash_t *HT_arr);
int validate_file(char *file_name);
int check_duplicate_file(create *head, char *file_name);
MAIN_NODE *create_main_node(char *word);
SUB_NODE *create_sub_node(char *fname);


#endif
