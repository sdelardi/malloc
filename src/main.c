#include "../includes/malloc.h"
#include <time.h>



/*static void	malloc_calloc(void)
{
	char	*str;
	char	*str2;
	char	*str3;
	char	*str4;
	int		i = 0;

	printf("calloc str de 16 octets * 2\n");
	str = (char*)calloc(2 ,sizeof(char) * 16);
	while (++i < 16 * 2)
		printf("%d", str[i]);

	printf("\ncalloc str2 de 1257 octets * 3\n");
	str2 = (char*)calloc(3, sizeof(char) * 1257);
	i = 0;
	while (++i < 3 * 1257)
		printf("%d", str[i]);

	printf("\ncalloc str3 de 327 octets * 2\n");
	str3 = (char*)calloc(2, sizeof(char) * 327);
	i = 0;
	while (++i < 2 * 327)
		printf("%d", str[i]);

	printf("\ncalloc str4 de 42 octets * 5\n");
	str4 = (char*)calloc(5, sizeof(char) * 42);
	i = 0;
	while (++i < 5 * 42)
		printf("%d", str[i]);
	printf("\n");

	printf("Allocated memory:\n");
	ft_show_alloc_mem();
}*/

static void	malloc_malloc(void)
{
	char	*str;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;
	char	*str6;
	char	*str7;
	char	*str8;

	printf("malloc str de 16 octets\n");
	str = (char*)ft_malloc(sizeof(char) * 16);
	printf("malloc str2 de 1257 octets\n");
	str2 = (char*)ft_malloc(sizeof(char) * 1257);
	printf("malloc str3 de 327 octets\n");
	str3 = (char*)ft_malloc(sizeof(char) * 327);
	printf("malloc str4 de 42 octets\n");
	str4 = (char*)ft_malloc(sizeof(char) * 42);
	printf("malloc str5 de 1 octet\n");
	str5 = (char*)ft_malloc(sizeof(char) * 1);
	printf("malloc str6 de 4055 octet\n");
	str6 = (char*)ft_malloc(sizeof(char) * 4055);
	printf("malloc str7 de 0 octet\n");
	str7 = (char*)ft_malloc(sizeof(char) * 0);
	printf("malloc str8 de -2 octet\n\n");
	str8 = (char*)ft_malloc(sizeof(char) * -2);

	int i = 0;
	char *tab[4048];
	while(i < 4048)
	{
		tab[i] = ft_malloc(24);
		i++;
	}
	i= 0;
	while (i < 23)
	{
		tab[0][i] = 'p';
		i++;
	}
	tab[0][23] = '\0';
	printf("TAB %s\n", tab[0]);
	i = 0;
	while(i < 4048)
	{
		ft_free(tab[i]);
		i++;
	}
	//ft_free(str6);
	//ft_free(str);
	//ft_free(str4);
	//ft_free(str5);
	printf("Allocated memory:\n");
	ft_show_alloc_mem();
}

static void	malloc_realloc(void)
{
	char	*str;
	char	*str2;
	char	*str3;
	char	*str4;

	printf("malloc str de 16 octets\n");
	str = (char*)ft_malloc(sizeof(char) * 16);
	printf("malloc str2 de 1257 octets\n");
	str2 = (char*)ft_malloc(sizeof(char) * 1257);
	printf("malloc str3 de 327 octets\n");
	str3 = (char*)ft_malloc(sizeof(char) * 327);
	printf("STR3: [%p]\n", str3);
	printf("malloc str4 de 42 octets\n\n");
	str4 = (char*)ft_malloc(sizeof(char) * 42);

	printf("Allocated memory:\n");
	ft_show_alloc_mem();

	printf("\nrealloc str de 27 octets\n");
	str = (char *)ft_realloc(str, sizeof(char) * 27);
	printf("realloc str3 de 233 octets\n");
	str3 = (char *)ft_realloc(str3, sizeof(char) * 233);
	printf("realloc str2 de 1337 octets\n");
	str2 = (char *)ft_realloc(str2, sizeof(char) * 1337);
	printf("realloc str4 de 2100 octets\n\n");
	str4 = (char *)ft_realloc(str4, sizeof(char) * 2100);

	printf("Allocated memory:\n");
	ft_show_alloc_mem();
}

static void	malloc_free(void)
{
	char	*str;
	char	*str2;
	char	*str3;
	char	*str4;

	printf("malloc str de 16 octets\n");
	str = (char*)ft_malloc(sizeof(char) * 16);
	printf("malloc str2 de 1257 octets\n");
	str2 = (char*)ft_malloc(sizeof(char) * 1257);
	printf("malloc str3 de 327 octets\n");
	str3 = (char*)ft_malloc(sizeof(char) * 327);
	printf("malloc str4 de 42 octets\n\n");
	str4 = (char*)ft_malloc(sizeof(char) * 42);

	printf("Allocated memory:\n");
	ft_show_alloc_mem();

	printf("\nfree str\n");
	ft_free(str);
	printf("Allocated memory:\n");
	ft_show_alloc_mem();

	printf("\nfree str2\n");
	ft_free(str2);
	printf("Allocated memory:\n");
	ft_show_alloc_mem();

	printf("\nfree str3\n");
	ft_free(str3);
	printf("Allocated memory:\n");
	ft_show_alloc_mem();

	printf("\nfree str4\n");
	ft_free(str4);
	printf("Allocated memory:\n");
	ft_show_alloc_mem();

	printf("\nfree str4\n");
	ft_free(str4);
}

static void	u_stupid_malloc_test(void)
{
	int		i;
	void	*allocation;

	i = 0;
	srand(time(NULL));
	printf("--- Stupid test begin ---\n");
	printf("--- Random stuff: ---\n");
	while (i < 1000)
	{
		int uji = rand() % 2000;
		allocation = (void *)ft_malloc(sizeof(char) * uji);
		ft_free(allocation);
		i++;
	}
	printf("--- Fat alloc ---\n");
	allocation = NULL;
	allocation = (void *)ft_malloc(sizeof(char) * 65535);
	i = 5;
	while (i > 0)
	{
	printf("--- Fat realloc ---\n");
		allocation = (void *)ft_realloc(allocation, 65535 / i);	
		printf("\n");
		i--;
	}
	ft_free(allocation);
}

int		main(int ac, char **av)
{

	(void)ac;
	if (av[1] && !(av[1][1]))
	{
		if (av[1][0] == '1')
		{
			printf("malloc_MALLOC\n");
			malloc_malloc();
		}
		else if (av[1][0] == '2')
		{
			printf("malloc_REALLOC\n");
			malloc_realloc();
		}
		else if (av[1][0] == '3')
		{
			printf("malloc_FREE\n");
			malloc_free();
		}
		else if (av[1][0] == '4')
		{
			printf("malloc_STUPID\n");
			u_stupid_malloc_test();
		}

		else
			printf("please choose what malloc to do :\n1 -> malloc\n2 -> realloc\n3 -> free\n4 -> stupid malloc\n");
	}
	else
		printf("please choose what malloc to do :\n1 -> malloc\n2 -> realloc\n3 -> free\n4 -> stupid malloc\n");
	return (0);
}
