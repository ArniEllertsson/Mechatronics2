/*
Class that enables the user specfied pin "PinMask" on the digatal output port DDRB
Functions:
void set_hi(): sets the output bit high
void set_lo(): sets the output bit low
void toggle(): toggle the output bit
Initialize: object.init(uint8_t x)
*/
#include <Arduino.h>
class Digital_out{
#include <avr/io.h>

public:
    void Timer(int period_ms);
    void set_hi();
    void set_low();
    void toggle();
    void init(int period_ms, float duty_cycle);
     Digital_out(uint8_t pin);
    void change_dutycycle(float duty_cycle);
private:
    uint8_t pinMask;
    void init();
};

Digital_out::Digital_out(uint8_t pin){
    pinMask = pin;
    init();
}

void Digital_out::init(){
    //Initialize output register
    DDRB |= (1 << pinMask);
}
void Digital_out:: set_hi(){
    PORTB |=  (1 << pinMask);
}
void Digital_out::set_low(){
   PORTB &=  ~(1 << pinMask);
}
void Digital_out::toggle(){
    PORTB = PORTB ^ (1 << pinMask);
}

void Digital_out :: Timer(int period_ms){
    
    float prescaler = 1024.0;
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;
    // use the formula OCRA1 = fclock /(prescaler*ftarget) -1 
    OCR1A =  16000000/(prescaler*1000/period_ms)-1;//assign target count to compare register A
    Serial.println(OCR1A);
    TCCR1B |= (1<<WGM12);//clear the timer on compare match A
    TIMSK1 |= (1<<OCIE1A);//set interrup to ncompare match A
    TCCR1B |= (1<<CS12)|(1<<CS10);//set prescaler to 1024 and start the timer

    }

void Digital_out :: init(int period_ms, float duty_cycle){
    float prescaler = 1024.0;
        
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;
    // use the formula OCRA1 = fclock /(prescaler*ftarget) -1 
    OCR1A =  16000000/(prescaler*1000/period_ms)-1;//assign target count to compare register A
    OCR1B= OCR1A*duty_cycle;
    TCCR1B |= (1<<WGM12);//clear the timer on compare match A
    TIMSK1 |= (1<<OCIE1A);//set interrup to on compare match A
    TIMSK1 |= (1<<OCIE1B); //set interupt to on compare match B
    TCCR1B |= (1<<CS12)|(1<<CS10);//set prescaler to 1024 and start the timer

    }

void Digital_out :: change_dutycycle(float duty_cycle){
    OCR1B= OCR1A*duty_cycle;
}
