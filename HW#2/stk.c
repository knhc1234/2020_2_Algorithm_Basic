// stk.c

#include "functions.h"

void stk_print(stack stk)
{
	if (!stk) { return; }

	while (stk) {

		printf("int stk_print %p", stk->ptr);

		stk = stk->parent;

	}	// while (stk)
}

void stk_push(stk_pck package, nodeptr* push)
{
	stack* stk				= package->stk;
	stack* temp_stk			= package->temp_stk;

	if (!(*stk)) {
		*stk				= (stack)malloc(sizeof(stk_rec));
		(*stk)->ptr			= *push;
		(*stk)->parent		= NULL;
	}	// if (stk)

	else {
		*temp_stk			= (stack)malloc(sizeof(stk_rec));
		(*temp_stk)->ptr		= *push;
		(*temp_stk)->parent = *stk;

		*stk				= *temp_stk;
		temp_stk			= NULL;
	}	// else
}

void stk_pop(stack* stk, nodeptr* pop)
{
	*pop = (*stk)->ptr;
	*stk = (*stk)->parent;
}