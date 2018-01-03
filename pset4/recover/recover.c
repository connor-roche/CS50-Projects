/**
 * Recovers JPEG images in card.raw
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>
 #include <stdint.h>
 
typedef uint8_t BYTE;
 
 bool JPEGtest(BYTE buffer[]);
 
 int main(int argc, char *argv[])
 {
     //ensure proper usage
     if (argc != 2)
     {
         fprintf(stderr, "Usage: ./recover image");
         return 1;
     }
     
     //remember file name
     char *infile = argv[1];
     
     //open input file
     FILE *inptr = fopen(infile, "r");
     if (inptr == NULL)
     {
         fprintf(stderr, "Could not open %s \n", infile);
         return 2;
     }
     // counter is to name jpgs
     int counter = 0;
     
     //a block of bytes to represent data
     BYTE buffer[512];
     
     //stores name of jpeg
     char name[8];
     
     //finds jpg and creates files
     while(fread(buffer, sizeof(buffer), 1, inptr) != 0)
     {
         while(JPEGtest(buffer))
         {
             //creates and name jpg
             sprintf(name, "%03i.jpg", counter);
             FILE *outptr = fopen(name, "w");
             
             //write out header to out
             fwrite(buffer, sizeof(BYTE), 512, outptr);
             
             //checks to see if there is a file
             if(outptr == NULL)
             {
                 fprintf(stderr, "Could not make jpeg  \n");
                 return 3;
             }
             
             //checks for eof
             if(fread(buffer, sizeof(buffer), 1, inptr) == 0)
             {
                 break;
             }
             
             //writes new jpg to file
             while(!JPEGtest(buffer))
             {
                 //write block while checking for eof
                 fwrite(buffer, sizeof(BYTE), 512, outptr);
                 
                 if(fread(buffer, sizeof(buffer), 1, inptr) == 0)
                 {
                    break;
                 }
             }
           fclose(outptr);
           counter++;
         }
     }
     //close file pointer
     fclose(inptr);
 }
 
 //checks to see if new jpeg
 bool JPEGtest(BYTE buffer[])
 {
     if (buffer[0] == 0xff &&
         buffer[1] == 0xd8 &&
         buffer[2] == 0xff &&
         (buffer[3] & 0xf0) == 0xe0)
     {
         return true;
     }
     else
     return false;
 }