int red[] = {2,3,4};
int redSize = sizeof(red) / sizeof(red[0]);
int de_red = 5;
int yellow[] = {6,7};
int yellowSize = sizeof(yellow) / sizeof(yellow[0]);
int green[] = {8,9,10,11};
int greenSize = sizeof(green) / sizeof(green[0]);
int sensor = 13;
void setup() {
  Serial.begin(9600);
  pinMode(de_red,OUTPUT);
  pinMode(sensor, INPUT);
  for (int i = 0; i < redSize; i++) 
  {pinMode(red[i], OUTPUT);} 
  for (int i = 0; i < yellowSize; i++) 
  {pinMode(yellow[i], OUTPUT);}
  for (int i = 0; i < greenSize; i++) 
  {pinMode(green[i], OUTPUT);} }
void loop() 
{ int get_info_sensor = digitalRead(sensor);
  int get_info_analog = analogRead(A0);
  Serial.println(get_info_analog);
  int wait_time = 8000;
  bool time_changed = false;
  //main loop start
  checkSensor(get_info_sensor); //check input
  if (digitalRead(de_red) == HIGH) //double check input
    {time_changed = true;}

  for (int i = 0; i < greenSize; i++) //turn on all green
    {digitalWrite(green[i], HIGH);} 

  if (time_changed == true) //wait for pedestrian
    {wait_time = 2000; delay(wait_time); time_changed = false;}
  else
    {delay(wait_time);}

  digitalWrite(yellow[0], HIGH); //turn on yellow1
  for (int i = 0; i < greenSize; i++) //turn off all green w/delay
    {digitalWrite(green[i], LOW); delay(200);}

  delay(200);
  digitalWrite(yellow[1], HIGH); //turn on yellow2
  delay(400);
  for (int i = 0; i < yellowSize; i++) //turn of all yellow w/delay
    {digitalWrite(yellow[i], LOW); delay(400);}

  for (int i = 0; i < redSize; i++)  //turn on all red
    {digitalWrite(red[i], HIGH);}
  delay(7000); //red wait time

  digitalWrite(yellow[0], HIGH); //turn on yellow1
  for (int i = 0; i < redSize; i++) //turn off all red w/delay
    {digitalWrite(red[i], LOW); delay(200);}
  delay(200);
  digitalWrite(yellow[1], HIGH); //turn on yellow2
  delay(400);
  for (int i = 0; i < yellowSize; i++) //turn of all yellow w/delay
    {digitalWrite(yellow[i], LOW); delay(400);}
  
}

void checkSensor(int get_info_sensor) {
  if (get_info_sensor == LOW) 
    {digitalWrite(de_red, HIGH);} 
  else
   {digitalWrite(de_red, LOW);}       }

