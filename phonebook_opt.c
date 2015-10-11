#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include "phonebook_opt.h"

entry *hash_tbl[MAX_DICT];


uint32_t hash(char *str){
	// djb2
	uint32_t hash = 5381;
	int c;
	while((c= *str++)!=0){
			hash = ((hash<<5)+hash)+c; // hash*33 +c
	}
	// stringtoint
	/*uint32_t hash = 0;
	while(*str){
			hash+= *str++;
			if(*str)
				hash+=((uint32_t) *str++)<<8;
	}*/
	
	return hash%MAX_DICT;
}

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[], entry *pHead)
{
    /* TODO: implement */
    uint32_t keys = 0;
    keys = hash(lastname);

	pHead = hash_tbl[keys];
	while(pHead){
			if (strcasecmp(lastname, pHead->lastName) == 0)
				return pHead;
			pHead= pHead->pNext;
	}
	return NULL;
    /*while (pHead != NULL) {
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;*/
}

entry *append(char lastName[], entry *e)
{
    uint32_t keys = 0;
    entry *temp = (entry *)malloc(sizeof(entry));
    
    keys = hash(lastName);
    
    if(hash_tbl[keys]==NULL){
			temp->pNext = NULL;
			strcpy(temp->lastName, lastName);
			hash_tbl[keys] = temp;
			return temp;
	}
    
    hash_tbl[keys]->pNext = temp;
    strcpy(temp->lastName,lastName);
    temp->pNext = NULL;
    hash_tbl[keys] = temp;
    
	return temp;
	
    /*e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;*/
}

