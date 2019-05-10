#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_BMP085.h>
#include <Wire.h>

int bin; float tensao, res, lum, temp, umid, press; // Declara variáveis
DHT dht(2,DHT22); // Declara objeto do tipo DHT
Adafruit_BMP085 bmp; // Declara objeto do tipo BMP

void setup()
{
Serial.begin(9600); // Inicializa serial
analogReference(INTERNAL); // Fundo escala 1,1V
dht.begin(); // Inicializa objeto dht
bmp.begin(); // Inicializa objeto bmp

}
void loop()
{
  //LDR
bin = analogRead(A1); // Lê binário
tensao = (bin/1023.0)*5.0; // Calc. tensão
res = tensao*100000.0/(5.0-tensao); // Calc. resist.
lum = pow(10,6.5-1.25*log10(res)); // Calc. lumnos.
//Serial.print("\n\nDado: ");
//Serial.print(bin); // Exibe binário
//Serial.print("\nTensão [V]: ");
//Serial.print(tensao); // Exibe tensão
//Serial.print("\nResistência [kΩ]: ");
//Serial.print(res/1000); // Exibe resistência
Serial.print ("\n\n----------");
Serial.print("\nLuminosidade [Lux]: ");
Serial.print(lum); // Exibe luminosidade
  //DHT22
umid = dht.readHumidity(); // Lê umidade
umid = 1.00*umid + 0.00; // Calibração
Serial.print("\n\nUmidade [%]: ");
Serial.print(umid); // Exibe umidade
  //BMP180
press = bmp.readPressure(); // Lê pressão
Serial.print("\n\nPressão [hPa]: ");
Serial.print(press/100); // Exibe pressão
  //LM35
bin = analogRead(A2); // Lê valor binário
tensao = (bin/1023.0)*1.1; // Converte em tensão
temp = 100.00*tensao+0.00; // Converte em temp.
//Serial.print("\n\nDado: ");
//Serial.print(bin); // Exibe dado binário
//Serial.print("\nTensão [V]: ");
//Serial.print(tensao); // Exibe tensão
Serial.print("\n\nTemperatura [ºC]: ");
Serial.print(temp); // Exibe temperatura

delay(3000);
}
