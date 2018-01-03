/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// prototype
int hash(const char* word);


//define the node structure
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

//define size of hashtable
#define HASHTABLE 27

//initalize hashtable
node *hashtable[HASHTABLE];

//create global value counter
int counter = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    
    node *cursor = hashtable[hash(word)];
    
    while (cursor != NULL)
    {
        //compare the words
        if (strcasecmp(cursor->word, word) == 0)
            return true;
        
        cursor = cursor->next;
    }
    
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    //open the file to read
    FILE *doc = fopen(dictionary, "r");
    
    //preform check to see if dictionary is open
    if (doc == NULL)
        return false;
        
    //create buffer to store new word    
    char buffer[LENGTH + 1];
        
    //iterate over the dictionary
    while (fscanf(doc, "%s", buffer) != EOF)
    {
        //allocate space for the new node and check to see if succesful
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        
        //copy word into node pointer
        strcpy(new_node->word, buffer);
        
        //get hashvalue of the word
        int hash_value = hash(buffer);
        
        //new node is the head
        if (hashtable[hash_value] == NULL)
        {
            hashtable[hash_value] = new_node;
            new_node->next = NULL;
        }
        
        //new node is not the head
        else
        {
            new_node->next = hashtable[hash_value];
            hashtable[hash_value] = new_node;
        }
        
        //count the words
        counter ++;
    }
    
    //close dictionary
    fclose(doc);
    
    return true;
}

/**
 *  Hash function thanks to CS50
 */
int hash(const char* word)
{
    // initialize index to 0
    int index = 0;

    // sum ascii values
    for (int i = 0; word[i] != '\0'; i++)
        // search for lower cases words
        index += tolower(word[i]);

    // mod by size to stay w/in bound of table
    return index % HASHTABLE;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return counter;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    //run through the hashtable
    for(int i = 0; i < HASHTABLE; i++)
    {
        // create cursor pointer at the head of the hashvalue
        node *cursor = hashtable[i];
        
        //free the linked list at i
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
