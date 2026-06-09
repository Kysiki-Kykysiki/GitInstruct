#include <Arduino.h>
#include "Temperature.h"
#include "button.h"
#include "Photoresistor.h"
#include "led.h"

const int TEMP_PIN = A0;
const int PHOTO_PIN = A1;
const int LED_PIN = 13;
const int BUTTON_PIN = 8;


Temperature t1(TEMP_PIN,LED_PIN, 35.5);
Button b1(BUTTON_PIN);
Photoresistor p1(PHOTO_PIN,LED_PIN,500);
Led l(LED_PIN);

void setup() {
    Serial.begin(9600);
}

void loop() {
    b1.update();
    l.update();
    int p_data = p1.photoresistor_read_raw();
    float t_data = t1.temperature_read_celsius();
    if(b1.get_pressCount() % 2 == 0){
        Serial.print("Температура: ");
        Serial.println(t_data);
        if(t1.temperature_is_hot()) Serial.println("Hot");
    }
    else {
        Serial.print("Освещение: ");
        Serial.println(p_data);
        if(p1.photoresistor_is_dark()) Serial.println("Dark");
    }
}
