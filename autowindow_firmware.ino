#include <SoftwareSerial.h>
#include <DHT.h>

#define DHTPIN 4
#define BT_RXD 8  // 회로 상에서 블루투스 rxd는 7번에 연결
#define BT_TXD 7  // 회로 상에서 블루투스 txd는 8번에 연결

DHT dht11(DHTPIN, DHT11);
SoftwareSerial bluetooth(BT_RXD, BT_TXD);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  dht11.begin();
}

void loop() {
  float humidity = dht11.readHumidity(false);
  float temperature = dht11.readTemperature(false);
  int water_level = analogRead(A0);

  bluetooth.print("h");
  bluetooth.print(humidity);
  delay(100);

  bluetooth.print("t");
  bluetooth.print(temperature);
  delay(100);

  bluetooth.print("w");
  bluetooth.print(water_level);

  delay(1000);
}
