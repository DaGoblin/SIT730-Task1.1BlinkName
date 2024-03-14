
int timeUnit = 500;
String inputText = "Phil";
const int buttonPin = 2;
int buttonState = 0;
volatile bool isRunning = false;
volatile bool buttonPressed = false;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT);
  inputText.toLowerCase();
  attachInterrupt(digitalPinToInterrupt(buttonPin),handelButtonPress, RISING);
}


void loop() {

  if (buttonPressed){
    isRunning = true;
    buttonPressed = false;
  }

  if (isRunning){
    read_text();
    isRunning = false;
  }
}

void handelButtonPress() {
  isRunning = false;
  buttonPressed = true;
  digitalWrite(LED_BUILTIN, LOW); //turns the LED off if it's already on part way through a dash or dot.
}


void dash(){
  if(!isRunning) return; //check to see if the program run has been interupted
  digitalWrite(LED_BUILTIN, HIGH);
  delay(timeUnit*3);
  digitalWrite(LED_BUILTIN, LOW);
  delay(timeUnit);
}

void dot(){
  if(!isRunning)return; //check to see if the program run has been interupted
  digitalWrite(LED_BUILTIN, HIGH);
  delay(timeUnit);
  digitalWrite(LED_BUILTIN, LOW);
  delay(timeUnit);
}

void read_text(){

  for (int i = 0; i <  inputText.length(); i++){
    letterLookUp(inputText[i]);
    if(!isRunning)return;
    delay(timeUnit*3); // 3 units for gap between letters
  }
  //delay(timeUnit*7); //7 units for gap between words

}

//while it is a poor convertion to put multiple statements on a single line, I feel it makes sense when reading Morse code in this case.
void letterLookUp(char letter){
  

  switch (letter) {
  case 'a':
    dot(); dash();
  break;
    
  case 'b':
    dash(); dot(); dot(); dot();
  break;
    
  case 'c':
    dash(); dot(); dash(); dot();
  break;

  case 'd':
    dash(); dot(); dot();
  break;
  
  case 'e':
    dot();
  break;
  
  case 'f':
    dot(); dot(); dash(); dot();
  break;
  
  case 'g':
    dash(); dash(); dot();
  break;
  
  case 'h':
    dot(); dot(); dot(); dot();
  break;
  
  case 'i':
    dot(); dot();
  break;
  
  case 'j':
    dot(); dash(); dash(); dash();
  break;
  
  case 'k':
    dash(); dot(); dash();
  break;
  
  case 'l':
    dot(); dash(); dot(); dot();
  break;
  
  case 'm':
    dash(); dash();
  break;
  
  case 'n':
    dash(); dot();  
  break;
  
  case 'o':
    dash(); dash(); dash();    
  break;
  
  case 'p':
    dot(); dash(); dash(); dot(); 
  break;
  
  case 'q':
    dash(); dash(); dot(); dash();  
  break;
      
  case 'r':
    dot(); dash(); dot();
  break;
  
  case 's':
    dot(); dot(); dot();
  break;
    
  case 't':
    dash();
  break;
  
  case 'u':
    dot(); dot(); dash();
  break;
    
  case 'v':
    dot(); dot(); dot(); dash();
  break;
    
  case 'w':
    dot(); dash(); dash();
  break;
    
  case 'x':
    dash(); dot(); dot(); dash();
  break;
    
  case 'y':
    dash(); dot(); dash(); dash();
  break;
    
  case 'z':
    dash(); dash(); dot(); dot();
  break;
    
  case ' ':
    delay(timeUnit*7);
  break;

  default:
    digitalWrite(LED_BUILTIN, LOW);
  break;

  }

}