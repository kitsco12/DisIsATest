#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayAndSortContent (char *file);
void swapNumbers(int i, int j, int array[100]);
void bubbleSort(int array[100]);

int main()
{
   char file_name[640];

 
   printf("Enter one of the following files that you wish to use:\n" 
   	"1.txt\n" 
   	"2.txt\n" 
   	"3.txt\n" 
   	"4.txt\n" 
   	"\n");
   scanf("%63s", file_name); 

   printf("The contents of file %s bofore sorting are :\n\n", file_name);
   displayAndSortContent(file_name);  

   return 0;
}

void displayAndSortContent (char *file){
	FILE *fp;
    int i = 0;
    int numbersInFileToArray[100];
    int value;
	
	fp = fopen (file, "r"); 
 
    if(!fp)
    {
         printf("Can't open %s for reading / sorting.. \n", file);
         exit(0);
      //perror("Error while opening the file.\n");
         //exit(EXIT_FAILURE);
    }
    if (feof(fp))
    {
         printf("\n\n Ops.. ran out of data. \n");
         exit(0);
    }

    fscanf (fp, "%d", &i);
    

   while (!feof (fp))
   {   		
 		fscanf (fp, "%d", &i);
 		printf("%i ", i);
 		value = numbersInFileToArray[i];
 		bubbleSort(value);

   }

   fclose (fp);

}
void swapNumbers(int i, int j, int array[100]){
	int temp;
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
void bubbleSort(int array[100]){
	int i, k, m;
	int n = sizeof(array[100]);

	for (m = n; m >= 0; --m){
		for (i = 0; i < n - 1; ++i){
			k = i + 1;
			if(array[i] > array[k]){
				swapNumbers(i, k, array);
			}
		}


	}
	


}








