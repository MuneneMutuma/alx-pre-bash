#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct linked_paths {
	char *path;
	struct linked_paths *next;
} path_t;


path_t *add_node_end(path_t **head, char *path);
/***/
int main(void)
{
	char *path, *str1, *token;
	path_t *list, *head = NULL, *node;
	path_t *iter;

	list = malloc(sizeof(path_t));
	path = getenv("PATH");
	for(str1 = path; ; str1 = NULL)
	{
		token = strtok(str1, ":");

		if (token == NULL)
		{
			list->next = NULL;
			break;
		}

		node = add_node_end(&head, token);

		if (strcmp(node->path, token) == 0)
			printf("We are okay!\n");
	}

	iter = head;
	for(int i = 0 ; iter->next; i++)
	{
		printf("%s\n", iter->path);
		iter = iter->next;
	}


	return (0);
}

path_t *add_node_end(path_t **head, char *path)
{
	path_t *new_node, *iter_node;

	new_node = malloc(sizeof(path_t));

	if (!new_node)
		return(NULL);

	new_node->path = strdup(path);
	iter_node = *head;
	if (*head == NULL)
	{
		new_node->next = *head;
		*head = new_node;
	}

	else
	{
		while (iter_node->next)
			iter_node = iter_node->next;

		new_node->next = iter_node->next;
		iter_node->next = new_node;
	}
	
	if (!new_node)
		return (NULL);
	
	return (new_node);
}
