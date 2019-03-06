/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


typedef struct {
    regex_t inner_struct[1];
} Regex;
/* Returns a new Regex that matches the given pattern.
*
* pattern:string regex
* flags: flags passed to regcomp
* returns: new Regex
*/
Regex *make_regex(char *pattern, int flags) {
    Regex *re = malloc(sizeof(Regex));
    int r = regcomp(re->inner_struct,pattern,flags);
    if (r){
      fprintf(stderr, "could not compile\n");
      exit(1);
    }
    return re;
}

/* Checks whether a regex matches a string.
*
* regex: Regex pointer
* s: string
* returns: 1 if there's a match, 0 otherwise
*/
int regex_match(Regex *regex, char *s) {
  int r = regexec(regex->inner_struct,s,0,NULL,0);
  if(r && r != REG_NOMATCH){
    fprintf(stderr, "%regex err\n" );
    exit(1);
  }

  return !r;
}

/* Frees a Regex.
*
* regex: Regex pointer
*/
void regex_free(Regex *regex) {
    regfree(regex->inner_struct);
    free(regex);
}


/* Finds all tracks that match the given pattern.
*
* Prints track number and title.
*/
void find_track_regex(char pattern[])
{
    int i;

    Regex *regex = make_regex(pattern, REG_EXTENDED | REG_NOSUB);

    for (i=0; i<NUM_TRACKS; i++) {
        if (regex_match(regex, tracks[i])) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }

    regex_free(regex);
}


int main (int argc, char *argv[])
{
    char *pattern = "F.*F.*";
    find_track_regex(pattern);

    return 0;
}
