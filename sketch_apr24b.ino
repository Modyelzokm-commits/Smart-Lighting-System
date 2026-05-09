// LIBS
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// PIN CONFIGRATION
const int LDR_sensor = 8;         // connect LDR sensor  module to Arduino pin D8
const int infrared_sensor_1 = 9;  // connect IR sensor 1 module to Arduino pin D9
const int infrared_sensor_2 = 10; // connect IR sensor 2 module to Arduino pin D10
const int infrared_sensor_3 = 11; // connect IR sensor 3 module to Arduino pin D11

const int LED_1 = 3; // connect LED 1 to Arduino pin D3
const int LED_2 = 5; // connect LED 2 to Arduino pin D5
const int LED_3 = 6; // connect LED 3 to Arduino pin D6

// INTIATE I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    // INTIATE LIB
    Wire.begin();

    // LCD SETUP

    lcd.init();

    // Turn on the blacklight
    lcd.backlight();

    // Print a message to the LCD
    lcd.setCursor(0, 0); // Move cursor to character 0 on line 0
    lcd.print("Hello, World!");

    lcd.setCursor(0, 1); // Move cursor to character 0 on line 1
    lcd.print("I2C Is Working!");

    delay(2000);
    lcd.clear();

    // put your setup code here, to run once:
    Serial.begin(115200);             // Init Serial at 115200 Baud Rate.
    Serial.println("Serial Working"); // Test to check if serial is working or not

    // IR PIN MODE CONFG
    pinMode(infrared_sensor_1, INPUT); // IR Sensor 1 pin INPUT
    pinMode(infrared_sensor_2, INPUT); // IR Sensor 2 pin INPUT
    pinMode(infrared_sensor_3, INPUT); // IR Sensor 3 pin INPUT

    pinMode(LED_1, OUTPUT); // LED 1 pin OUTPUT
    pinMode(LED_2, OUTPUT); // LED 2 pin OUTPUT
    pinMode(LED_3, OUTPUT); // LED 3 pin OUTPUT
}

void loop()
{
    // put your main code here, to run repeatedly:
    // Example of updating data: A simple uptime counter
    /*lcd.setCursor(0, 0);
    lcd.print("System Uptime:");

    lcd.setCursor(0, 1);
    lcd.print(millis() / 1000);
    lcd.print(" Seconds");

    delay(500);*/

    // IR READED VALUES
    int IR_1_sensorStatus = digitalRead(infrared_sensor_1); // Set the GPIO as Input
    int IR_2_sensorStatus = digitalRead(infrared_sensor_2); // Set the GPIO as Input
    int IR_3_sensorStatus = digitalRead(infrared_sensor_3); // Set the GPIO as Input
    int LDR_sensorStatus  = digitalRead(LDR_sensor);         // Set the GPIO as Input

    if (LDR_sensorStatus == HIGH)
    {
        Serial.println("The light is NOT present");

        // IR_1_sensorStatus WORK
        if (IR_1_sensorStatus == 1) // Check if the pin high or not
        {
            // if the pin is high turn off the LED_1
            digitalWrite(LED_1, LOW); // LED LOW
            Serial.println("Motion Detected!");
            lcd.clear();
        }
        else
        {
            // else turn on the onboard LED
            digitalWrite(LED_1, HIGH);       // LED High
            Serial.println("Motion Ended!"); // print Motion Ended! on the serial monitor window
            lcd.setCursor(0, 0);
            lcd.print("led1:on");
        }

        // IR_2_sensorStatus WORK
        if (IR_2_sensorStatus == 1) // Check if the pin high or not
        {
            // if the pin is high turn off the LED_1
            digitalWrite(LED_2, LOW); // LED LOW
            Serial.println("Motion Detected!");
            lcd.clear();

        }
        else
        {
            // else turn on the onboard LED
            digitalWrite(LED_2, HIGH);       // LED High
            Serial.println("Motion Ended!"); // print Motion Ended! on the serial monitor window

            lcd.setCursor(0, 1);
            lcd.print("led2:on");
        }

        // IR_3_sensorStatus WORK
        if (IR_3_sensorStatus == 1) // Check if the pin high or not
        {
            // if the pin is high turn off the LED_1
            digitalWrite(LED_3, LOW); // LED LOW
            Serial.println("Motion Detected!");
            lcd.clear();
        }
        else
        {
            // else turn on the onboard LED
            digitalWrite(LED_3, HIGH);       // LED High
            Serial.println("Motion Ended!"); // print Motion Ended! on the serial monitor window
            lcd.setCursor(9 , 0);
            lcd.print("led3:on");
        }
    }

    else
    {
        // do nothing
        Serial.println("The light is present");
    }
}
