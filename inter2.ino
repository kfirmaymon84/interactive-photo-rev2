#include <SPI.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <SoftwareSerial.h>

#include <DNSServer.h>            //Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h>     //Local WebServer used to serve the configuration portal
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager WiFi Configuration Magic

// FUNCTION DECLERTION /////
void get_youtube();
void get_clock();
void get_tempera();
void max7219_send(unsigned short maxadd,unsigned short maxdata);   // spi send adrees and data to max7219
void max7219_init();        // initilize max7219
void max7219(unsigned long maxnum);     // send 8 digit to max7219
void max7219_4_clr();// clr dot matrix screen
void max7219_send4(unsigned short maxadd1,unsigned short maxdata1,unsigned short maxadd2,unsigned short maxdata2, unsigned short maxadd3 ,unsigned short maxdata3, unsigned short maxadd4 ,unsigned short maxdata4);   // spi send adrees and data to max7219 * 4
void max7219_4_init(); // init 4* max7219
void max7219_4_send(unsigned short arra1[],unsigned short arra2[],unsigned short arra3[],unsigned short arra4[]);

void dot_full_screen(unsigned short hr,unsigned short minit,unsigned short temperatur ,unsigned short minus_plus);
// END FUNCTION DECLERTION /////


const char* ssid = "BEZEQINT-3289";
const char* password = "2176461297";
const char* host = "api.thingspeak.com";

unsigned short ip_code1[]={0x0,0x5D,0xD4,0x5D,0x45,0x45,0x0,0x0};
unsigned short ip_code2[]={0x0,0xC5,0x4D,0xC5,0x5,0xD5,0x0,0x0};
unsigned short ip_code3[]={0x0,0xDC,0x14,0xDC,0x54,0xDD,0x0,0x0};
unsigned short ip_code4[]={0x0,0x51,0x53,0x71,0x11,0x15,0x0,0x0};

unsigned short clk_hour=0,clk_minut,days=0,months=0,years=0;
unsigned short temper=0,temper_mius_plus=0;
int find_text(String needle, String haystack,int from) {
  int foundpos = -1;
  if (haystack.length()<needle.length())
    return foundpos;
  for (int i = from; (i < haystack.length() - needle.length()); i++) {
    if (haystack.substring(i,needle.length()+i) == needle) {
      foundpos = i;
      return foundpos;
    }
  }
  return foundpos;
}



void setup() {
  pinMode(16, OUTPUT); // we use this for cs pin dot matrix
  pinMode(4, OUTPUT); // we use this for cs pin 8 7 segment display
  SPI.begin(); // wake up the SPI bus.
  SPI.setBitOrder(MSBFIRST);
  
  max7219_4_init(); // init 4* max7219
  max7219_init();   // initilize max7219 7 segment
  max7219_4_send(ip_code1,ip_code2,ip_code3,ip_code4);
   
  WiFiManager wifiManager;
  wifiManager.autoConnect("kfir-esp", "123456");
  Serial.begin(115200);
  //WiFi.begin(ssid, password);
  //Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  
   get_youtube();
   get_clock();
   get_tempera();




}
