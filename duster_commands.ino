#define LIGHT_SENSOR_PIN 2 // ESP32 pin GIOP36 (ADC0)

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
    serial.println(getLight());
    delay(500);
}

//código referente ao status de luz do ambiente;
string getLight(){
    // reads the input on analog pin (value between 0 and 4095)
  int analogValue = analogRead(LIGHT_SENSOR_PIN);
  string light_Ambient ="";
  light_Ambient += "Analog Value = ";
  light_Ambient += analogValue;   // the raw analog reading

  // We'll have a few threshholds, qualitatively determined
  if (analogValue < 40) {
    light_Ambient += " => Escuro";
  } else if (analogValue < 800) {
    light_Ambient += " => Meia-luz";
  } else if (analogValue < 2000) {
    light_Ambient += " => Claro";
  } else if (analogValue < 3200) {
    light_Ambient += " => Muito Claro";
  } else {
    light_Ambient += " => Extremamente Claro";
  }
  return light_Ambient;
}

//código referente ao uso da vassoura 
string vassoura = "";
boolean Vstatus = false;
string actionVassoura(){
    Vstatus = !Vstatus;
    if(Vstatus==true){
        vassoura = "on";
    }else{
        vassoura = "off";
    }
    return vassoura;
}

string statusVassoura(){
  return Vstatus;
}

//código referente ao uso do aspirador 
string aspirador = "";
boolean Astatus = false;
string actionAspirador(){
    Astatus = !Astatus;
    if(Astatus==true){
        aspirador = "on";
    }else{
        aspirador = "off";
    }
    return aspirador;
}

string statusAspirador(){
  return Astatus;
}
