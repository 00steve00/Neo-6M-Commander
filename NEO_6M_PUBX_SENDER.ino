//use this define to specify which hardware serial port for output
#define SERIAL_PORT Serial1

/* CONFIGURING THE UBLOX NEO 6M - COMMANDS
 *  This sketch sends PUBX commands to a Ublox NEO 6M GPS module. 
 *  Commit date: March 4, 2020
*TO DISABLE ZDA MESSAGES:
$PUBX,40,ZDA,0,0,0,0,0,0*44
TO ENABLE ZDA MESSAGES:
$PUBX,40,ZDA,0,1,0,0,0,0*45
checksum is HEX value of XOR over everything between $ and *
*/

const char payload[] = {"$PUBX,40,ZDA,0,1,0,0,0,0*"}; //must start '$' and end '*' as delimiter!!

void send_payload() {

  byte checksum = 0;
  byte i = 0;
  if (payload[i] != '$') {
    return;
    }
  SERIAL_PORT.print(payload[i]);
  i++;
  while (payload[i] != '*') {
      SERIAL_PORT.print(payload[i]);
      checksum ^= payload[i];
      i++;
  } //end while
  SERIAL_PORT.print("*");
  SERIAL_PORT.print(checksum,HEX);
  SERIAL_PORT.print("\r");
  SERIAL_PORT.print("\n");
  
} //end send_payload


void setup() {
  // put your setup code here, to run once:

  delay(250);
  SERIAL_PORT.begin(9600);
  delay(250);

  send_payload();

  
} //end setup

void loop() {
  // put your main code here, to run repeatedly:

} //end loop
