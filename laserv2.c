#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rp.h"


//Defining values to ensure slow start. 
const float onvalue[19]= {0, 0.1, 0.2, 0.3, 0.4, 0.5,
                          0.6, 0.7, 0.8, 0.9, 1.0, 1.1,
                          1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8};


int main (int argc, char *argv[]) 
{

// Initialization of API
if (rp_Init() != RP_OK) {
        fprintf(stderr, "Red Pitaya API init failed!\n");
        return EXIT_FAILURE;
}
if (strcmp(argv[1],"ON")==0){
        for (int i = 0; i<19; i++){
                int status= rp_AOpinSetValue(0,onvalue[i]);
                if (status !=RP_OK){
                        fprintf(stderr, "Error in controlling laser");
                }
        }
}

else if (strcmp(argv[1], "OFF")==0){
        int status= rp_AOpinSetValue(0,0);
        if (status !=RP_OK){
                fprintf(stderr, "Error in controlling laser");
        }

}
else {
        int status= rp_AOpinSetValue(0,0);
        if (status !=RP_OK){
                fprintf(stderr, "Error in controlling laser");
        }
}

    rp_Release();

    return EXIT_SUCCESS;
}
