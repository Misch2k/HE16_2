#include <stdio.h>
#include <stdlib.h>
 
unsigned long long fak(unsigned n)
{
  unsigned long long result = 1;
  unsigned i = 1;
  for (; i <=n; ++i)
    result *= i;
  return result;
}
 
 
unsigned binomial(unsigned n, unsigned k)
{
  return fak(n)/(fak(k)*fak(n-k));
}
 
int main ()
{
  unsigned max_n;
  puts("Maximales n (0-20)? ");
  if (scanf("%ud", &max_n) == 1)
    {
      unsigned zeichenbreite=7;
      // "Empirisch"  bestimmte Werte
      if (max_n > 20)  // Zahlen werden zu groß
        exit(1);
      else if (max_n > 19)
        zeichenbreite = 7;
      else if (max_n > 16)
        zeichenbreite = 6;
      else if (max_n > 13)
        zeichenbreite = 5;
      else if (max_n > 9)
        zeichenbreite = 4;
      else if (max_n > 5)
        zeichenbreite = 3;
      else
        zeichenbreite = 2;
 
      char formatstring[6];
      sprintf(formatstring, "%%%uu ", zeichenbreite - 1);
 
      unsigned n, k;
      for(n = 0; n <= max_n; ++n)
        {
          // Whitespace vorne
          int num_whitespace = ((max_n)/2. - n/2.)*zeichenbreite;
          int i;
          for(i = 0; i < num_whitespace; ++i)
            putchar(' ');
         
          // Eigentliche Werte
          for(k = 0; k <= n; ++k)
            {
              printf(formatstring, binomial(n,k));
            }
          putchar('\n');
        }
    }
 
  return 0;
}