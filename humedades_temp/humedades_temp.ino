#include <DHT.h>
#define DHT11PIN 0 //pin D3
#define DHT11TYPE DHT11
DHT dht11(DHT11PIN, DHT11TYPE);
float h11;
float t11;

int analog_pin = A0; //pin A0 
int humedad_suelo;
int humedad_suelomap;


void setup()
{
  Serial.begin(115200);
  dht11.begin();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  humedadsuelo();
  dht_11();
  delay(2000);
  Serial.println("");
}


//----------------------------------------------------------------------------------------------//
 

void humedadsuelo()
  {
      humedad_suelo = analogRead(analog_pin);
      humedad_suelomap = map(humedad_suelo, 0, 1023, 100, 0);
      Serial.print("Humedad Suelo: ");
      Serial.print(humedad_suelomap);
      Serial.println("%");
      
  }


//----------------------------------------------------------------------------------------------//




//----------------------------------------------------------------------------------------------//

void dht_11(){

  h11 = dht11.readHumidity();
  t11 = dht11.readTemperature();

  if (isnan(h11) || isnan(t11)) {
    // Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humedad Ambiente: ");
  Serial.print(h11);
  Serial.println("%");
  
  Serial.print("Temperatura: ");
  Serial.print(t11);
  Serial.println("*C");
}

//----------------------------------------------------------------------------------------------//