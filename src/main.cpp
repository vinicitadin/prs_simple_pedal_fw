#include <Arduino.h>
#include <HX711.h>
#include <USBComposite.h>
#include "project_name_config.h"

// Criando a HID e os pedais
USBHID HID;
HIDJoystick simplePedal(HID);

// Criando os módulos HX711
HX711 acceleratorSensor;
HX711 brakeSensor;
HX711 clutchSensor;

void setup() {
  Serial.begin(9600);
  HID.begin();
  while(!USBComposite);

  // Inicializando os sensores das células de carga
  acceleratorSensor.begin(DAT1, CLK1);
  acceleratorSensor.set_scale(CALIB_VALUE);
  acceleratorSensor.tare();

  brakeSensor.begin(DAT2, CLK2);
  brakeSensor.set_scale(CALIB_VALUE);
  brakeSensor.tare();

  clutchSensor.begin(DAT3, CLK3);
  clutchSensor.set_scale(CALIB_VALUE);
  clutchSensor.tare();
}

void loop() {

// Retornando os valores obtidos nas células de carga como valores de um joystick oscilando nos eixos X e Y 
  float acceleratorValue = acceleratorSensor.get_units();
  float brakeValue = brakeSensor.get_units();
  float clutchValue = clutchSensor.get_units();

  int accelerator = map(acceleratorValue, 0, CALIB_MIN, 0, CALIB_MAX) - 0;
  int brake = map(brakeValue, 0, CALIB_MIN, 0, CALIB_MAX) - 0;
  int clutch = map(clutchValue, 0, CALIB_MIN, 0, CALIB_MAX) - 0;

  simplePedal.Y(accelerator * CALIB_MULT);
  simplePedal.X(brake * CALIB_MULT);
  simplePedal.Xrotate(clutch * CALIB_MULT);

  delay(10);
}


