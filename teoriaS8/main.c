/* Comment/Un-comment the following code to find out:
 * 
 * What variable allocations break the compiler?
 * How does the size of your program increase when doing different declarations?
 * What happens to const variables?
 * 
 * /

*/
// This works all the way
char buffer_gob[450] = {0,0,0,0};



//static char buffer_gob2[450] = {0,0,0,0};

/*
char func1(void){
    // This does not work.
    //char mome[83] = {0,1,1,1};
    
    static char mome[128] = {0,1,1,1};
    return mome[1];
}*/

/*
char func2(void){
    char var = 0;
    return var + 'a' + 1;
}

char func3(void){
    return 'a' + 1;
}
*/


void main(void)
{
    // initialize the device
    // Nothing will work without this! but we don't need it!
    //SYSTEM_Initialize();
    
    // These consume twice as much as you expect.
    //char large_buffer[80] = {0,2,2,2};
    //volatile char buffer_vol[80] = {0,0,0,0};
    
    // This does not compile
    //char buffer2[81] = {0,0,0,0};
    // volatile char buffer_vol[81] = {0,0,0,0};

    // This will work... why?
    //static char buffer[128] = {0,0,0,0};
    
    // buffer[0] = func1() + func3() + func2();
    //buffer[0] = func3() + func2();
    
    // This goes into the program area.
    const char buffer_Const[1000] = {0,0,0,0};
    
}
/**
 End of File
*/