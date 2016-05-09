
void get_tempera(){
  unsigned short first=0,minus_chack=0;
  unsigned short d1,d2,m1,m2,y1,y2;

temper =0;
  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
   
  }
  
  // Get youtube sub`s and view`s
  String url = "/apps/thinghttp/send_request?api_key=5JVHZGLG1XKEEZPY";
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
   
int start_loc= find_text("Rea",line,0);
int end_loc=find_text("</s",line,0);
if (start_loc>0 && end_loc>0)
{
  Serial.println("temp:  ");
for (int i=start_loc+3;i<end_loc;i++)
{  
Serial.print(line[i]);
if( (line[i] >= 48) && (line[i]<=58) && (first==0) )
{
  temper = (line[i] - 48) *10;
  first++;
}
if( (line[i] >= 48) && (line[i]<=58) && (first==1) ){temper = temper + (line[i] - 48);} 
if( (line[i] =='-') && (minus_chack == 0))
{
  temper_mius_plus=1;
  minus_chack=1;
}
else{temper_mius_plus=0;}

}
}
}

  first=0;
  minus_chack=0;
  max7219_4_clr();
  dot_full_screen(clk_hour,clk_minut,temper,temper_mius_plus);
  d1=days/10;
  d2=days%10;
  m1=months/10;
  m2=months%10;
  y1=(years%100) /10;
  y2=years%10;
  max7219_send(0x08,d1);
  max7219_send(0x07,d2);
  max7219_send(0x06,0x0a);
  max7219_send(0x05,m1);
  max7219_send(0x04,m2);
  max7219_send(0x03,0x0a);
  max7219_send(0x02,y1);
  max7219_send(0x01,y2);

  
  Serial.println(); 
  Serial.print("temp:  ");
  Serial.println(temper);
  Serial.println("");
   
  Serial.println();
  Serial.println("closing connection");
  delay(10000);
}

