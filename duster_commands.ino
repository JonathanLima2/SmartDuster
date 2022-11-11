#define LIGHT_SENSOR_PIN 2 // ESP32 pin GIOP36 (ADC0)
//parâmetros de retorno
//["RGS",SL, SU, SB, AA, AV, RE, REFT, RD, RDFT]
byte RGS = 0x00;
byte SL = 0x00;
byte SU = 0x00;
byte SB = 0x00;
byte AA = 0x00;
byte AV = 0x00;
byte RE = 0x00;
byte REFT = 0x00;
byte RD = 0x00;
byte RDFT = 0x00;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
    serial.println(getLight());
    delay(500);
}

byte[] getStatus(){
  byte[9] status;
  byte[0] = getLight(); 
  byte[1] = getLight(); 
  byte[2] = getLight(); 
  byte[3] = getLight(); 
  byte[4] = getLight(); 
  byte[5] = getLight(); 
  byte[6] = getLight(); 
  byte[7] = getLight(); 
  byte[8] = getLight(); 
}

//código referente ao status de luz do ambiente;
byte getLight(){
    // reads the input on analog pin (value between 0 and 4095)
  int analogValue = analogRead(LIGHT_SENSOR_PIN);
  byte ret = 0x00;
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
  Serial.println(light_Ambient);
  if(analogValue>0)
    ret = 0x01;
  else if(analogValue==0)
    ret = 0x00;
  else 
    ret = 0xff; 
  return ret;
}

//código referente ao uso da vassoura 
byte actionVassoura(){
    if(AV==0x00){
      AV=0x01;
    }else{
      AV=0x00;
    }
    return AV;
}

byte statusVassoura(){
  return AV;
}

//código referente ao uso do aspirador 
byte actionAspirador(){
    if(AA==0x00){
      AA=0x01;
    }else{
      AA=0x00;
    }
    return AA;
}

byte statusAspirador(){
  return AA;
}

//código referente ao uso da roda esquerda e sua tração
byte actionRodaEsqueda(){
    if(RE==0x00){
      RE=0x01;
    }else{
      RE=0x00;
    }
    return RE;
}

byte statusRE(){
  return RE;
}
byte TracaoEsquerda(){
  if(RE==0x01 && REFT==0x00)
    REFT=0x01;
  return RE;
}

byte statusREFT(){
  return REFT;
}
//código referente ao uso da roda direita e sua tração
byte actionRodaDireita(){
    if(RD==0x00){
      RD=0x01;
    }else{
      RD=0x00;
    }
    return RD;
}

string statusRD(){
  return RD;
}
byte TracaoDireita(){
  if(RD==0x01 && RDFT==0x00)
    RDFT=0x01;
  return RE;
}

byte statusRDFT(){
  return RDFT;
}