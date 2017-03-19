#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <assert.h>

#include <ucontext.h>
#include "tlib.h"

TCB* head = NULL;
TCB* tail = NULL;
int curr = 0;
int length = 0; //lenght of the queue-like structure contains threads
int tid;



int tlib_init (void)
{
    return (TLIB_ERROR);
}

/* implementation of stub is already given below */
void stub (void (*tstartf)(void *), void *arg)
{
    
	tstartf (arg); /* calling thread start function to execute */
    /* 
        We are done with executing the application specified thread start
        function. Hence we can now terminate the thread
    */
	tlib_delete_thread(TLIB_SELF);
    exit(0);
}

int tlib_create_thread(void (*func)(void *), void *param)
{
	if(length >= TLIB_MAX_THREADS)
		return TLIB_NOMORE;
	else if (length == 0) {
		TCB* new_tcb = (TCB *)malloc(sizeof(TCB));
		new_tcb -> context = (ucontext_t *)malloc(sizeof(ucontext_t));
		//makecontext
		new_tcb->next = NULL;
		head = new_tcb;
		tail = head;
	}
	else
	{
		TCB* new_tcb = (TCB *)malloc(sizeof(TCB));
		new_tcb -> context = (ucontext_t *)malloc(sizeof(ucontext_t));
		//makecontext
		new_tcb->next = NULL;
		tail->next = new_tcb;
		tail = new_tcb; 
	}

    //return (TLB_ERROR);
}


int tlib_yield(int wantTid)
{
	if (wantTid > TLIB_MAX_THREADS)
		 return TLIB_INVALID;
	else if( wantTid == TLIB_SELF)
		return TLIB_INVALID;
	else{

	}
}


int tlib_delete_thread(int tid)
{
    
}

