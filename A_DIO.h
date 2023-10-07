/*
 * DIO.h
 *
 *  Created on: Oct 7, 2023
 *  Author: Mina Adel Attia Labib
 *  Description: Header file of AUTOSAR Compatible DIO Driver.
 */

#ifndef A_DIO_H_
#define A_DIO_H_

/*Includes*/
#include <stdint.h>
#include "imported_data_types.h"
#include "tm4c123gh6pm.h"

/*Defines & Macros*/
#define STD_LOW     0
#define STD_HIGH    1

#define PORTA       0   /*IDs 0..7*/
#define PORTB       1   /*IDs 8..15*/
#define PORTC       2   /*IDs 16..23*/
#define PORTD       3   /*IDs 24..31*/
#define PORTE       4   /*IDs 32..39*/
#define PORTF       5   /*IDs 40..47*/
#define GET_BIT(REG,BIT)    ((REG >> BIT) & 1)
#define SET_BIT(REG,BIT)    (REG |=  (1 << BIT))
#define CLR_BIT(REG,BIT)    (REG &= ~(1 << BIT))
#define TGL_BIT(REG,BIT)    (REG ^=  (1 << BIT))

/*Functions Declaration*/

void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level);
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level);
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId);


#endif /* A_DIO_H_ */
