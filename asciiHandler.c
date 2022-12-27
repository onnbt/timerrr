#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCIIPATH "ascii_numbers.txt"

#define PRINTABLES_COUNT 10
#define LINES_PER_PRINTABLE 11

typedef struct Printable
{
   char *lines[LINES_PER_PRINTABLE];
} Printable;

struct Printable printables[PRINTABLES_COUNT];

/* Load printable ascii numbers from text file to global arr printables */
int loadPrintables()
{
   FILE *fp;
   char *line = NULL;
   size_t len = 0;
   ssize_t read;
   int lineCount = 0;
   int number = 0;

   Printable *printable = malloc(sizeof(*printable));

   fp = fopen(ASCIIPATH, "r");
   if (fp == NULL)
      return -1;

   while ((read = getline(&line, &len, fp)) != -1)
   {

      if (lineCount == 11)
      {
         printables[number] = *printable;
         lineCount = 0;
         number++;
      }
      line[strcspn(line, "\n")] = 0;
      printable->lines[lineCount] = malloc(sizeof(*line));
      strcpy(printable->lines[lineCount], line);
      lineCount++;
   }

   fclose(fp);
   if (line)
      free(line);
   return 1;
}

/* Print the ascii numbers  to terminal*/
void print(int8_t first, int8_t second)
{
   for (int i = 0; i < LINES_PER_PRINTABLE; i++)
   {
      printf("%s\n", printables[9].lines[i]);
   }
}