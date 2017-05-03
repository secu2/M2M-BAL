#include "mbed.h"
#include <stdio.h>
#include <string.h>
#include <inttypes.h>


Ticker toggle_led_ticker;

//------------------------------------
// Hyperterminal configuration
// 9600 bauds, 8-bit data, no parity
//------------------------------------
Serial pc(SERIAL_TX, SERIAL_RX);
DigitalOut led1(LED1);

#define TRIGGER_PIN    D6
#define ECHO_PIN       D7

DigitalOut trigger(TRIGGER_PIN);
DigitalIn echo(ECHO_PIN);

void toggle_led() {
    led1 = !led1;
}

int main() { 
    // Init the ticker with the address of the function (toggle_led) to be attached and the interval (100 ms)
    toggle_led_ticker.attach(&toggle_led, 0.1);
    
    while (true) {
        pc.printf("#1 Set trigger = 1\n");
        trigger = 1;
        
        pc.printf("#2 Wait 1sec\n");
        wait(1);
        
        pc.printf("#3 Set trigger = 0\n");
        trigger = 0;
 
        pc.printf("#4 Read echo: %d\n", echo);
        wait(2);
    }
}