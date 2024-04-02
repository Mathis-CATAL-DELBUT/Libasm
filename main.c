
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
	printf("ft_strlen : %ld || strlen : %ld", ft_strlen(long_string), strlen(long_string));
	strcmp((char[]){ft_strlen(long_string), '\0'}, (char[]){strlen(long_string), '\0'}) == 0 ? printf(" ✅\n") : printf(" ❌\n");
}

void	ft_test_strcpy()
{
	char	*ft_strcp;
	char	*strcp;
	char	dest[1000];
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

	ft_strcp = ft_strcpy(dest, str2);
	memset(dest, 0, 20);
	strcp = strcpy(dest, str2);
	printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(dest, str3);
	memset(dest, 0, 20);
	strcp = strcpy(dest, str3);
	printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(dest, str4);
	memset(dest, 0, 20);
	strcp = strcpy(dest, str4);
	printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(dest, str5);
	memset(dest, 0, 20);
	strcp = strcpy(dest, str5);
	printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(dest, str6);
	memset(dest, 0, 20);
	strcp = strcpy(dest, str6);
	printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(dest, str7);
	memset(dest, 0, 20);
	strcp = strcpy(dest, str7);
	printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(dest, str8);
	memset(dest, 0, 20);
	strcp = strcpy(dest, str8);
	// printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	printf("whith \\a caractere : ");
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(dest, str9);
	memset(dest, 0, 20);
	strcp = strcpy(dest, str9);
	// printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	printf("whith \\b caractere : ");
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(dest, str10);
	memset(dest, 0, 20);
	strcp = strcpy(dest, str10);
	// printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	printf("whith \\t caractere : ");
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(dest, str11);
	memset(dest, 0, 20);
	strcp = strcpy(dest, str11);
	// printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	printf("whith \\n caractere : ");
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(dest, str12);
	memset(dest, 0, 20);
	strcp = strcpy(dest, str12);
	// printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	printf("whith \\v caractere : ");
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(dest, str13);
	memset(dest, 0, 20);
	strcp = strcpy(dest, str13);
	// printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	printf("whith \\f caractere : ");
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(dest, str14);
	memset(dest, 0, 20);
	strcp = strcpy(dest, str14);
	// printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	printf("whith \\r caractere : ");
	strcmp(ft_strcp, strcp) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	ft_strcp = ft_strcpy(dest, long_string);
	memset(dest, 0, 20);
	strcp = strcpy(dest, long_string);
	// printf("ft_strcpy : %s || strcpy : %s", ft_strcp, strcp);
	printf("whith long string : ");
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
	printf("ft_strcmp : %d || strcmp : %d", ft_strcmp("a", "z"), strcmp("a", "z"));
	ft_strcmp("a", "z") == strcmp("a", "z") ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_strcmp : %d || strcmp : %d", ft_strcmp(long_string, long_string), strcmp(long_string, long_string));
	ft_strcmp(long_string, long_string) == strcmp(long_string, long_string) ? printf(" ✅\n") : printf(" ❌\n");
}

void ft_test_write()
{
	printf("\n\n###################   ft_write   ###################\n");
	int fd = open("file_for_test/write_out.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	printf("ft_write : %zd || write : %zd ", ft_write(fd, "Hello", 5), write(fd, "Hello", 5));
	ft_write(fd, "Hello", 5) == write(fd, "Hello", 5) ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_write : %zd || write : %zd ", ft_write(fd, "coucou", 6), write(fd, "coucou", 6));
	ft_write(fd, "coucou", 6) == write(fd, "coucou", 6) ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_write : %zd || write : %zd ", ft_write(fd, "123456789", 9), write(fd, "123456789", 9));
	ft_write(fd, "123456789", 9) == write(fd, "123456789", 9) ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_write : %zd || write : %zd ", ft_write(fd, " ", 1), write(fd, " ", 1));
	ft_write(fd, " ", 1) == write(fd, " ", 1) ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_write : %zd || write : %zd ", ft_write(fd, "ca va", 5), write(fd, "ca va", 5));
	ft_write(fd, "ca va", 5) == write(fd, "ca va", 5) ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_write : %zd || write : %zd ", ft_write(fd, "c'est moi", 9), write(fd, "c'est moi", 9));
	ft_write(fd, "c'est moi", 9) == write(fd, "c'est moi", 9) ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_write : %zd || write : %zd ", ft_write(fd, "c'est moi aussi", 15), write(fd, "c'est moi aussi", 15));
	ft_write(fd, "c'est moi aussi", 15) == write(fd, "c'est moi aussi", 15) ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_write : %zd || write : %zd ", ft_write(fd, "\a", 1), write(fd, "\a", 1));
	ft_write(fd, "\a", 1) == write(fd, "\a", 1) ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_write : %zd || write : %zd ", ft_write(fd, "\b", 1), write(fd, "\b", 1));
	ft_write(fd, "\b", 1) == write(fd, "\b", 1) ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_write : %zd || write : %zd ", ft_write(fd, "\t", 1), write(fd, "\t", 1));
	ft_write(fd, "\t", 1) == write(fd, "\t", 1) ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_write : %zd || write : %zd ", ft_write(fd, "\n", 1), write(fd, "\n", 1));
	ft_write(fd, "\n", 1) == write(fd, "\n", 1) ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_write : %zd || write : %zd ", ft_write(fd, "\v", 1), write(fd, "\v", 1));
	ft_write(fd, "\v", 1) == write(fd, "\v", 1) ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_write : %zd || write : %zd ", ft_write(fd, "\f", 1), write(fd, "\f", 1));
	ft_write(fd, "\f", 1) == write(fd, "\f", 1) ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_write : %zd || write : %zd ", ft_write(fd, "\r", 1), write(fd, "\r", 1));
	ft_write(fd, "\r", 1) == write(fd, "\r", 1) ? printf(" ✅\n") : printf(" ❌\n");
	printf("ft_write : %zd || write : %zd ", ft_write(fd, long_string, 1000), write(fd, long_string, 1000));
	ft_write(fd, long_string, 1000) == write(fd, long_string, 1000) ? printf(" ✅\n") : printf(" ❌\n");
	fd = open("file_for_test/no_perm", O_WRONLY | O_CREAT | O_TRUNC, 0000);
	ft_write(-1, "a", 1);
	perror("ERROR ");
}

static void	do_test(char *path)
{
	char	buf[2][100];
	int		ori[2];
	int		ft[2];
	int		fd;

	memset(&buf, 0, sizeof(char [2][100]));
	fd = open(path, O_RDONLY);
	ori[0] = read(fd, buf[0], 50);
	ori[1] = errno;
	close(fd);
	fd = open(path, O_RDONLY);
	ft[0] = ft_read(fd, buf[1], 50);
	ft[1] = errno;
	close(fd);
	if ((strcmp(buf[1], buf[0]) != 0) || (ori[0] != ft[0]) || (ori[1] != ft[1]))
		printf("ft_read with %s file ❌\n", path);
	else
		printf("ft_read with %s file ✅\n", path);
}

void	ft_test_read(void)
{
	printf("\n\n###################   ft_read   ###################\n");
	do_test("./Makefile");
	do_test("./main.c");
	do_test("./file_for_test/empty.txt");
	do_test("./NotExist");
	perror("ERROR");
	do_test("./file_for_test/no_perm");
	perror("ERROR");
}

void ft_test_strdup()
{
	printf("\n\n###################   ft_strdup   ###################\n");
	char	*str1 = "Hello";
	char	*str2 = "coucou";
	char	*str3 = "123456789";
	char	*str4 = " ";
	char	*str5 = "ca va";
	char	*str6 = "c'est moi";
	char	*str7 = "c'est moi aussi";
	char	*str8 = "\a";
	char	*str9 = "\b";
	char	*str10 = "\t";
	char	*str11 = "\n";
	char	*str12 = "\v";
	char	*str13 = "\f";
	char	*str14 = "\r";

	char	*strcp1 = ft_strdup(str1);
	char	*strcp2 = ft_strdup(str2);
	char	*strcp3 = ft_strdup(str3);
	char	*strcp4 = ft_strdup(str4);
	char	*strcp5 = ft_strdup(str5);
	char	*strcp6 = ft_strdup(str6);
	char	*strcp7 = ft_strdup(str7);
	char	*strcp8 = ft_strdup(str8);
	char	*strcp9 = ft_strdup(str9);
	char	*strcp10 = ft_strdup(str10);
	char	*strcp11 = ft_strdup(str11);
	char	*strcp12 = ft_strdup(str12);
	char	*strcp13 = ft_strdup(str13);
	char	*strcp14 = ft_strdup(str14);
	char	*strcpLONG = ft_strdup(long_string);

	printf("ft_strdup : %s || strdup : %s", strcp1, strdup(str1));
	strcmp(strcp1, strdup(str1)) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	printf("ft_strdup : %s || strdup : %s", strcp2, strdup(str2));
	strcmp(strcp2, strdup(str2)) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	printf("ft_strdup : %s || strdup : %s", strcp3, strdup(str3));
	strcmp(strcp3, strdup(str3)) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	printf("ft_strdup : %s || strdup : %s", strcp4, strdup(str4));
	strcmp(strcp4, strdup(str4)) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	printf("ft_strdup : %s || strdup : %s", strcp5, strdup(str5));
	strcmp(strcp5, strdup(str5)) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	printf("ft_strdup : %s || strdup : %s", strcp6, strdup(str6));
	strcmp(strcp6, strdup(str6)) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	printf("ft_strdup : %s || strdup : %s", strcp7, strdup(str7));
	strcmp(strcp7, strdup(str7)) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	printf("ft_strdup : %s || strdup : %s", strcp8, strdup(str8));
	strcmp(strcp8, strdup(str8)) == 0 ? printf(" ✅\n") : printf(" ❌\n");	

	printf("ft_strdup : %s || strdup : %s", strcp9, strdup(str9));
	strcmp(strcp9, strdup(str9)) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	printf("ft_strdup : %s || strdup : %s", strcp10, strdup(str10));
	strcmp(strcp10, strdup(str10)) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	printf("ft_strdup : %s || strdup : %s", strcp11, strdup(str11));
	strcmp(strcp11, strdup(str11)) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	printf("ft_strdup : %s || strdup : %s", strcp12, strdup(str12));
	strcmp(strcp12, strdup(str12)) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	printf("ft_strdup : %s || strdup : %s", strcp13, strdup(str13));
	strcmp(strcp13, strdup(str13)) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	printf("ft_strdup : %s || strdup : %s", strcp14, strdup(str14));
	strcmp(strcp14, strdup(str14)) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	printf("ft_strdup : with long string");
	strcmp(strcpLONG, strdup(long_string)) == 0 ? printf(" ✅\n") : printf(" ❌\n");

	free(strcp1);
	free(strcp2);
	free(strcp3);
	free(strcp4);
	free(strcp5);
	free(strcp6);
	free(strcp7);
	free(strcp8);
	free(strcp9);
	free(strcp10);
	free(strcp11);
	free(strcp12);
	free(strcp13);
	free(strcp14);
	free(strcpLONG);
}

int	main(void)
{
    ft_test_strlen();
	ft_test_strcpy();
	ft_test_strcmp();
	ft_test_write();
	ft_test_strdup();
	ft_test_read();
	return (0);
}	
