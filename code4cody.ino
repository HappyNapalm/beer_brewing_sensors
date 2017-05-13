//Author: Ian Church Weber
//Do not mod code without contacting author
//This is pretty ezpz shit so figure it out yourself

//Unsiged 16 bit var to hold information
unsigned short int Temp_ch_1 = 0;
unsigned short int Temp_ch_2 = 0;
unsigned short int Brew_ch_1 = 0;

//unsigned 64 bit var for time increments and data points.
unsigned long int Run_time = 0;

unsigned short int time_inc = 1000;

void setup() {
  //establish baud rate. 
  Serial.begin(9600);
  header_format();
}

void loop() {
  if(Serial.available()){
    Temp_ch_1 = analogRead(A0);
    Temp_ch_2 = analogRead(A1);
    Brew_ch_1 = analogRead(A2);
    delay(time_inc);
    Run_time = Run_time++;
    data_format();
  }

}

void header_format(){
  Serial.println("Tempurature Probe 1, Tempurature Probe 2, Alcohol Content, Time Passed");
}

void data_format(){
  Serial.print(Temp_ch_1);
  Serial.print(",");
  Serial.print(Temp_ch_2);
  Serial.print(",");
  Serial.print(Brew_ch_1);
  Serial.print(",");
  Serial.print(Run_time);
  Serial.println("");
}

void brew_timers(){//this will take a weird amount of work to do right...
  
}

