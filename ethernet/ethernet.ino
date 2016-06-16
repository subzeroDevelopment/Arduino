#include <EthernetUdp.h>
#include <Dns.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <Ethernet.h>
#include <Dhcp.h>

boolean reading=false;


byte ip[]={192,168,1,109};
byte gateway[]={192,168,1,254};
byte subnet[]={255,255,255,0};
//IPAddress ip(192,168,1,1);
//byte ip[]={192,168,1,11};
byte mac[]={
  0xDE,0xAD,0xBE,0xEF,0xFE,0xED
  };

EthernetServer server(80);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
digitalWrite(4, HIGH);
  delay(1000);
  digitalWrite(4,LOW);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac,ip,gateway);
  }
  //Ethernet.begin(mac,ip,gateway);
  server.begin();
  Serial.print("ip:");
  Serial.println(Ethernet.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  checkForClient();

}

void checkForClient(){
  EthernetClient client=server.available();
  if(client){
      boolean currentLineIsBlank=true;
      boolean sentHeader=false;

      while(client.connected()){
          if(client.available()){
              if(!sentHeader){
                  client.println("HTTP/1.1 200 OK");
                  client.println("Content-Type: text/html");               
                  client.println();
                  sentHeader=true;
                }
                char c=client.read();
                if(reading && c==' ')reading=false;
                if(c=='?')reading=true;                

                if(reading){
                    Serial.print(c);

                    switch(c){
                        case '2':
                          triggerPin(2,client);
                          break;
                        case '3':
                          triggerPin(3,client);
                          break;
                        case '4':
                          triggerPin(4,client);
                          break;
                        case '5':
                          triggerPin(5,client);
                          break;
                        
                      }
                  }
                if(c=='\n'&& currentLineIsBlank)break;
                if(c=='\n'){
                    currentLineIsBlank=true;
                  }else if(c!='\r'){
                      currentLineIsBlank=false;
                    }
            }
        
        }
        delay(1);
        client.stop();
    
    }
  }


  void triggerPin(int pin,EthernetClient client){
      client.print("Encendiendo un pin");
      client.println(pin);
      client.print("<br>");

      digitalWrite(pin,HIGH);
      delay(25);
      digitalWrite(pin,LOW);
      delay(25);
      
    }

