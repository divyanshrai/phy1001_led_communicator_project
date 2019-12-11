int sensorPin = A0; // select the input pin for LDR
int sensorValue = 0; // variable to store the value coming from the sensor
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //sets serial port for communication
}

void loop() {
 // read the value from the sensor


int arr[100];int c=0;
for(int i=0;i<50;i++)
{
  sensorValue = analogRead(sensorPin);
if(sensorValue<20)
{
  arr[c]=0;
  c++;
  Serial.println(0);
}
if(sensorValue>20)
{
  arr[c]=1;
  c++;
  Serial.println(1);
}
delay(700);
}


for(int i=0;i<100;i++)
{
  if(arr[i]==1&&arr[i+1]==1&&arr[i+2]==0&&arr[i+3]==1&&arr[i+4]==0)
    {c=i+5;
    break;}
}
String message= "Message is:  ";
for(int i=c;i<100;i=i+5)
{
  if(arr[i]==1 && arr[i+1]==1 && arr[i+2]==0 && arr[i+3]==1 && arr[i+4]==1) 
  message = message + 'A';
  else if(arr[i]==0 && arr[i+1]==0 && arr[i+2]==0 && arr[i+3]==0 && arr[i+4]==1) 
  message = message + 'B';
}
Serial.println(message);

}

