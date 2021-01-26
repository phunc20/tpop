#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NELEMS(array) (sizeof(array) / sizeof(array[0]))

typedef struct Nameval Nameval;
struct Nameval {
  char *name;
  int value;
};

/* HTML characters, e.g. AElig is ligature of A and E. */
/* Values are Unicode/ISO10646 encoding. */
Nameval htmlchars[] = {
  "AElig",  0x00c6,
  "Aacute", 0x00c1,
  "Acirc",  0x00c2,
  /* ... */
  "zeta",   0x03b6,
};

/* lookup: binary search for name in tab; return index */
int lookup(char *name, Nameval tab[], int ntab) {
  int low, high, mid, cmp;
  low = 0;
  high = ntab - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    cmp = strcmp(name, tab[mid].name);
    if (cmp < 0)
      high = mid - 1;
    else if (cmp > 0)
      low = mid + 1;
    else
      return mid;
  }
  return -1; /* no match */
}


int main(int argc, char **argv) {
  printf("The HTML table has %d words.\n", NELEMS(htmlchars));
  int can_find, cannot_find;
  can_find = lookup("zeta", htmlchars, NELEMS(htmlchars));
  cannot_find = lookup("frac12", htmlchars, NELEMS(htmlchars));
  printf("can_find = %d\n", can_find);
  printf("cannot_find = %d\n", cannot_find);
  return 0;
}
