char serialFunction;
char serialTarget;
int serialRelay;
int relayPin;
boolean data;

void setup() { 

  pinMode(30, OUTPUT); //Power OFF = ID:1
  digitalWrite(30, HIGH);
  pinMode(31, OUTPUT); //Pi = ID:2
  digitalWrite(31, HIGH);
  pinMode(32, OUTPUT); //AP = ID:3
  digitalWrite(32, HIGH);
  pinMode(33, OUTPUT); //Switch = ID:4
  digitalWrite(33, HIGH);
  pinMode(34, OUTPUT); //SPARE = ID:5
  digitalWrite(34, HIGH);
  pinMode(35, OUTPUT); // SPARE = ID:6
  digitalWrite(35, HIGH);
  pinMode(36, OUTPUT); // SPARE = ID:7
  digitalWrite(36, HIGH);
  pinMode(37, OUTPUT);
  digitalWrite(37, LOW);
  delay(1000);
  digitalWrite(37, HIGH);

  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.print("Ready");
  Serial1.print("666");
}

// the loop function runs over and over again forever
void loop() {
  // send data only when you receive data:
  while (Serial.available() > 2){
    serialTarget = Serial.read();
    if ((String) serialTarget == "A") {
      serialFunction = Serial.read();
      serialRelay = Serial.parseInt();
      data = true;
    }
  }
  while (Serial1.available() > 2){
    serialTarget = Serial.read();
    if ((String) serialTarget == "A") {
      serialFunction = Serial.read();
      serialRelay = Serial.parseInt();
      data = true;
    }
  }
  if (data) {
    Serial.print("Function:");
    Serial.println((String) serialFunction);
    Serial.print("Relay:");
    Serial.println(serialRelay);
    if ((String) serialFunction == "O") {
      if (serialRelay == 1) digitalWrite(30, LOW);
      if (serialRelay == 2) digitalWrite(31, LOW);
      if (serialRelay == 3) digitalWrite(32, LOW);
      if (serialRelay == 4) digitalWrite(33, LOW);
      if (serialRelay == 5) digitalWrite(34, LOW);
      if (serialRelay == 6) digitalWrite(35, LOW);
      if (serialRelay == 7) digitalWrite(36, LOW);  
    }

    if ((String) serialFunction == "X") {
      if (serialRelay == 1) digitalWrite(30, HIGH);
      if (serialRelay == 2) digitalWrite(31, HIGH);
      if (serialRelay == 3) digitalWrite(32, HIGH);
      if (serialRelay == 4) digitalWrite(33, HIGH);
      if (serialRelay == 5) digitalWrite(34, HIGH);
      if (serialRelay == 6) digitalWrite(35, HIGH);
      if (serialRelay == 7) digitalWrite(36, HIGH);  
    }

    // if ((String) serialFunction = "X") digitalWrite(serialRelay + 2, HIGH); WHY DOESN'T THIS WORK???
    data = false;
  }
}

