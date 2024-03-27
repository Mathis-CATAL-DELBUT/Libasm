
#include "libasm.h"
#include <string.h>
#include <stdio.h>

void    ft_test_strlen(void)
{
    printf("\n\n###################   ft_strlen   ###################\n");
	printf("ft_strlen : %ld || strlen : %ld", ft_strlen("1"), strlen("1"));
	strcmp((char[]){ft_strlen("1"), '\0'}, (char[]){strlen("1"), '\0'}) == 0 ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strlen : %ld || strlen : %ld", ft_strlen("123456789"), strlen("123456789"));
	strcmp((char[]){ft_strlen("123456789"), '\0'}, (char[]){strlen("123456789"), '\0'}) == 0 ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strlen : %ld || strlen : %ld", ft_strlen(""), strlen(""));
	strcmp((char[]){ft_strlen(""), '\0'}, (char[]){strlen(""), '\0'}) == 0 ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strlen : %ld || strlen : %ld", ft_strlen("Hello"), strlen("Hello"));
	strcmp((char[]){ft_strlen("Hello"), '\0'}, (char[]){strlen("Hello"), '\0'}) == 0 ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strlen : %ld || strlen : %ld", ft_strlen("coucou"), strlen("coucou"));
	strcmp((char[]){ft_strlen("coucou"), '\0'}, (char[]){strlen("coucou"), '\0'}) == 0 ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strlen : %ld || strlen : %ld", ft_strlen("Hey"), strlen("Hey"));
	strcmp((char[]){ft_strlen("Hey"), '\0'}, (char[]){strlen("Hey"), '\0'}) == 0 ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strlen : %ld || strlen : %ld", ft_strlen("                    "), strlen("                    "));
	strcmp((char[]){ft_strlen("                    "), '\0'}, (char[]){strlen("                    "), '\0'}) == 0 ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strlen : %ld || strlen : %ld", ft_strlen("\a"), strlen("\a"));
	strcmp((char[]){ft_strlen("\a"), '\0'}, (char[]){strlen("\a"), '\0'}) == 0 ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strlen : %ld || strlen : %ld", ft_strlen("\b"), strlen("\b"));
	strcmp((char[]){ft_strlen("\b"), '\0'}, (char[]){strlen("\b"), '\0'}) == 0 ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strlen : %ld || strlen : %ld", ft_strlen("\t"), strlen("\t"));
	strcmp((char[]){ft_strlen("\t"), '\0'}, (char[]){strlen("\t"), '\0'}) == 0 ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strlen : %ld || strlen : %ld", ft_strlen("\n"), strlen("\n"));
	strcmp((char[]){ft_strlen("\n"), '\0'}, (char[]){strlen("\n"), '\0'}) == 0 ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strlen : %ld || strlen : %ld", ft_strlen("\v"), strlen("\v"));
	strcmp((char[]){ft_strlen("\v"), '\0'}, (char[]){strlen("\v"), '\0'}) == 0 ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strlen : %ld || strlen : %ld", ft_strlen("\f"), strlen("\f"));
	strcmp((char[]){ft_strlen("\f"), '\0'}, (char[]){strlen("\f"), '\0'}) == 0 ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strlen : %ld || strlen : %ld", ft_strlen("\r"), strlen("\r"));
	strcmp((char[]){ft_strlen("\r"), '\0'}, (char[]){strlen("\r"), '\0'}) == 0 ? printf(" ✅\n") : printf(" ❌\n");
}

void	ft_test_strcpy()
{
	char	*ft_strcp;
	char	*strcp;
	char	dest[20];
	char	str1[] = "COUCOU";
	char	str2[] = "HEY";
	char	str3[] = "              ";
	char	str4[] = " ";
	char	str5[] = "ca va";
	char	str6[] = "c'est moi";
	char	str7[] = "c'est moi aussi";
	char	str8[] = "\a";
	char	str9[] = "\b";
	char	str10[] = "\t";
	char	str11[] = "\n";
	char	str12[] = "\v";
	char	str13[] = "\f";
	char	str14[] = "\r";

	printf("\n\n###################   ft_strcpy   ###################\n");

	ft_strcp = ft_strcpy(dest, str1);
	memset(dest, 0, 20); // reset dest
	strcp = strcpy(dest, str1);
	printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(str1, str2);
	memset(dest, 0, 20);
	strcp = strcpy(str1, str2);
	printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(str1, str3);
	memset(dest, 0, 20);
	strcp = strcpy(str1, str3);
	printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(str1, str4);
	memset(dest, 0, 20);
	strcp = strcpy(str1, str4);
	printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(str1, str5);
	memset(dest, 0, 20);
	strcp = strcpy(str1, str5);
	printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(str1, str6);
	memset(dest, 0, 20);
	strcp = strcpy(str1, str6);
	printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(str1, str7);
	memset(dest, 0, 20);
	strcp = strcpy(str1, str7);
	printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(str1, str8);
	memset(dest, 0, 20);
	strcp = strcpy(str1, str8);
	// printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	printf("whith \\a caractere : ");
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(str1, str9);
	memset(dest, 0, 20);
	strcp = strcpy(str1, str9);
	// printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	printf("whith \\b caractere : ");
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(str1, str10);
	memset(dest, 0, 20);
	strcp = strcpy(str1, str10);
	// printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	printf("whith \\t caractere : ");
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(str1, str11);
	memset(dest, 0, 20);
	strcp = strcpy(str1, str11);
	// printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	printf("whith \\n caractere : ");
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(str1, str12);
	memset(dest, 0, 20);
	strcp = strcpy(str1, str12);
	// printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	printf("whith \\v caractere : ");
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(str1, str13);
	memset(dest, 0, 20);
	strcp = strcpy(str1, str13);
	// printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	printf("whith \\f caractere : ");
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(str1, str14);
	memset(dest, 0, 20);
	strcp = strcpy(str1, str14);
	// printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	printf("whith \\r caractere : ");
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");
}

void ft_test_strcmp()
{
	printf("\n\n###################   ft_strcmp   ###################\n");
	printf("ft_strcmp : %d || strcmp : %d", ft_strcmp("12", "11"), strcmp("12", "11"));
	ft_strcmp("12", "11") == strcmp("12", "11") ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strcmp : %d || strcmp : %d", ft_strcmp("1234567", "123456789"), strcmp("1234567", "123456789"));
	ft_strcmp("1234567", "123456789") == strcmp("1234567", "123456789") ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strcmp : %d || strcmp : %d", ft_strcmp("      ", ""), strcmp("      ", ""));
	ft_strcmp("      ", "") == strcmp("      ", "") ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strcmp : %d || strcmp : %d", ft_strcmp("Hello", "Helloooo"), strcmp("Hello", "Helloooo"));
	ft_strcmp("Hello", "Helloooo") == strcmp("Hello", "Helloooo") ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strcmp : %d || strcmp : %d", ft_strcmp("coucou ca va", "coucou"), strcmp("coucou ca va", "coucou"));
	ft_strcmp("coucou ca va", "coucou") == strcmp("coucou ca va", "coucou") ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strcmp : %d || strcmp : %d", ft_strcmp("HHHey", "Hey"), strcmp("HHHey", "Hey"));
	ft_strcmp("HHHey", "Hey") == strcmp("HHHey", "Hey") ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strcmp : %d || strcmp : %d", ft_strcmp("                   ", "                    "), strcmp("                   ", "                    "));
	ft_strcmp("                   ", "                    ") == strcmp("                   ", "                    ") ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strcmp : %d || strcmp : %d", ft_strcmp("\a", "\a"), strcmp("\a", "\a"));
	ft_strcmp("\a", "\a") == strcmp("\a", "\a") ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strcmp : %d || strcmp : %d", ft_strcmp("\b", "\b"), strcmp("\b", "\b"));
	ft_strcmp("\b", "\b") == strcmp("\b", "\b") ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strcmp : %d || strcmp : %d", ft_strcmp("\t", "\t"), strcmp("\t", "\t"));
	ft_strcmp("\t", "\t") == strcmp("\t", "\t") ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strcmp : %d || strcmp : %d", ft_strcmp("\n", "\n"), strcmp("\n", "\n"));
	ft_strcmp("\n", "\n") == strcmp("\n", "\n") ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strcmp : %d || strcmp : %d", ft_strcmp("\v", "\v"), strcmp("\v", "\v"));
	ft_strcmp("\v", "\v") == strcmp("\v", "\v") ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strcmp : %d || strcmp : %d", ft_strcmp("\f", "\f"), strcmp("\f", "\f"));
	ft_strcmp("\f", "\f") == strcmp("\f", "\f") ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strcmp : %d || strcmp : %d", ft_strcmp("\r", "\r"), strcmp("\r", "\r"));
	ft_strcmp("\r", "\r") == strcmp("\r", "\r") ? printf(" ✅\n") : printf(" ❌\n");
}

int	main(void)
{
    ft_test_strlen();
	ft_test_strcpy();
	ft_test_strcmp();
	return (0);
}	
