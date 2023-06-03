#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - prints buffe
 * @argc: the address of memory to print
 * @argv: the size of the memory to print
 * Return: - int                                                    
 *
 */
int main(int argc, char *argv[])
{
  int rd, num, file1, sec = 0, i = 0, siz = 1000, se = 1;
  char st[1000], numstr[1000];

  if (argc == 2)
    {
      file1 = open(argv[1], O_RDONLY);
      if (file1 < 0)
	return 1;
      rd = read(file1, st, siz);

      st[rd] = '\0';
      while(st[sec] != '\0')
	{
	 if (st[sec] != '\n')
	   {
	    numstr[i] = st[sec];
	    i++;
	    sec++;
	    continue;
	   }
	 numstr[i] = '\0';
	 num = atoi(numstr);
	 for(i = 1; i < num; i++)
	   {
	     if ((num > 1) && ((num % se) == 0) && (se > 1))
	       {
		 printf("%d=%d*%d\n", num, (num/se), se);
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
