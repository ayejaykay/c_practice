#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>



/********* Circular Buffer Using Array and Linked List *********
 * 
 * Author: Anthony Kahley
 * 
 * Description: Practice Circular Buffers to be used in my remote sniffer and of course other applications
 * 
****************************************************************/


#define BUFFER_SIZE 6
uint8_t HEAD, TAIL = 0;
uint8_t BUFFER[BUFFER_SIZE];
uint8_t is_full_flag = 0;
uint8_t is_empty_flag = 1;


void buffer_write(uint8_t data)
{
    if(is_full_flag)
    {
        printf("Buffer is full\n");
    }
    else
    {
        BUFFER[HEAD] = data;
        HEAD = (HEAD+1)%BUFFER_SIZE;
        if(HEAD==TAIL)
        {
            is_full_flag = 1;
            is_empty_flag = 0;
        }    
    }
}


uint8_t buffer_pop_left()
{
    uint8_t data_var =0;
    if(is_empty_flag)
    {
        printf("Buffer is empty\n");
        
    }
    else
    {
        data_var = BUFFER[TAIL];
        TAIL = (TAIL+1)%BUFFER_SIZE;
        is_full_flag = 0;
        if(HEAD==TAIL && BUFFER[HEAD]==NULL)
        {
            is_empty_flag = 1;
        }
    }

    return data_var;
}


void get_buffer_contents(void)
{
    int i;
    printf("BUFFER CONTENTS: %d", BUFFER[0]);
    for(i=TAIL+1; i<HEAD; i++)
    {
        printf(", %d", BUFFER[i]);
    }
    printf("\n\r");
}


int main(void)
{
    uint8_t* data;
    int i;
    for(i=0; i<BUFFER_SIZE; i++)
    {
        buffer_write(i);
        printf("Buffer Info: HEAD: %d, TAIL: %d, Data: %d\n\r", HEAD, TAIL, i);
        if(i%2 == 0)
        {
            get_buffer_contents();
        }
    }

    printf("BUFFER[0]: %d\n", buffer_pop_left());
    printf("BUFFER[0]: %d\n", buffer_pop_left());
    printf("BUFFER[0]: %d\n", buffer_pop_left());
    printf("BUFFER[0]: %d\n", buffer_pop_left());
    printf("BUFFER[0]: %d\n", buffer_pop_left());
    printf("BUFFER[0]: %d\n", buffer_pop_left());
    printf("BUFFER[0]: %d\n", buffer_pop_left());
}