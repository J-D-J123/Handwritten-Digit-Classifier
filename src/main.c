/**
 * Author:          Joseph Johnson 
 * Date:            06/09/2026
 * File:            starts the neural network and sets it up from the first layer
 *                      then sends data through the network to determine what image it is
 */


#include <stdio.h> 
#include <stdlib.h> 

#include "../structs/png.h"
#include "../structs/network.h"

// void network_testing() {

//     // first step is to setup the network ammount of layers neurons etc... 
//     int neurons_per_layer[4] = {784, 256, 128, 10};
//     int number_of_layers = 4; 

//     int number_of_biases = 0; 

//     Network network = setup_network(neurons_per_layer, number_of_layers);

//     printf("setup_network is completed...\n");

//     printf("=== Network num_layers = %d===\n\n", network.num_layers);

//     for (int i = 0; i < number_of_layers; i++) {

//         printf("Layer %d = %d neurons. ", i, network.layers[i].num_neurons); 

//         // randomly loop through biases to make sure they exist correctly... 
//         // this is going to be alot of text in the terminal 
//         for (int h = 0; h < network.layers[i].num_neurons; h++) {

//             number_of_biases += 1; 
//             printf("%f, ", network.layers[i].neurons[h].bias);
//         }
//         printf("\n\n");

//     }

//     printf("=== Number of Biases = %d ===\n", number_of_biases);
// }

// first get each pixel and put it into a row & colummn and take each pixel and put into each neruon 
int main() {

    // was just testing & messing around
    // read the png image first 28 * 28 pixels    
    // png image = get_png_info("0_1.png");
    // PixelGrey * pixels_greyscale = pixels_in_png_to_array(&image, "0_1.png"); 

    // print_png_data(image, pixels_greyscale); 

    // setup network
    int neurons_per_layer[4] = {784, 256, 128, 10};
    int number_of_layers = 4; 

    double learning_rate = 0.001; 

    Network network = setup_network(neurons_per_layer, number_of_layers);

    // now train network on batches of input_pngs
    network = train_network(network, input_png_batch, number_of_pngs, learning_rate); 

    return 0;     
}