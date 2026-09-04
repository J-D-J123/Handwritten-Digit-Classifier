#ifndef IMAGE_BATCH_H
#define IMAGE_BATCH_H

typedef struct _training_batch {

    // we need # of images 
    // the pointer to the path 
    // what else???

    int num_of_images; 
    char ** image_paths; 

    struct _training_batch * array_of_training_batches;  

} training_batch; 

#endif