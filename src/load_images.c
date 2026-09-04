/**
* Author:   Joey Johnson
* Date:     9/3/2026
*
* Desc: load_images.c loads in training PNG 
*    images in sets and returns a training_batch struct  
*   
*/

#include <stdio.h> 
#include <errno.h>
#include <dirent.h> 
#include <stdlib.h> 
#include <string.h> 

void enumerate_files(const char * dir);

#define NUM_DIGITS 10

int main() {

    enumerate_files("../AI/png_images/");

    return 0; 
}

// figure out how many images there is in the folder... 
// Let's assume it is something like this ** where ** is of type num
// so in order to numerate through 
// we are given a dir as a param so use that and then count each
// file and figure out how they differ by num[s]
void enumerate_files(const char * path) {

    DIR * dir; 
    struct dirent * entry; 
    int count = 0; 


    if(path == NULL) {
        printf("Nothing was found\n");
        return; 

    } else {

        // dir is not NULL so let's loop through it now 
        // count how many files it has... 
        // open the dir 
        DIR * dir; 
        dir = opendir(path); 

        int digit_counts[NUM_DIGITS] = {0}; 

        if(dir == NULL) {

            printf("Directory is NULL\n");
            perror(path);
            fprintf(stderr, "Attempted path: '%s'\n", path); 
            return; 
        }

        // read and count each entry 
        while ((entry = readdir(dir)) != NULL) {

            // also count the URL of the file type 
            // ex. 0_1.png - 0_75.png - 4_29779.png etc... just the #
            int digit; 
            int image_number; 

            char * filename = entry->d_name; 

            if(strcmp(filename, ".") == 0 || 
                strcmp(filename, "..") == 0) {
                    continue; 
                }

            if(sscanf(filename, "%d_%d.png", &digit, &image_number) != 2) {

                printf("Skipping unexpected filename: %s\n", filename);
                continue; 
            }

            digit_counts[digit]++;
            count++;
        }

        // close the dir 
        closedir(dir); 
        printf("Total files counted: %d\n", count); 

        printf("Number of images per digit\n");
        for(int i = 0; i < NUM_DIGITS; i++) {
            printf("%d: %d images\n", i, digit_counts[i]); 
        }
    }
}

