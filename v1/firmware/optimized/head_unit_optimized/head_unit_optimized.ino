// SkyEye V1 head unit - optimized version.
//
// !!! UNVERIFIED: this sketch has NOT been compiled, uploaded or tested on hardware. !!!
// See ../README.md before use. The original sketch is ../../head_unit/head_unit.ino.
//
// Hardware and wire format are unchanged from the original:
//   MPU6050 on I2C, HC-05 on the hardware Serial port at 9600 baud.
//   One byte per sample: (angle + 90) clamped to 0..180,
//   pitch (MPU Y axis) forced to an even value, yaw (MPU Z axis) forced to an odd value.
//   Pitch and yaw bytes alternate, one byte every 8 ms.

#include <Wire.h>
#include <MPU6050_light.h>

const long SERIAL_BAUD = 9600;
const unsigned long SEND_INTERVAL_MS = 8;  // same pacing as the original delay(8)
const int ANGLE_OFFSET = 90;
const int ENCODED_MIN = 0;
const int ENCODED_MAX = 180;
const int UNUSED_PPM_PIN = 2;  // PPM output was disabled on the head unit; pin kept as in the original

MPU6050 mpu(Wire);
unsigned long lastSendMs = 0;
bool sendPitchNext = true;

// Shift the angle into 0..180 and clamp it so it always fits in one byte.
int encodeAngle(float angle) {
  return constrain((int)(angle + ANGLE_OFFSET), ENCODED_MIN, ENCODED_MAX);
}

// Pitch is always sent as an even byte (0..180).
uint8_t encodePitch(float angle) {
  int value = encodeAngle(angle);
  if (value % 2 != 0) {
    value += 1;
  }
  return (uint8_t)value;
}

// Yaw is always sent as an odd byte (1..181).
uint8_t encodeYaw(float angle) {
  int value = encodeAngle(angle);
  if (value % 2 == 0) {
    value += 1;
  }
  return (uint8_t)value;
}

void setup() {
  Serial.begin(SERIAL_BAUD);
  Wire.begin();
  while (mpu.begin() != 0) {
    // Wait until the MPU6050 responds.
  }
  delay(100);
  mpu.calcOffsets();  // keep the head unit still during calibration
  delay(500);
  pinMode(UNUSED_PPM_PIN, OUTPUT);
}

void loop() {
  // Update the sensor fusion on every pass (not only every 16 ms) for better angle accuracy.
  mpu.update();

  unsigned long now = millis();
  if (now - lastSendMs < SEND_INTERVAL_MS) {
    return;
  }
  lastSendMs = now;

  if (sendPitchNext) {
    Serial.write(encodePitch(mpu.getAngleY()));
  } else {
    Serial.write(encodeYaw(mpu.getAngleZ()));
  }
  sendPitchNext = !sendPitchNext;
}
