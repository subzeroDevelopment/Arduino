char rxChar;    // Variable para recibir datos del puerto serie
 
// Configurar el arduino
void setup()
{
  // Comunicación serie a 9600 baudios
  Serial.begin(9600);
}
 
// Ciclo infinito, programa principal
void loop()
{
  // Si hay datos disponibles en el buffer
  if( Serial.available() )
  {
    // Leer un byte y colocarlo en variable
    rxChar = Serial.read();
    Serial.println(rxChar);
  }
 
}
