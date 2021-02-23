/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1717
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include <stdint.h>
#include "mcc_generated_files/mcc.h"
#include "sensor_gn.h"
#include "sensor_dn.h"
#include "sensor_ac.h"
/*
                         Main application
 */

#define SENSORS 4

#define SENPTID 0
#define SENGNID 1
#define SENDNID 2
#define SENACID 3


#define REGISTER(iopen, iget, iclose, id, control) \
  control[id].open = iopen;                        \
  control[id].get = iget;                          \
  control[id].close = iclose;

typedef struct sensor_ctrl_s
{
  int (*open)(void);
  int (*get)(void);
  void (*close)(void);
} sensor_ctrl_t;

int myopen()
{
  printf("Main Open called!\n");
  return 0;
}

int myget()
{
  return 42;
}

void myclose()
{
  printf("All done here!\n");
}

void main(void)
{
  sensor_ctrl_t all_sensors[SENSORS];

  // initialize the device
  SYSTEM_Initialize();

  INTERRUPT_GlobalInterruptEnable();
  INTERRUPT_PeripheralInterruptEnable();

  EUSART_Initialize();

  printf("Hello World\r\n");
  REGISTER(&myopen, &myget, &myclose, SENPTID, all_sensors);
  REGISTER(&myopen_gn, &myget_gn, &myclose_gn, SENGNID, all_sensors);
  REGISTER(&myopen_dn, &myget_dn, &myclose_dn, SENDNID, all_sensors);
  REGISTER(&myopen_ac, &myget_ac, &myclose_ac, SENACID, all_sensors);

  for (int i = 0; i < SENSORS; i++)
  {
    all_sensors[i].open();
  }

  while (1)
  {
    printf("New values: ");
    for (int i = 0; i < SENSORS; i++)
    {
      printf("%d", all_sensors[i].get());
      if (i != (SENSORS - 1))
        printf(",");
    }
    printf("\n");
  }
}
/**
 End of File
*/
