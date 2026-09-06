#ifndef IMAGE_BATCH_H
#define IMAGE_BATCH_H

typedef struct _training_batch {

    // we need # of images 
    // the pointer to the path 
    // what else???

    // num of images per batch
    int num_of_images; 

    // the paths of said images in order to train
    char ** image_paths; 

    // ground truth 
    int * labels; 

} training_batch; 

// a struct of training_batches = dataset 
typedef struct _training_dataset {

    int num_batches; 
    training_batch ** batches; 

} training_dataset; 

#endif