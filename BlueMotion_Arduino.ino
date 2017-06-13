

int trigPin = 7; 
int echoPin = 8; 
int led = 13;

long maxcm;
boolean firsttime = true;
boolean done = false;


void setup() {
 // initialize serial communication:
 Serial.begin(9600);
 
 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);

 digitalWrite(trigPin, LOW);
 
 pinMode(led,OUTPUT);
}

void loop()
{
 // establish variables for duration of the ping, 
 // and the distance result in inches and centimeters:
 long duration, inches,cm;
 //String str;
 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);

 duration = pulseIn(echoPin, HIGH);

 // convert the time into a distance
 cm = microsecondsToCentimeters(duration);
 inches = microsecondsToInches(duration);
 //Serial.println(String(inches));
 
 
    if (firsttime == true)
    {
      maxcm = 80;
      firsttime = false;
      Serial.println("Max: " + String(maxcm));
    }
  
  if (cm < maxcm)
  {
    if(done == false)
    {
      digitalWrite(led,HIGH);
      Serial.println("Proximity Alert" + String(cm) + " Cm");
      
    } 
  }
  else
  {
    digitalWrite(led,LOW);
    done = false;
  }
  
 delay(50);
}

long microsecondsToInches(long microseconds)
{
 
 return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{

 return microseconds / 29 / 2;
}
