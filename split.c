#include "libft.h"
#include <stdio.h>
int ft_split_size(char const *str, char c)
{
	int count = 0;
	int key = 0;
	while (*str != '\0')
	{
		if(*str != c)
			key = 1;
		else if(*str == c && key)
		{
			count++;
			key = 0;
		}
		str++;
	}
	if(key)
		count++;
	return count;
}
char *ft_create_tokens(char* str, char c, int* begin_index)
{
	while(str[*begin_index] == c && str[*begin_index] != '\0')
		(*begin_index)++;

	int last_index = *begin_index;

	while (str[last_index] != c && str[last_index] != '\0')	
		last_index++;

	if(last_index != *begin_index)
	{
		char* token = malloc(last_index - *begin_index + 1);
		if(token == NULL)
			return NULL;
		int i = 0;
		while(*begin_index < last_index && str[*begin_index] != c)
		{	
			token[i] = str[*begin_index];
			i++;
			(*begin_index)++;
		}
		token[i] = '\0';	
		return token;
	}

	return NULL;
}
void free_split(char** split)
{
	char **splitt = split;
	while(*splitt != NULL)
	{
		free(*splitt);
		splitt++;
	}
	free(split);
}
char **ft_split(char const *str, char c)
{	if(str == NULL)
		return NULL;	
	int split_size = ft_split_size(str,c);
	char** split_tokens = (char**) malloc(sizeof(char*) * (split_size + 1));
	if(split_tokens == NULL)
		return NULL;
	int begin = 0;
	int i = 0;
	while(split_size > 0)
	{	
		char* token = ft_create_tokens((char*)str,c,&begin);
		if(token == NULL)
		{	
			free_split(split_tokens);
			return NULL;			
		}
		split_tokens[i] = token;
		split_size--;
		i++;
	}
	split_tokens[i]=NULL;
		
	return split_tokens;
}
/*
int main(int ac, char** arg)
{	

	printf("Kelime sayısı : %d\n", ft_split_size(arg[1],' '));
	char ** str = ft_split(arg[1],' ');
	while(*str != NULL)
	{
		printf("%s\n",*str);
		str++;
	}
	return 0;
}*/

