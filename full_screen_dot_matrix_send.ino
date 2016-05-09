
unsigned short num1[]= {0x0,0x0,0x2,0x2,0x2,0x2,0x2,0x0};
unsigned short num2[]= {0x0,0x0,0xE,0x2,0xE,0x8,0xE,0x0};
unsigned short num3[]= {0x0,0x0,0xE,0x2,0xE,0x2,0xE,0x0};
unsigned short num4[]= {0x0,0x0,0xA,0xA,0xE,0x2,0x2,0x0};
unsigned short num5[]= {0x0,0x0,0xE,0x8,0xE,0x2,0xE,0x0};
unsigned short num6[]= {0x0,0x0,0xE,0x8,0xE,0xA,0xE,0x0};
unsigned short num7[]= {0x0,0x0,0xE,0x2,0x2,0x2,0x2,0x0};
unsigned short num8[]= {0x0,0x0,0xE,0xA,0xE,0xA,0xE,0x0};
unsigned short num9[]= {0x0,0x0,0xE,0xA,0xE,0x2,0x2,0x0};
unsigned short num0[]= {0x0,0x0,0xE,0xA,0xA,0xA,0xE,0x0};
unsigned short clock_dots[]= {0x0,0x0,0x0,0x2,0x0,0x2,0x0,0x0};
unsigned short plus[]= {0x0,0x0,0x0,0x2,0x7,0x2,0x0,0x0};
unsigned short minus[]= {0x0,0x0,0x0,0x0,0x7,0x0,0x0,0x0};
unsigned short celc[]= {0x0,0x0,0x0,0x0,0x7,0x4,0x7,0x0};

unsigned short hr1=2,hr2=0,min1=4,min2=6,temp1=0,temp2=0;
unsigned short i=0;
unsigned long tempmul=0;
unsigned int  tempmul1=0;

void dot_full_screen(unsigned short hr,unsigned short minit,unsigned short temperatur ,unsigned short minus_plus){         // function get hour minit temperator minus or plus
unsigned short hr1_arry[]={0,0,0,0,0,0,0,0},hr2_arry[]={0,0,0,0,0,0,0,0},min1_arry[]={0,0,0,0,0,0,0,0},min2_arry[]={0,0,0,0,0,0,0,0},temp1_arry[]={0,0,0,0,0,0,0,0},temp2_arry[]={0,0,0,0,0,0,0,0},minus_plus_arry[]={0,0,0,0,0,0,0,0};
unsigned short array11[]={0,0,0,0,0,0,0,0},array22[]={0,0,0,0,0,0,0,0},array33[]={0,0,0,0,0,0,0,0},array44[]={0,0,0,0,0,0,0,0};
unsigned long dot[]={0,0,0,0,0,0,0,0};
    hr1= hr / 10;
    hr2= hr % 10;
    min1= minit / 10;
    min2= minit % 10;
    temp1= temperatur / 10;
    temp2= temperatur % 10;
    
    switch (hr1){
        case 0:   for(i=0;i<8;i++){hr1_arry[i] = num0[i];} break;
        case 1:   for(i=0;i<8;i++){hr1_arry[i] = num1[i];} break;
        case 2:   for(i=0;i<8;i++){hr1_arry[i] = num2[i];} break;
        case 3:   for(i=0;i<8;i++){hr1_arry[i] = num3[i];} break;
        case 4:   for(i=0;i<8;i++){hr1_arry[i] = num4[i];} break;
        case 5:   for(i=0;i<8;i++){hr1_arry[i] = num5[i];} break;
        case 6:   for(i=0;i<8;i++){hr1_arry[i] = num6[i];} break;
        case 7:   for(i=0;i<8;i++){hr1_arry[i] = num7[i];} break;
        case 8:   for(i=0;i<8;i++){hr1_arry[i] = num8[i];} break;
        case 9:   for(i=0;i<8;i++){hr1_arry[i] = num9[i];} break;
        default:  for(i=0;i<8;i++){hr1_arry[i] = num0[i];} break;  
    }
    switch (hr2){
        case 0:   for(i=0;i<8;i++){hr2_arry[i] = num0[i];} break;
        case 1:   for(i=0;i<8;i++){hr2_arry[i] = num1[i];} break;
        case 2:   for(i=0;i<8;i++){hr2_arry[i] = num2[i];} break;
        case 3:   for(i=0;i<8;i++){hr2_arry[i] = num3[i];} break;
        case 4:   for(i=0;i<8;i++){hr2_arry[i] = num4[i];} break;
        case 5:   for(i=0;i<8;i++){hr2_arry[i] = num5[i];} break;
        case 6:   for(i=0;i<8;i++){hr2_arry[i] = num6[i];} break;
        case 7:   for(i=0;i<8;i++){hr2_arry[i] = num7[i];} break;
        case 8:   for(i=0;i<8;i++){hr2_arry[i] = num8[i];} break;
        case 9:   for(i=0;i<8;i++){hr2_arry[i] = num9[i];} break;
        default:  for(i=0;i<8;i++){hr2_arry[i] = num0[i];} break;  
    }
     switch (min1){
        case 0:   for(i=0;i<8;i++){min1_arry[i] = num0[i];} break;     
        case 1:   for(i=0;i<8;i++){min1_arry[i] = num1[i];} break;
        case 2:   for(i=0;i<8;i++){min1_arry[i] = num2[i];} break;
        case 3:   for(i=0;i<8;i++){min1_arry[i] = num3[i];} break;
        case 4:   for(i=0;i<8;i++){min1_arry[i] = num4[i];} break;
        case 5:   for(i=0;i<8;i++){min1_arry[i] = num5[i];} break;
        case 6:   for(i=0;i<8;i++){min1_arry[i] = num6[i];} break;
        case 7:   for(i=0;i<8;i++){min1_arry[i] = num7[i];} break;
        case 8:   for(i=0;i<8;i++){min1_arry[i] = num8[i];} break;
        case 9:   for(i=0;i<8;i++){min1_arry[i] = num9[i];} break;
        default:  for(i=0;i<8;i++){min1_arry[i] = num0[i];} break;  
    }
     switch (min2){
        case 0:   for(i=0;i<8;i++){min2_arry[i] = num0[i];} break;   
        case 1:   for(i=0;i<8;i++){min2_arry[i] = num1[i];} break;
        case 2:   for(i=0;i<8;i++){min2_arry[i] = num2[i];} break;
        case 3:   for(i=0;i<8;i++){min2_arry[i] = num3[i];} break;
        case 4:   for(i=0;i<8;i++){min2_arry[i] = num4[i];} break;
        case 5:   for(i=0;i<8;i++){min2_arry[i] = num5[i];} break;
        case 6:   for(i=0;i<8;i++){min2_arry[i] = num6[i];} break;
        case 7:   for(i=0;i<8;i++){min2_arry[i] = num7[i];} break;
        case 8:   for(i=0;i<8;i++){min2_arry[i] = num8[i];} break;
        case 9:   for(i=0;i<8;i++){min2_arry[i] = num9[i];} break;
        default:  for(i=0;i<8;i++){min2_arry[i] = num0[i];} break;  
    }
     switch (minus_plus){
        case 0:   for(i=0;i<8;i++){minus_plus_arry[i] = plus[i];} break;   
        case 1:   for(i=0;i<8;i++){minus_plus_arry[i] = minus[i];} break;
        default:  for(i=0;i<8;i++){minus_plus_arry[i] = num0[i];} break;  
     }
     switch (temp1){
        case 0:   for(i=0;i<8;i++){temp1_arry[i] = num0[i];} break;   
        case 1:   for(i=0;i<8;i++){temp1_arry[i] = num1[i];} break;
        case 2:   for(i=0;i<8;i++){temp1_arry[i] = num2[i];} break;
        case 3:   for(i=0;i<8;i++){temp1_arry[i] = num3[i];} break;
        case 4:   for(i=0;i<8;i++){temp1_arry[i] = num4[i];} break;
        case 5:   for(i=0;i<8;i++){temp1_arry[i] = num5[i];} break;
        case 6:   for(i=0;i<8;i++){temp1_arry[i] = num6[i];} break;
        case 7:   for(i=0;i<8;i++){temp1_arry[i] = num7[i];} break;
        case 8:   for(i=0;i<8;i++){temp1_arry[i] = num8[i];} break;
        case 9:   for(i=0;i<8;i++){temp1_arry[i] = num9[i];} break;
        default:  for(i=0;i<8;i++){temp1_arry[i] = num0[i];} break;  
    }
     switch (temp2){
        case 0:   for(i=0;i<8;i++){temp2_arry[i] = num0[i];} break;   
        case 1:   for(i=0;i<8;i++){temp2_arry[i] = num1[i];} break;
        case 2:   for(i=0;i<8;i++){temp2_arry[i] = num2[i];} break;
        case 3:   for(i=0;i<8;i++){temp2_arry[i] = num3[i];} break;
        case 4:   for(i=0;i<8;i++){temp2_arry[i] = num4[i];} break;
        case 5:   for(i=0;i<8;i++){temp2_arry[i] = num5[i];} break;
        case 6:   for(i=0;i<8;i++){temp2_arry[i] = num6[i];} break;
        case 7:   for(i=0;i<8;i++){temp2_arry[i] = num7[i];} break;
        case 8:   for(i=0;i<8;i++){temp2_arry[i] = num8[i];} break;
        case 9:   for(i=0;i<8;i++){temp2_arry[i] = num9[i];} break;
        default:  for(i=0;i<8;i++){temp1_arry[i] = num0[i];} break;  
    }
     
   for(i=0;i<8;i++)              // dot matrix digit 1
    {
    tempmul=0;
    tempmul= hr1_arry[i] * 268435456;
    dot[i]= dot[i] | tempmul;
    }
    
    for(i=0;i<8;i++)             // dot matrix digit 2
    {
    tempmul=0;
    tempmul= hr2_arry[i] * 16777216; 
    dot[i]= dot[i] | tempmul;
    }
    
    for(i=0;i<8;i++)             // dot matrix clock dots
    {
    tempmul=0;
    tempmul= clock_dots[i] * 4194304; 
    dot[i]= dot[i] | tempmul;
    }
    
    for(i=0;i<8;i++)            // dot matrix digit 3
    {
    tempmul=0;
    tempmul= min1_arry[i] * 262144;   
    dot[i]= dot[i] | tempmul;
    }

    for(i=0;i<8;i++)           // dot matrix digit 4
    {
    tempmul1=0;
    tempmul1= min2_arry[i] * 16384;  
    dot[i]= dot[i] | tempmul1;
    }

    for(i=0;i<8;i++)          // dot matrix temperator minus/plus 
    {
    tempmul=0;
    tempmul= minus_plus_arry[i] * 2048;   
    dot[i]= dot[i] | tempmul;
    }

    for(i=0;i<8;i++)          // dot matrix temperator digit 1
    {
    tempmul=0;
    tempmul= temp1_arry[i] * 128;    
    dot[i]= dot[i] | tempmul;
    }

    for(i=0;i<8;i++)         // dot matrix temperator digit 2 
    {
    tempmul=0;
    tempmul= temp2_arry[i] * 8;     
    dot[i]= dot[i] | tempmul;
    }

    for(i=0;i<8;i++)               // dot matrix temperator celcius
    {
    tempmul=0;
    tempmul= celc[i];
    dot[i]= dot[i] | tempmul;
    }


    for(i=0;i<8;i++)
    {
    tempmul=0;
    tempmul = dot[i];
    array11[i] = tempmul >> 24;
    }

    for(i=0;i<8;i++)
    {
    tempmul=0;
    tempmul = dot[i];
    array22[i] = tempmul >> 16;
    }

    for(i=0;i<8;i++)
    {
    tempmul=0;
    tempmul = dot[i];
    array33[i] = tempmul >> 8;
    }
    
    for(i=0;i<8;i++)
    {
    tempmul=0;
    tempmul = dot[i];
    array44[i] = tempmul ;
    }

    max7219_4_send(array11,array22,array33,array44); // send youtube views grafic to dot matrix 
  
}

