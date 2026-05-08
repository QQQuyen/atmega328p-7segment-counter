void setup() {
  DDRD |= 0x0F;   // PD0-PD3 output
  DDRB |= 0x0F;   // PB0-PB3 output
}

void loop() {
  static uint8_t count = 0;

  // PD giữ nguyên
  PORTD = (PORTD & 0xF0) | (count & 0x0F);

  // Đảo thứ tự bit sang PB4 -> PB0
  uint8_t reversed =
      ((count & 0x01) << 3) |   // b0 -> PB3
      ((count & 0x02) << 1) |   // b1 -> PB2
      ((count & 0x04) >> 1) |   // b2 -> PB1
      ((count & 0x08) >> 3);    // b3 -> PB0

  PORTB = (PORTB & 0xF0) | reversed;

  delay(500);

  count++;
  if(count > 9) count = 0;
}