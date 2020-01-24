/* 
 * File:   buzzer.h
 * Author: Tomoaki Kimuraè
 *
 * Created on 2012/11/22, 11:52
 */

#ifndef BUZZER_H
#define	BUZZER_H

#ifdef	__cplusplus
extern "C" {
#endif
    #define     SOUND_ON    1
    #define     SOUND_OFF   0

    void buzzer_init( void );
    void buzzer( char sound );
#ifdef	__cplusplus
}
#endif

#endif	/* BUZZER_H */

