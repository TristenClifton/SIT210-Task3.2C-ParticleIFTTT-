// This #include statement was automatically added by the Particle IDE.
#include <BH1750Lib.h>


BH1750Lib lightmeter;
bool Is_sunny = FALSE;

void setup(){
  Serial.begin(9600);
  lightmeter.begin(BH1750LIB_MODE_CONTINUOUSHIGHRES);
  Serial.println("Running...");
}


void loop() {
  uint16_t lux = lightmeter.lightLevel();

  
    String temp = "";
    temp.concat((int)lux);
  
    Particle.publish("Lux", temp, PRIVATE);
    
    if(lux > 150 and Is_sunny == FALSE)
    {
        Particle.publish("Sunlight Has Started", "TRUE", PUBLIC);
        Is_sunny = TRUE;
    }
        if(lux <= 150 and Is_sunny == TRUE)
    {
        Particle.publish("Sunlight Has Ended", "TRUE", PUBLIC);
        Is_sunny = FALSE;
    }
  delay(10000);
  
}
