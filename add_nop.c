#include "monty.h"
/**
 * xfadd - adds the top two elements
 * @head: stack head
 * @counter: line number
*/
void xfadd(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		xfreestack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}

/**
* xfreestack - frees a doubly linked
* @head: head of the stack
*/
void xfreestack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
/**
  *xfnop- nothing
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void xfnop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
