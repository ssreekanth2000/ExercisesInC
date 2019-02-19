#include <stdio.h>
#include <stdlib.h> // For exit()

int main(int argc, char * argv[])
{
	FILE *fptr1, *fptr2;
  if (argc < 2) {
    printf("too few arguments\n" );

    exit(1);
    /* code */
  }

  char c;
	//printf("Enter the filename to open for reading \n");

  char * filename=argv[1];
  //printf("%s\n",filename );
	// Open one file for reading
	fptr1 = fopen(filename, "r");
	if (fptr1 == NULL)
	{
		printf("Cannot open file %s \n", filename);
		exit(0);
	}

	//printf("Enter the filename to open for writing \n");

  filename=argv[2];

	// Open another file for writing
	fptr2 = fopen(filename, "w");
	if (fptr2 == NULL)
	{
		printf("Cannot open file %s \n", filename);
		exit(0);
	}

	// Read contents from file
	c = fgetc(fptr1);
	while (c != EOF)
	{
		fputc(c, fptr2);
		c = fgetc(fptr1);
	}

	//printf("\nContents copied to %s", filename);

	fclose(fptr1);
	fclose(fptr2);
	return 0;
}
//3. For me braking the problem down into 4 seperate parts of opening a file,
//reading a file, writing to a files and then closing a file.   I turned to
//google and stack overflow for help. I had to figure out the various
//functions i needed and how to read arguments from the command line. Sometimes
// searched for multiple parts at once, which only complicated things, i would
// have been faster if I focuseed on understanding and building the 4 functions
// seperatly,


/*
5. The professional implementation used a lot more .h files for more specialized
functions and is probably faster and more efficient. It also checks for more
kinds of errors.
*/
