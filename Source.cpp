#include<Servo.h>

//front right
#define motor1pin1 2
#define motor1pin2 3

//front left
#define motor2pin1 4
#define motor2pin2 5

//back left
#define motor3pin1 6
#define motor3pin2 7

//back right
#define motor4pin1 8
#define motor4pin2 9

#define rightIr 10
#define frontIr 11
#define leftIr 12

#define pump A2

#define test A1

int pos = 0;
bool fire = false;

Servo servo;

void setup() {
    // put your setup code here, to run once:

    Serial.begin(9600);

    pinMode(motor1pin1, OUTPUT);
    pinMode(motor1pin2, OUTPUT);
    pinMode(motor2pin1, OUTPUT);
    pinMode(motor2pin2, OUTPUT);
    pinMode(motor3pin1, OUTPUT);
    pinMode(motor3pin2, OUTPUT);
    pinMode(motor4pin1, OUTPUT);
    pinMode(motor4pin2, OUTPUT);

    pinMode(rightIr, INPUT);
    pinMode(leftIr, INPUT);
    pinMode(frontIr, INPUT);
    pinMode(pump, OUTPUT);

    servo.attach(A0);
    servo.write(90);
}

void put_off_fire()
{
    //delay(500);

    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    digitalWrite(motor3pin1, HIGH);
    digitalWrite(motor3pin2, LOW);
    digitalWrite(motor4pin1, LOW);
    digitalWrite(motor4pin2, HIGH);

    delay(800);

    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    digitalWrite(motor3pin1, LOW);
    digitalWrite(motor3pin2, LOW);
    digitalWrite(motor4pin1, LOW);
    digitalWrite(motor4pin2, LOW);

    digitalWrite(pump, LOW);
    digitalWrite(pump, HIGH);

    delay(500);

    for (pos = 50; pos <= 130; pos++)
    {
        servo.write(pos);
        delay(10);
    }

    for (pos = 130;pos >= 50;pos--)
    {
        servo.write(pos);
        delay(10);
    }
    if (!(digitalRead(rightIr)) && !(digitalRead(leftIr)) && !(digitalRead(frontIr)))
    {
        fire = false;
    }
    if (fire)
    {

        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, HIGH);
        digitalWrite(motor2pin1, HIGH);
        digitalWrite(motor2pin2, LOW);
        digitalWrite(motor3pin1, HIGH);
        digitalWrite(motor3pin2, LOW);
        digitalWrite(motor4pin1, LOW);
        digitalWrite(motor4pin2, HIGH);

        delay(800);

        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, LOW);
        digitalWrite(motor2pin1, LOW);
        digitalWrite(motor2pin2, LOW);
        digitalWrite(motor3pin1, LOW);
        digitalWrite(motor3pin2, LOW);
        digitalWrite(motor4pin1, LOW);
        digitalWrite(motor4pin2, LOW);

        digitalWrite(pump, LOW);
        digitalWrite(pump, HIGH);

        delay(500);

        for (pos = 30; pos <= 130; pos++)
        {
            servo.write(pos);
            delay(10);
        }

        for (pos = 130;pos >= 30;pos--)
        {
            servo.write(pos);
            delay(10);
        }
    }
    else            //  fire false  //
    {
        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, LOW);
        digitalWrite(motor2pin1, LOW);
        digitalWrite(motor2pin2, LOW);
        digitalWrite(motor3pin1, LOW);
        digitalWrite(motor3pin2, LOW);
        digitalWrite(motor4pin1, LOW);
        digitalWrite(motor4pin2, LOW);

        digitalWrite(pump, LOW);

        servo.write(90);
        fire = false;
    }
}



void loop() {
    // put your main code here, to run repeatedly:

    // done
    if (digitalRead(rightIr) && !(digitalRead(leftIr)) && !(digitalRead(frontIr)))
    {
        fire = true;
        Serial.println(analogRead(test));

    }
    //done
    else if (!(digitalRead(rightIr)) && digitalRead(leftIr) && !(digitalRead(frontIr)))
    {
        fire = true;
        Serial.println(analogRead(test));
    }
    //done
    else if (!(digitalRead(rightIr)) && (digitalRead(leftIr)) && (digitalRead(frontIr)))
    {
        fire = true;
        Serial.println(analogRead(test));
    }
    else if ((digitalRead(rightIr)) && !(digitalRead(leftIr)) && (digitalRead(frontIr)))
    {
        fire = true;
        Serial.println(analogRead(test));
    }
    else if ((digitalRead(rightIr)) && (digitalRead(leftIr)) && (digitalRead(frontIr)))
    {
        fire = true;
        Serial.println(analogRead(test));
    }
    else
    {
        digitalWrite(pump, LOW);
        servo.write(90);
        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, LOW);
        digitalWrite(motor2pin1, LOW);
        digitalWrite(motor2pin2, LOW);
        digitalWrite(motor3pin1, LOW);
        digitalWrite(motor3pin2, LOW);
        digitalWrite(motor4pin1, LOW);
        digitalWrite(motor4pin2, LOW);
        Serial.println("NO FIRE");
    }
    delay(250);
    while (fire)
    {
        put_off_fire();
    }
}