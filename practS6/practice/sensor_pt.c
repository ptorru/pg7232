#include <stdint.h>
#include "sensor_pt.h"
#include "mcc_generated_files/mcc.h"


int myPedroOpen(){
    printf("Main Open called!\n");
    printf("Wanna do some moorooororoeeee opening here!\n");
    return 0;
}

int myPedroGet(){
    return 0xAA;
}

void myPedroClose(){
    printf("All done here from this Pedro function!\n");
}