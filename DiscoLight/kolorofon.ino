
int soundPin1 = A0; //deklaracja wejścia analogowego
//used to indicate the initial values of system on starting
void setup() {
  Serial.begin(9600); //monitor portu szeregowego
  pinMode(3,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT); //nasze wyjścia
}

//contains the statements that will run whenever the system is powered aftersetup
void loop() 
{
 int soundPin1Reading; //zmienna z wartością naszego wejścia
 
 if (analogRead(soundPin1)<8) //eliminowanie zakłóceń, poniżej tej wartości
                              //diody nie zapalają się
 {
   soundPin1Reading=0;        //przypisanie wartości 0
 }
 else
 {
   soundPin1Reading=analogRead(soundPin1); //jeśli wartość jest wyższa
 }                                         //przypisujemy ją do zmiennej
 
 
 Serial.println(soundPin1Reading);  //wyświetlamy naszą wartość w monitorze 
                                    //portu szeregowego
 
 int a=soundPin1Reading*10;// zmienna mocy świecenia dla pinu 3
 int b=soundPin1Reading*12;// zmienna mocy świecenia dla pinu 5
 int c=soundPin1Reading*16;// zmienna mocy świecenia dla pinu 6
 int f=(soundPin1Reading/255)*20; //zmienna opóźnienia 
 
//przykład: mp4 na analogu daje sygnał 10, mnożymy przez 10 i dioda zapala się
//napęciem (100/255)*5V czyli około 1.96V
 
 analogWrite(3,a);
 analogWrite(5,b);
 analogWrite(6,c);//zapalanie diód
 
  delay(f);//opóźnienie do wygaszenia
 
 analogWrite(3,0);
 analogWrite(5,0);
 analogWrite(6,0);//wygaszanie ich
 
 delay(f);//opóźnienie między cyklami
}
