/* 
 * File:   sensor.h
 * Author: M†ˆ—‰—pŒ¤‹†º
 *
 * Created on 2012/08/23, 19:53
 */

#ifndef SENSOR_H
#define	SENSOR_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define     CW      1
#define     CCW     2

/* timer0 */
//#define     SEC_MAX     38

void sensor_init( void );
void timer0_init( void );
char check_Rotary( void );
short check_Tempture( void );

#ifdef	__cplusplus
}
#endif

#endif	/* SENSOR_H */

