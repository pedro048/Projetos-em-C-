
void main(){

TRISD.RD7 = 0;
PORTD.RD7 = 0;
TRISB.RB0 = 1;

}

for(;;){
 if(RB0 == 1){
   if(RD7 == 1){
   PORTD.RD7 = 0;
   
   }else if(RD7 == 0){
   PORTD.RD7 = 1;
   }
 }

  if(RB0 == 0){
    if(RD7 == 1){
      PORTD.RD7 = 1;
      
    }else if(RD7 == 0){
      PORTD.RD7 = 0;
    }
  }

}