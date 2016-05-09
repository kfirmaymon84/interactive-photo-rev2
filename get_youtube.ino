/////////// dot matrix grafic ////////////
unsigned short you_tube_logo[]={0x3C,0x6E,0xE7,0xE3,0xE3,0xE7,0x6E,0x3C};
unsigned short you_tube_subs2[]={0x3D,0x41,0x41,0x39,0x5,0x5,0x78,0x0};
unsigned short you_tube_subs3[]={0x17,0x14,0x14,0x17,0x14,0x14,0xE7,0x0};
unsigned short you_tube_subs4[]={0x8F,0x50,0x50,0x8E,0x41,0x41,0x9E,0x0};

unsigned short you_tube_views2[]={0x0,0x57,0x52,0x52,0x52,0x27,0x0,0x0};
unsigned short you_tube_views3[]={0x0,0x74,0x44,0x75,0x45,0x72,0x0,0x0};
unsigned short you_tube_views4[]={0x0,0x4E,0x50,0x4C,0x42,0x9C,0x0,0x0};

///////////END dot matrix grafic ////////////


void get_youtube(){
   Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
   
  }
  
  // Get youtube sub`s and view`s
  String url = "/apps/thinghttp/send_request?api_key=4EZDJHJC63M9P6FU";
  Serial.print("Requesting URL: ");
  Serial.println(url);
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.0\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(500);
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
   String line = client.readStringUntil('\r');
   
int start_loc= find_text("<b>",line,0);
int end_loc=find_text("</b>",line,0);
unsigned long multi=0,sum=0;
if (start_loc>0 && end_loc>0)
{
  Serial.println("subs:  ");
  max7219_4_send(you_tube_logo,you_tube_subs2,you_tube_subs3,you_tube_subs4); // send youtube views grafic to dot matrix 
  multi= end_loc - start_loc - 4 ;
for (int i=start_loc+3;i<end_loc;i++)
{  
Serial.print(line[i]);
if((line[i]>= 48) && (line[i]<= 57)){ 
sum = (line[i] - 48 ) * pow(10, multi) + sum;
multi--;
}
}
max7219(sum);
Serial.println("");
delay(7000);
max7219_4_send(you_tube_logo,you_tube_views2,you_tube_views3,you_tube_views4); // send youtube subs grafic to dot matrix 
sum=0;   // reset sum value
int start_loc2= find_text("<b>",line,end_loc+1);
int end_loc2=find_text("</b>",line,end_loc+1);
if (start_loc2>0 && end_loc2>0)
{
  Serial.println("views:");
  multi = end_loc2 - start_loc2 - 5 ;// set multi value
for (int i=start_loc2+3;i<end_loc2;i++)
{
Serial.print(line[i]);
if((line[i]>= 48) && (line[i]<= 57)){ 
sum = (line[i] - 48 ) * pow(10, multi) + sum;
multi--;
}
}
max7219(sum);
}


}
    
 //   Serial.println(line);
  }
  
  Serial.println();
  Serial.println("closing connection");
}

