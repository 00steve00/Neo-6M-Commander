# Neo-6M-Commander
Arduino sketch that sends UBX commands via hardware serial to a ublox Neo 6M GPS unit

For UBX Protocol command documentation, see:
See https://www.u-blox.com/sites/default/files/products/documents/u-blox6_ReceiverDescrProtSpec_%28GPS.G6-SW-10018%29_Public.pdf
  Specifically, Section 21 "Proprietary Messages"
  
  The example provided in the sketch can be used for toggling different NMEA sentences in the output.
  Specifically, see section 21.11 UBX,40 "Set NMEA message output rate".
  
  The sketch could be adapted to send any other UBX formatted commands as described in section 21.
