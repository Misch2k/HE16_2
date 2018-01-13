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
  if (k>n) return 0;   // ACHTUNG: Hier auch geändert!
  return fak(n)/(fak(k)*fak(n-k));
}
 
int main ()
{
  unsigned max_n;
  puts("Maximales n (0-20)? ");
  if (scanf("%ud", &max_n) == 1)
    {
      if (max_n > 20)  // Zahlen werden zu groß
        exit(1);
 
      unsigned n, k;
      for(n = 0; n <= max_n; ++n)
        {
          for(k = 0; k <= max_n; ++k)  // Dann muss man hier nicht denken
            {
              unsigned wert = binomial(n,k);
              if (wert > 0) printf("%7u ", wert);
            }
          putchar('\n');
        }
    }
 
  return 0;
} 