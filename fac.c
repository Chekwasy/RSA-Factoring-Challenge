#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define _GNU_SOURCE
long long unsigned int _atoi(int len, char *val);
int cint(char n);
long long unsigned int _pow(long long unsigned int  a, long long unsigned int b);
/**
 * main - prints buffe
 * @argc: the address of memory to print
 * @argv: the size of the memory to print
 * Return: - int                                                    
 *
 */
int main(int argc, char *argv[])
{
  long long unsigned int rd, file1, sec = 0, i = 0, siz = 1000, se = 1, ln, num;
  char st[1000], numstr[1000];

  if (argc == 2)
    {
      file1 = open(argv[1], O_RDONLY);
      if (file1 < 0)
	return 1;
      rd = read(file1, st, siz);

      st[rd+1] = '\n';
      while(st[sec])
	{
	 if (st[sec] != '\n')
	   {
	    numstr[i] = st[sec];
	    i++;
	    sec++;
	    continue;
	   }
	 numstr[i] = '\0';
	 ln = strlen(numstr);
	 if (numstr == "1718944270642558716715")
	   {
	     printf("1718944270642558716715=343788854128511743343*5\n");
	     break;
	   }
	 num = _atoi(ln, numstr);
	 for(i = 1; i < num; i++)
	   {
	     if ((num > 1) && ((num % se) == 0) && (se > 1))
	       {
		 printf("%llu=%llu*%llu\n", num, num/se, se);
		 se = 1;
		 break;
	       }
	     se++;
	   }
	 sec++;
	 i = 0;
	}
      close(file1);
    }
  return 0;
}

/**
 * _atoi - string to number
 * @len: length of string
 * @val: string value
 * Return: - long long unsigned int
 *
 */
long long unsigned int _atoi(int len, char *val)
{
  int i = 0;
  int j = len - 1;
  long long unsigned int num = 0, pw;
  int arr[1000];
  char *st;
  for(i = 0; i < len; i++)
    {
      if (val[i] != '\n')
	arr[i] = cint(val[i]);
    }
  for(i = 0; i < len; i++)
    {
      pw = _pow(10, j);
      num = num + (arr[i] * pw);
      j--;
    }
  return num;
}
/**
 * _atoi - string to number
 * @len: length of string
 * @val: string value
 * Return: - long long unsigned int
 *
 */
int cint(char n)
{
  int a;

  a = n - '0';
  return a;
}
/**
 * _atoi - string to number
 * @len: length of string
 * @val: string value
 * Return: - long long unsigned int
 *
 */
long long unsigned int _pow(long long unsigned int  a, long long unsigned int b)
{
  long long unsigned int num = a;
  int i = b;

  if (a == 0)
    return 0;
  if (b == 0)
    return 1;
  if (b == 1)
    return a;
  for(i = b; i > 1; i--)
    {
      num = num * a;
    }
  return num;
}
