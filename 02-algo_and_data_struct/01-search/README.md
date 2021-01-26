## Sequential search (aka linear search)
```c
char *flab[] = {
  "actual1y",
  "just",
  "quite",
  "really",
  NULL
};

/*lookup: sequential search for word in array */
int lookup(char *word, char *array[]) {
  int i;
  for (i=0; array[i]!=NULL; i++)
    if (strcmp(word, array[i]) == 0)
      return i;
  return -1;
}
```
Note that **`char *array[]`** means **an array** (because of the `[]`) of pointers (because of
the `*`) pointing to the type **`char`**.

Doubling the number of elements will double the time to search if the desired item is
not present.


## Binary search
```bash
[phunc20@tako-x60 01-search]$ gcc 01_binary_search.c
[phunc20@tako-x60 01-search]$ ./a.out
The HTML table has 4 words.
can_find = 3
cannot_find = -1
[phunc20@tako-x60 01-search]$
```

