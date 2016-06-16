#include <SPI.h>
#include <Ethernet.h>
boolean leyendo = false;

//Configuración de la red
byte ip[] = {192, 168, 1, 69};
byte gateway[] = {192, 168, 1, 1};
byte subnet[] = {255, 255, 255, 0};
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

//IPAddress ip(192, 168, 1, 69);

EthernetServer server(80);

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  Ethernet.begin(mac, ip, gateway);
  server.begin();
  Serial.print("Servidor corriendo en: ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  revisarCliente();
}

void revisarCliente(){
  EthernetClient client = server.available();
  if (client) {
    boolean finDeLinea = true;
    boolean sentHeader = false;
    while (client.connected()) {
      if (client.available()) {
        if(!sentHeader){
          client.println("HTTP:1.1 200 OK");
          client.println("Content-type: text/html");
          client.println();          
          sentHeader = true;
        }
        char c = client.read();
        if(leyendo && c == ' ') leyendo = false;
        if(c == '?') leyendo = true;
        if(leyendo){
          Serial.print(c);
          switch(c){
            case '2':
              triggerPin(2, client);
              break;
            case '3':
              triggerPin(3, client);
              break;
            case '4':
              triggerPin(4, client);
              break;
            case '5':
              triggerPin(5, client);
              break;
            case '6':
              triggerPin(6, client);
              break;                                                     
          }
        }
        if(c == '\n' && finDeLinea) break;
        if(c == '\n'){
            finDeLinea = true;
        }else if(c != '\r'){
            finDeLinea = false;
        }
      }
    }
    delay(1);   
    client.stop();
  }
}

void triggerPin(int pin, EthernetClient client){
  client.print("Encendiendo pin ");
  client.print(pin);
  client.print("<br>");
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
  delay(1000);
}
