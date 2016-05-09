
void get_clock(){
  unsigned short find_sw=0,clock_hour=0,clock_minut=0,month=0,dayz=0,yearz=0;
  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
    if (!client.connect(host, httpPort)) 
    {
      Serial.println("connection failed");  
    }
  
  // Get clock and date
  String url = "/apps/thinghttp/send_request?api_key=ZN822HEAOKVI0SJK"; // get time from http://www.timeanddate.com/worldclock/israel/tel-aviv
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
   
int start_loc= find_text("h1",line,0);
int end_loc=find_text("</s",line,0);

if (start_loc>0 && end_loc>0)
{
  Serial.println("time:  ");
  //max7219_4_send(you_tube_logo,you_tube_subs2,you_tube_subs3,you_tube_subs4); // send youtube views grafic to dot matrix 
  //multi= end_loc - start_loc - 4 ;
for (int i=start_loc+4;i<end_loc;i++)
{  
Serial.print(line[i]);
   if( (line[i] == ':') && (find_sw==0) ) 
   {
     if( (line[i-2] >=48) && (line[i-2] <=58) ) {  clock_hour= ( (line[i-2]-48) *10 + (line[i-1] -48));}
     else { clock_hour= ( (line[i-1] -48) ); } 
     clock_minut= ( (line[i+1]-48) *10 + (line[i+2] -48));
     find_sw=1;  
   }
   if(line[i] == 'P') {clock_hour = clock_hour + 12 ; }
   if( (line[i] == 'A') && (clock_hour==12) ) {clock_hour = 0 ; }
}

find_sw=0; 
Serial.println(); 
Serial.print("hour:  ");
Serial.println(clock_hour);
Serial.print("minit:  ");
Serial.println(clock_minut);

int start_loc2= find_text("<p>",line,end_loc+1);
int end_loc2=find_text("</p",line,end_loc+1);
if (start_loc2>0 && end_loc2>0)
{
  Serial.println();
  Serial.println("date: ");
    for (int i=start_loc2+3;i<end_loc2;i++)
    {
    Serial.print(line[i]);
        if(line[i] == ','){
         find_sw++;
             if( find_sw == 2){
             if( (line[i-2] >=48) && (line[i-2] <=58) ) {  dayz= ( (line[i-2]-48) *10 + (line[i-1] -48));}
             else { dayz= ( (line[i-1] -48) ); }         
             yearz=((line[i+2]-48)* 1000) + ((line[i+3]-48)* 100) + ((line[i+4]-48)* 10) + (line[i+5]-48) ;
             
             }
        }
    }
Serial.println();
Serial.print("dayz: ");
Serial.println(dayz);
Serial.println();
Serial.print("yaerz: ");
Serial.println(yearz);

if(find_text("January" ,line,0) > 0)   { month=1;}
if(find_text("Februaryl" ,line,0) > 0) { month=2;}
if(find_text("March" ,line,0) > 0)     { month=3;}
if(find_text("April" ,line,0) > 0)     { month=4;}
if(find_text("May" ,line,0) > 0)       { month=5;}
if(find_text("June" ,line,0) > 0)      { month=6;}
if(find_text("July" ,line,0) > 0)      { month=7;}
if(find_text("August" ,line,0) > 0)    { month=8;}
if(find_text("September" ,line,0) > 0) { month=9;}
if(find_text("October" ,line,0) > 0)   { month=10;}
if(find_text("November" ,line,0) > 0)  { month=11;}
if(find_text("December" ,line,0) > 0)  { month=12;}
Serial.println();
Serial.print("month: ");
Serial.println(month);
}
}  
  }


clk_hour=clock_hour;
clk_minut=clock_minut;
days=dayz;
months=month;
years=yearz;

   
  Serial.println();
  Serial.println("closing connection");
  delay(12000);
}

