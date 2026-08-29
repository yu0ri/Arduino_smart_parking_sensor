const int butonPin = 2;
const int trigPin = 3;
const int echoPin = 4;
const int buzzerPin = 11;
const int redPin = 9;
const int yellowPin = 10;
const int greenPin = 8;

bool sistemAcik = false;
int sonbutonDurumu = HIGH;
unsigned long sonbutonZamani = 0;
unsigned long sonbuzzerZamani = 0;

void setup(){
  pinMode(butonPin, INPUT_PULLUP);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(96500); //seri port ekranı (mesafeyi ekrandan görmek için)
}

void loop(){
  //açma kapatma kontrolü (1)
  int butonOkuma = digitalRead(butonPin);
  if (butonOkuma == LOW && sonbutonDurumu == HIGH && (millis() - sonbutonZamani > 200)){
    sistemAcik = !sistemAcik; //açık ise kapat, kapalı ise aç
    sonbutonZamani = millis();

    //sistem kapandığında herşeyi sustur ve söndür
    if (sistemAcik) {
      digitalWrite(8, LOW);
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      noTone(buzzerPin);
    }
  }
sonbutonDurumu = butonOkuma;

 //sistem açıksa mesafe ölç. ve kontrol (2)
 if (sistemAcik){
  //mesafe sensöründe ölçüm alma mantığı
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long sure = pulseIn(echoPin, HIGH);
  int mesafe = sure * 0.034 / 2; //ses hızından mesafe hesaplama (cm)

  //mesafe bilgileri ve kontrolü
  //KIRMIZI (0-15cm)
  if(mesafe > 0 && mesafe <= 15) {
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(8, LOW);

    tone(buzzerPin, 1000); //kesintisiz bağırma
  }
  //SARI (15-30cm)
  else if(mesafe > 15 && mesafe <=30) {
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(8, LOW);

    //3 SANİYEDE 1 BİPLEME
    if (millis() - sonbuzzerZamani >= 1000) {
      tone(buzzerPin, 1000, 200); //1000hz de 200ms ses çıkar
      sonbuzzerZamani = millis();

    }
  }
  //YEŞİL (30+cm)
  else if(mesafe >30) {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(8, HIGH);

    noTone(buzzerPin); //buzzer susar
  }

  delay(50); //sensör kararlılığı için bekleme
}
}


