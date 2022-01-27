#include <avr/io.h>
#include "digital.h"
/*
function:digital_Out_init
usage: initialize digital pin as output
parameters: port (char)- desired port 0 :port B, 1:port C,
            2:port D. 
            pin(char)-desired pin for port
*/
extern void digital_out_init(char port , char pin  ){
if (port <=3 || pin<=7 ){
   if (port == 0){
        DDRB |= (1 << pin);}
    else if(port == 1){
        DDRC |= (1 << pin);}
    else{
        DDRD |= (1 << pin);}
} 
/*
function:digital_Out_set_hi
usage:set digital pin high
parameters: port (char)- desired port 0 :port B, 1:port C,
            2:port D. 
            pin (char)-desired pin for port
*/
}
extern void digital_out_set_hi(char port, char pin){
if (port <=3 || pin<=7 ){
    if (port == 0){
      PORTB |=  (1 << pinMask);}
    else if(port == 1){
        PORTC |= (1 << pin);}
    else{
        PORTD |= (1 << pin);}
} 
}
/*
function:digital_Out_set_low
usage:set digital pin low
parameters: port (char)- desired port 0 :port B, 1:port C,
            2:port D. 
            pin (char)-desired pin for port
*/
extern void digital_out_set_low(char port, char pin){
if (port <=3 || pin<=7 ){
    if (port == 0){
      PORTB &=  (1 << pin);}
    else if(port == 1){
        PORTC &= (1 << pin);}
    else{
        PORTD &= (1 << pin);}
} 
}
/*
function:digital_Out_toggle
usage:toggle digital output pin
parameters: port (char)- desired port 0 :port B, 1:port C,
            2:port D. 
            pin (char)-desired pin for port
*/
extern void digital_out_toggle(char port, char pin){
if (port <=3 || pin<=7 ){
    if (port == 0){
        PORTB ^=  (1 << pin);}
    else if(port == 1){
        PORTC ^= (1 << pin);}
    else{
        PORTD ^= (1 << pin);}
} 
}

extern void digital_in_init(char port, char pin , int pullUp){
    if (port <=3 || pin<=7 ){
        if (port == 0){
            DDRB &= ~(1 << pin);
                 if (pullUp){
                    PORTB |= (1 << pin);
                 }

        else if(port == 1){
            DDRC &= ~(1 << pin);
                if (pullUp){
                    PORTC |= (1 << pin);
                }
        else{
            DDRD &= ~(1 << pin);
                if (pullUp){
                    PORTD |= (1 << pin);
                }
               
        } 
    }
}
extern int digital_in_read(char port, char pin){
    if (port <=3 || pin<=7 ){
        if (port == 0){
            return PINDB & (1 << pin);}
        else if(port == 1){
            return PINDC & (1 << pin);}
        else{
            return PIND & (1 << pin);
        }
    } 
    return -1;
}