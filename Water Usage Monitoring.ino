#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 8);

int TURBINE;      //pengukuran SINYAL data yang bersifat incremental
int HSensor = 2; //nama alias pada pin 2
int Calc;
 
void speedrpm ()    //fungsi penghitungan dan interrupt
{
TURBINE++; //bersifat incrementing (dengan mode falling edge)
}
 
void setup() 
{
lcd.begin(20,4);
pinMode(HSensor, INPUT); //inisialisasi sebagai input
Serial.begin(9600); 
attachInterrupt(00, speedrpm, RISING); //cara penulisan perintah interrupt

}
 
void loop ()
{
TURBINE = 00; //data awal = 0
sei(); //perintah aktifnya mode interrupt
delay (1000); //nilai delay 1 detik
cli(); //perintah untuk matinya program interrupt
Calc = (TURBINE * 60 / 7.5); //Pulsa * 60 / 7.5 
 
//satuan FLOW RATE benda cair yaitu L / hour
lcd.setCursor(0,0);
lcd.print("Debit : ");
lcd.print(Calc,DEC);
lcd.print(" ");
Serial.print(Calc, DEC); //menampilkan hasil pembacaan kalkulasi flow rate dalam bentuk dec di serial monitor 
Serial.print(" L/hour\r\n"); //Tampilkan L / hour pada baris baru
}
