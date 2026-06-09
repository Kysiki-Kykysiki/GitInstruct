#include <Arduino.h>
#include "temperature.h"
#include "button.h"
#include "photoresistor.h"
#include "led.h"

const int TEMP_PIN = A0;
const int PHOTO_PIN = A1;
const int LED_PIN = 13;
const int BUTTON_PIN = 8;


temperature t1(TEMP_PIN);
button b1(BUTTON_PIN);
photoresistor p1(PHOTO_PIN)
led l(LED_PIN);

void setup() {
    Serial.begin(9600);
}

void loop() {
    b1.update();
    l.update();
    p_data = p1.photoresistor_read_raw();
    t_data = t1.temperature_read_celsius();
    if(b1.get_pressCount() % 2 == 0){
        Serial.print("Температура: ");
        Serial.println(t_data);
        if(t1.temperature_is_hot()) l.blink();
    }
    else {
        Serial.print("Освещение: ");
        Serial.println(p_data);
        if(p1.photoresistor_is_dark()) l.on();
    }
}
