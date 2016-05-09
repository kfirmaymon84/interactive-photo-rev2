void max7219_send(unsigned short maxadd,unsigned short maxdata)   // spi send adrees and data to max7219
{
digitalWrite(4, LOW); // max7219 cs
SPI.transfer(maxadd);
SPI.transfer(maxdata);
digitalWrite(4, HIGH); // max7219 cs
}

void max7219_send4(unsigned short maxadd1,unsigned short maxdata1,unsigned short maxadd2,unsigned short maxdata2, unsigned short maxadd3 ,unsigned short maxdata3, unsigned short maxadd4 ,unsigned short maxdata4)   // spi send adrees and data to max7219 * 4
{
digitalWrite(16, LOW); // max7219 cs
SPI.transfer(maxadd4);
SPI.transfer(maxdata4);
SPI.transfer(maxadd3);
SPI.transfer(maxdata3);
SPI.transfer(maxadd2);
SPI.transfer(maxdata2);
SPI.transfer(maxadd1);
SPI.transfer(maxdata1);
digitalWrite(16, HIGH); // max7219 cs
}


void max7219_init()        // initilize max7219
{
    max7219_send(0x0F,0x01);  // test mode on
    delay(1000);
    max7219_send(0x0F,0x00);  // test mode off
    max7219_send(0x09,0xFF);  // set decade mode to B
    max7219_send(0x0A,0x04);  // set brightness
    max7219_send(0x0B,0x07);  // set scan for all digits
    max7219_send(0x0C,0x01);  // turn on chip
    max7219(0);
}

void max7219(unsigned long maxnum)     // send 8 digit to max7219
{
unsigned short dig1=0,dig2=0,dig3=0,dig4=0,dig5=0,dig6=0,dig7=0,dig8=0;
unsigned short i=0;
dig1 = (maxnum%10);
dig2 = (maxnum%100)/10;
dig3 = (maxnum%1000)/100;
dig4 = (maxnum%10000)/1000;
dig5 = (maxnum%100000)/10000;
dig6 = (maxnum%1000000)/100000;
dig7 = (maxnum%10000000)/1000000;
dig8 = (maxnum%100000000)/10000000;

 for(i=0;i<8;i++){max7219_send(i+1,0x0f);}  // blank digits

 // send all digit that mater
    max7219_send(0x01,dig1);
 if(maxnum>9){max7219_send(0x02,dig2);}
 if(maxnum>99){max7219_send(0x03,dig3);}
 if(maxnum>999){max7219_send(0x04,dig4);}
 if(maxnum>9999){max7219_send(0x05,dig5);}
 if(maxnum>99999){max7219_send(0x06,dig6);}
 if(maxnum>999999){max7219_send(0x07,dig7);}
 if(maxnum>9999999){max7219_send(0x08,dig8);}
}

void max7219_4_init()        // test max7219
{
    unsigned short i=0;
    max7219_send4(0x0f,0x01,0x0F,0x01,0x0F,0x01,0x0F,0x01);
    delay(1000);
    max7219_send4(0x0f,0x00,0x0F,0x00,0x0F,0x00,0x0F,0x00);
    max7219_send4(0x09,0x00,0x09,0x00,0x09,0x00,0x09,0x00); // no decade mode
    max7219_send4(0x0A,0x01,0x0A,0x01,0x0A,0x01,0x0A,0x01); // set brightness
    max7219_send4(0x0B,0x07,0x0B,0x07,0x0B,0x07,0x0B,0x07); // set scan for all digits
    max7219_send4(0x0C,0x01,0x0C,0x01,0x0C,0x01,0x0C,0x01); // turn on chip
  
    for( i=1; i<9 ; i++){  // clear all dot display
    max7219_send4(i,0x00,i,0x00,i,0x00,i,0x00);
    }
}

void max7219_4_send(unsigned short arra1[],unsigned short arra2[],unsigned short arra3[],unsigned short arra4[]){
unsigned short i=0;

for(i=0;i<8;i++){
   max7219_send4(i+1,arra4[i],i+1,arra3[i],i+1,arra2[i],i+1,arra1[i]);
} 
}

void max7219_4_clr(){
  unsigned short clr1[]={0,0,0,0,0,0,0,0},clr2[]={0,0,0,0,0,0,0,0},clr3[]={0,0,0,0,0,0,0,0},clr4[]={0,0,0,0,0,0,0,0};
for(i=0;i<8;i++){
   max7219_send4(i+1,clr1[i],i+1,clr2[i],i+1,clr3[i],i+1,clr4[i]);
}
}


