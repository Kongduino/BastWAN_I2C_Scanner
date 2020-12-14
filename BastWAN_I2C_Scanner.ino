#include "Arduino.h"
#include "Wire.h"

void setup() {
  delay(2500);
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n\nI2C Scanner...");
  //Wire.begin(SDA_OLED, SCL_OLED); //Scan OLED's I2C addr via I2C0
  Wire.begin(SDA, SCL); //If there have other device on I2C1, scan the device addr via I2C1
  Wire.setClock(100000);
}

char result[128];

char* getDef(uint8_t x) {
  switch (x) {
    case (0x00):
      return "reserved";
      break;
    case (0x01):
      return "reserved";
      break;
    case (0x02):
      return "reserved";
      break;
    case (0x03):
      return "reserved";
      break;
    case (0x04):
      return "reserved";
      break;
    case (0x05):
      return "reserved";
      break;
    case (0x06):
      return "reserved";
      break;
    case (0x07):
      return "reserved";
      break;
    case (0x0c):
      return "AK8975";
      break;
    case (0x0d):
      return "AK8975";
      break;
    case (0x0e):
      return "MAG3110, AK8975, IST-8310";
      break;
    case (0x0f):
      return "AK8975";
      break;
    case (0x10):
      return "VEML7700, VML6075";
      break;
    case (0x11):
      return "Si4713, SAA5246, SAA5243P/K, SAA5243P/L, SAA5243P/E, SAA5243P/H";
      break;
    case (0x13):
      return "VCNL40x0";
      break;
    case (0x18):
      return "MCP9808, LIS3DH, LSM303";
      break;
    case (0x19):
      return "MCP9808, LIS3DH, LSM303";
      break;
    case (0x1a):
      return "MCP9808";
      break;
    case (0x1b):
      return "MCP9808";
      break;
    case (0x1c):
      return "MCP9808, MMA845x, FXOS8700";
      break;
    case (0x1d):
      return "MCP9808, MMA845x, ADXL345, FXOS8700";
      break;
    case (0x1e):
      return "HMC5883, LSM303, MCP9808, LSM303, FXOS8700";
      break;
    case (0x1f):
      return "MCP9808, FXOS8700";
      break;
    case (0x20):
      return "MCP23008, MA12070P, MCP23017, Chirp!, FXAS21002";
      break;
    case (0x21):
      return "FXAS21002, MCP23008, MCP23017, SAA4700, MA12070P";
      break;
    case (0x22):
      return "MCP23008, MCP23017, PCA1070, MA12070P";
      break;
    case (0x23):
      return "MCP23008, MCP23017, SAA4700, MA12070P";
      break;
    case (0x24):
      return "MCP23008, PCD3312C, MCP23017, PCD3311C";
      break;
    case (0x25):
      return "MCP23008, PCD3312C, MCP23017, PCD3311C";
      break;
    case (0x26):
      return "MCP23008, MCP23017";
      break;
    case (0x27):
      return "MCP23008, MCP23017";
      break;
    case (0x28):
      return "BNO055, CAP1188";
      break;
    case (0x29):
      return "VL53L0x, BNO055, VL6180X, CAP1188, TCS34725, TSL2591";
      break;
    case (0x2a):
      return "CAP1188";
      break;
    case (0x2b):
      return "CAP1188";
      break;
    case (0x2c):
      return "CAP1188, AD5248, AD5251, AD5252, CAT5171";
      break;
    case (0x2d):
      return "CAP1188, AD5248, AD5251, AD5252, CAT5171";
      break;
    case (0x2e):
      return "AD5248, AD5251, AD5252, LPS22HB";
      break;
    case (0x2f):
      return "AD5248, AD5243, AD5251, AD5252";
      break;
    case (0x30):
      return "SAA2502";
      break;
    case (0x31):
      return "SAA2502";
      break;
    case (0x38):
      return "FT6x06, VEML6070, BMA150, SAA1064";
      break;
    case (0x39):
      return "TSL2561, APDS-9960, VEML6070, SAA1064";
      break;
    case (0x3a):
      return "PCF8577C, SAA1064";
      break;
    case (0x3b):
      return "SAA1064, PCF8569";
      break;
    case (0x3c):
      return "SSD1305, SSD1306, PCF8578, PCF8569, SH1106";
      break;
    case (0x3d):
      return "SSD1305, SSD1306, PCF8578, SH1106";
      break;
    case (0x40):
      return "Si7021, HTU21D-F, TMP007, TMP006, PCA9685, INA219, TEA6330, TEA6300, TDA9860, TEA6320, TDA8421, NE5751, INA260, PCF8574";
      break;
    case (0x41):
      return "TMP007, PCF8574, NE5751, TDA8421, TDA8424, STMPE610, STMPE811, INA260, TDA8425, TMP006, TDA9860, INA219, PCA9685, TDA8426";
      break;
    case (0x42):
      return "TMP007, HDC1008, PCF8574, TDA8417, INA260, TDA8415, TMP006, INA219, PCA9685";
      break;
    case (0x43):
      return "TMP007, HDC1008, PCF8574, INA260, TMP006, INA219, PCA9685";
      break;
    case (0x44):
      return "TMP007, TMP006, PCA9685, INA219, STMPE610, SHT31, ISL29125, STMPE811, TDA4688, TDA4672, TDA4780, TDA4670, TDA8442, TDA4687, TDA4671, TDA4680, INA260, PCF8574";
      break;
    case (0x45):
      return "TMP007, TDA7433, PCF8574, TDA8376, INA260, TMP006, INA219, PCA9685, SHT31";
      break;
    case (0x46):
      return "TMP007, PCF8574, TDA8370, INA260, TMP006, INA219, PCA9685, TDA9150";
      break;
    case (0x47):
      return "TMP007, PCF8574, INA260, TMP006, INA219, PCA9685";
      break;
    case (0x48):
      return "PCA9685, INA219, PN532, TMP102, INA260, ADS1115, PCF8574";
      break;
    case (0x49):
      return "TSL2561, PCA9685, INA219, TMP102, INA260, ADS1115, AS7262, PCF8574";
      break;
    case (0x4a):
      return "PCF8574, ADS1115, INA260, INA219, PCA9685, MAX44009, TMP102";
      break;
    case (0x4b):
      return "PCF8574, ADS1115, INA260, INA219, PCA9685, MAX44009, TMP102";
      break;
    case (0x4c):
      return "PCA9685, INA219, INA260, PCF8574";
      break;
    case (0x4d):
      return "PCA9685, INA219, INA260, PCF8574";
      break;
    case (0x4e):
      return "PCA9685, INA219, INA260, PCF8574";
      break;
    case (0x4f):
      return "PCA9685, INA219, INA260, PCF8574";
      break;
    case (0x50):
      return "PCA9685, MB85RC";
      break;
    case (0x51):
      return "PCA9685, MB85RC";
      break;
    case (0x52):
      return "PCA9685, MB85RC, Nunchuck, controller, APDS-9250";
      break;
    case (0x53):
      return "ADXL345, PCA9685, MB85RC";
      break;
    case (0x54):
      return "PCA9685, MB85RC";
      break;
    case (0x55):
      return "PCA9685, MB85RC, MAX30101";
      break;
    case (0x56):
      return "PCA9685, MB85RC";
      break;
    case (0x57):
      return "PCA9685, MB85RC, MAX3010x";
      break;
    case (0x58):
      return "PCA9685, TPA2016, SGP30";
      break;
    case (0x59):
      return "PCA9685, ATCC608A";
      break;
    case (0x5a):
      return "MPR121, MLX90614, CCS811, PCA9685, DRV2605";
      break;
    case (0x5b):
      return "PCA9685, CCS811, MPR121";
      break;
    case (0x5c):
      return "PCA9685, AM2315, MPR121";
      break;
    case (0x5d):
      return "PCA9685, MPR121";
      break;
    case (0x5e):
      return "PCA9685";
      break;
    case (0x5f):
      return "PCA9685, HTS221";
      break;
    case (0x60):
      return "ATECC608A, MPL3115A2, ATECC508A, MCP4725A0, TSA5511, Si5351A, SAB3035, MPL115A2, SAB3037, MCP4725A1, PCA9685, TEA5767, Si1145";
      break;
    case (0x61):
      return "MCP4725A0, TSA5511, Si5351A, SAB3035, SAB3037, TEA6100, MCP4725A1, PCA9685";
      break;
    case (0x62):
      return "TSA5511, UMA1014T, SAB3035, SAB3037, MCP4725A1, PCA9685";
      break;
    case (0x63):
      return "TSA5511, UMA1014T, SAB3035, Si4713, SAB3037, MCP4725A1, PCA9685";
      break;
    case (0x64):
      return "PCA9685, MCP4725A2, MCP4725A1";
      break;
    case (0x65):
      return "PCA9685, MCP4725A2, MCP4725A1";
      break;
    case (0x66):
      return "PCA9685, MCP4725A3, IS31FL3731, MCP4725A1";
      break;
    case (0x67):
      return "PCA9685, MCP4725A3, MCP4725A1";
      break;
    case (0x68):
      return "MPU-9250, ICM-20948, MPU6050, DS3231, PCA9685, PCF8523, PCF8573, DS1307, AMG8833, ITG3200";
      break;
    case (0x69):
      return "MPU-9250, ICM-20948, MPU6050, PCA9685, PCF8573, AMG8833, ITG3200, SPS30";
      break;
    case (0x6a):
      return "PCA9685, L3GD20H, PCF8573";
      break;
    case (0x6b):
      return "PCA9685, L3GD20H, PCF8573";
      break;
    case (0x6c):
      return "PCA9685";
      break;
    case (0x6d):
      return "PCA9685";
      break;
    case (0x6e):
      return "PCA9685";
      break;
    case (0x6f):
      return "PCA9685";
      break;
    case (0x70):
      return "PCA9685, TCA9548, HT16K33, SHTC3";
      break;
    case (0x71):
      return "PCA9685, TCA9548, HT16K33";
      break;
    case (0x72):
      return "PCA9685, TCA9548, HT16K33";
      break;
    case (0x73):
      return "PCA9685, TCA9548, HT16K33";
      break;
    case (0x74):
      return "PCA9685, TCA9548, HT16K33";
      break;
    case (0x75):
      return "PCA9685, TCA9548, HT16K33";
      break;
    case (0x76):
      return "BME680, HT16K33, MS5607, MS5611, PCA9685, BME280, BMP280, TCA9548";
      break;
    case (0x77):
      return "PCA9685, TCA9548, HT16K33, IS31FL3731, BME280, BMP280, MS5607, BMP180, BMP085, BMA180, MS5611, BME680";
      break;
    case (0x78):
      return "PCA9685";
      break;
    case (0x79):
      return "PCA9685";
      break;
    case (0x7a):
      return "PCA9685";
      break;
    case (0x7b):
      return "PCA9685";
      break;
    case (0x7c):
      return "PCA9685";
      break;
    case (0x7d):
      return "PCA9685";
      break;
    case (0x7e):
      return "PCA9685";
      break;
    case (0x7f):
      return "PCA9685";
      break;
    default:
      return "unknown";
  }
}

void loop() {
  byte error, addr;
  uint8_t nDevices, ix = 0;
  Serial.println("\nScanning...");
  nDevices = 0;
  Serial.print("   |.0 .1 .2 .3 .4 .5 .6 .7 .8 .9 .A .B .C .D .E .F\n---------------------------------------------------\n0. | . ");
  for (addr = 1; addr < 128; addr++) {
    Wire.beginTransmission(addr);
    error = Wire.endTransmission();
    // Wire.beginTransmission(addr);
    // error = Wire.endTransmission();
    Serial.write(' ');
    if (error == 0) {
      Serial.write('o');
      result[ix++] = addr;
      nDevices++;
    } else if (error == 4) {
      Serial.write('X');
    } else {
      Serial.write('x');
    } Serial.write(' ');
    if (addr > 0 && (addr + 1) % 16 == 0 && addr < 127) {
      Serial.write('\n');
      Serial.print(addr / 16 + 1);
      Serial.print(". |");
    }
  }
  Serial.println("\n---------------------------------------------------\nI2C devices found: " + String(nDevices));
  for (addr = 0; addr < ix; addr++) {
    Serial.print(" . 0x");
    if (result[addr] < 16) Serial.write('0');
    Serial.print(result[addr], 16);
    Serial.print(": ");
    Serial.println(getDef(result[addr]));
  }
  delay(5000);
}
