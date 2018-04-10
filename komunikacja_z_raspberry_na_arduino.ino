const int ledPin = 13;
int n=10;
String odebrane;
bool odbieranie =1;
char a;

void setup(){
pinMode(ledPin, OUTPUT);
Serial.begin(9600); //rozpoczęcie komunikacji szeregowej
}

void loop(){
  odebrane = "";                            //od
  odbieranie = 1 ;
if(Serial.available()){  
  while(Serial.available()&&odbieranie) {
    a = Serial.read();                      //odebranie bajt po bajcie i zapisuje w stringu
    if(a=='.'){
      odbieranie = 0;
    }
    odebrane += a;
  }                                           //do
  digitalWrite(ledPin, HIGH);
  Serial.println(odebrane);   // send the data        wysyłanie
  digitalWrite(ledPin, LOW);
  //light(int(Serial.read()));
  }
else{
  Serial.println("Nic");   // send the data         
}
}

/*void light(int n){
  for (int i = 0; i < n; i++) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
}*/
