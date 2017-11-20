#include <WiFi.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
using namespace std;

const char* ssid     = "TU VIEJA";
const char* password = "EN TANGA";

const char* streamId   = "192.168.0.21";
  

#define port 8888

  int sockfd = 0, n = 0;
  char recvBuff[1024];
  struct sockaddr_in serv_addr; 

/*CREACION DE UN SOCKET
 * La secuencia resumida de llamadas al sistema es:
 * 
 * 1. --> socket()
 * 2. --> bind()
 * 3. --> listen()
 * 4. --> accept()
 */

 //Teclas
 #define TECLA1 26
 #define TECLA2 25
 #define TECLA3 33
 #define TECLA4 32
 #define TECLA5 35
 #define TECLA6 34
 #define TECLA7 39
 #define VOLUME 27
void setup()
{
    Serial.begin(115200);
    delay(10);
    //Defino los pines como entrada
    pinMode(TECLA1,INPUT);
    pinMode(TECLA2,INPUT);
    pinMode(TECLA3,INPUT);
    pinMode(TECLA4,INPUT);
    pinMode(TECLA5,INPUT);
    pinMode(TECLA6,INPUT);
    pinMode(TECLA7,INPUT);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    //SOCKET

    memset(recvBuff, '0',sizeof(recvBuff));
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        Serial.print("\n Error : Could not create socket \n");
        //return 1;
    } 

    memset(&serv_addr, '0', sizeof(serv_addr)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port); 

    if(inet_pton(AF_INET, "192.168.0.21", &serv_addr.sin_addr)<=0)
    {
        Serial.print("\n inet_pton error occured\n");
        ///return 1;
    } 

    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
       Serial.print("\n Error : Connect Failed \n");
       //return 1;
    }

}
int handleError(const char *s)
{
  printf("%s: %s\n", s, strerror(errno));
  exit(1);
}


int value = 0;

byte getBotones(){
  byte salida= 0;
  if(digitalRead(TECLA1)==LOW){
    //Serial.println("TECLA1");
    write(sockfd, "TECLA1", 6);
    salida |= B00000001;
   }
   if(digitalRead(TECLA2)==LOW){
    //Serial.println("TECLA2");
    write(sockfd, "TECLA2", 6);
    salida |= B00000010;
   }
   if(digitalRead(TECLA3)==LOW){
    //Serial.println("TECLA3");
    write(sockfd, "TECLA3\n", 8);
    salida |= B00000100;
   }
   if(digitalRead(TECLA4)==LOW){
    //Serial.println("TECLA4");
    write(sockfd, "TECLA4\n", 8);
    salida |= B00001000;
   }
   if(digitalRead(TECLA5)==LOW){
    //Serial.println("TECLA5");
    close(sockfd); //TESTING de sesion
    //write(sockfd, "TECLA5\n", 8);
    salida |= B00010000;
   }
   if(digitalRead(TECLA6)==LOW){
    //Serial.println("TECLA6");
    write(sockfd, "TECLA6\n", 8);
    salida |= B00100000;
   }
   if(digitalRead(TECLA7)==LOW){
    //Serial.println("TECLA7");
    write(sockfd, "TECLA7\n", 8);
    salida |= B01000000;
   }
   Serial.println(salida);
   return salida;
}


byte obtVolumen(){

return 0;

}

void loop()
{

  
   byte apretados= getBotones();

   byte potenciometro=obtVolumen();

   uint8_t send_buf[20]; //arreglo que almacena la informacion a transmitir

   sprintf((char*)send_buf, "<%i$%c$%i$%i>",10, 1, apretados, potenciometro);

      Serial.println((char *) send_buf);


  /*
   if(digitalRead(TECLA1)==LOW){
    Serial.println("TECLA1");
    write(sockfd, "TECLA1", 6);
   }
   if(digitalRead(TECLA2)==LOW){
    Serial.println("TECLA2");
    write(sockfd, "TECLA2", 6);
   }
   if(digitalRead(TECLA3)==LOW){
    Serial.println("TECLA3");
    write(sockfd, "TECLA3\n", 8);
   }
   if(digitalRead(TECLA4)==LOW){
    Serial.println("TECLA4");
    write(sockfd, "TECLA4\n", 8);
   }
   if(digitalRead(TECLA5)==LOW){
    Serial.println("TECLA5");
    close(sockfd); //TESTING de sesion
    //write(sockfd, "TECLA5\n", 8);
   }
   if(digitalRead(TECLA6)==LOW){
    Serial.println("TECLA6");
    write(sockfd, "TECLA6\n", 8);
   }
   if(digitalRead(TECLA7)==LOW){
    Serial.println("TECLA7");
    write(sockfd, "TECLA7\n", 8);
   }*/
    
   
   delay(5); 
}
