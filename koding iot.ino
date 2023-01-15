// program esp nod mcu
#include <CTBot.h>
CTBot smarthome333;
int relay=5;

void setup() {
  Serial.begin(115200);
  pinMode(relay,OUTPUT);
  digitalWrite(relay,HIGH);
  smarthome333.wifiConnect("redmi9, redmi0009");
  smarthome333.setTelegramToken("5973918591:AAGzAtZbCOOKA04P_Wbd_s1vhpzlBkOZJac");
  if(smarthome333.testConnection())
    Serial.println("Terhubung");
  else
    Serial.println("Error!");

}

void loop() {
TBMessage pesan;

  if(smarthome333.getNewMessage(pesan)){
  Serial.print("Ada pesan Masuk : ");
  Serial.println(pesan.text);
  if(pesan.text.equalsIgnoreCase("RELAY ON")){
    digitalWrite(relay,LOW);
    smarthome333.sendMessage(pesan.sender.id,"Menghidupkan Relay");
  }
  else if(pesan.text.equalsIgnoreCase("RELAY OFF")){
    digitalWrite(relay,HIGH);
    smarthome333.sendMessage(pesan.sender.id,"Mematikan Relay");
  }
  else{
    String balas;
    balas="Maaf perintah yang anda masukkan salah. Coba kirim RELAY ON atau RELAY OFF.";
    smarthome333.sendMessage(pesan.sender.id,balas);
  }

  }

}
