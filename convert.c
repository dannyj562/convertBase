#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* A function that reads a positive integer number in base 10 from
 * stdin. Return number or -1 on failure. Will read one character
 * ahead! */

int read_int10(void)
{
   int res = 0, c, count=0;   

   while(isdigit(c=getchar()))
   {
      res = (res*10)+c-'0';
      count++;
   }
   if(count > 0) /* We read something */
   {
         return res;
   }
   return -1;
}



/* Is a character a valid digit in base b? */

int is_base_digit(int c, int base)
{
   if(c - '0' < 0)
   {
      return 0;
   }
   if(c - '0' >=base)
   {
      return 0;
   }
   return 1;
}


/* A function that reads a positive integer number in any base from stdin */


int read_int_b(int base)
{
   int res = 0, c, count = 0;
   
   res = 0;
   while(is_base_digit((c=getchar()),base))
   {
      res = (res*base)+c-'0';
      count++;
   }
   if(count > 0) /* We read something */
   {
      return res;
   }
   return -1;
}

/* Alternative to read_int10 */

int read_int10b(void)
{
   return read_int_b(10);
}


/* Write non-zero positive integer in any base to stdout */

void write_int_b_rekursive(int value, int base)
{
   int digit;
   
   digit = value % base;
   value = value/base;
   
   if(value!=0)
   {
      write_int_b_rekursive(value, base);
   }
   putchar(digit + '0');
}

/* Write positive integer in any base to stdout */

void write_int_b(int value, int base)
{
   if(value == 0)
   {
      putchar('0');
   }
   write_int_b_rekursive(value, base);
}


int main(void)
{
   int num, base;

   while(1)
   {
      printf("Input decimal value and desired base!\n");
      num = read_int10();
      if(num == -1)
      {
	 return EXIT_SUCCESS;
      }
      base = read_int10();
      if(base == -1 || base < 2 || base > 10)
      {
	 printf("Error: No valid base!\n");	 
	 return EXIT_FAILURE;
      }
      write_int_b(num, base);
      putchar('\n');
   }
}
