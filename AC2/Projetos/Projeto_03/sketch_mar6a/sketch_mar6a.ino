int entrada1;
int entrada2;
int entrada3;

int ledVermelho = 13;
int ledAmarelo = 12;
int ledVerde = 11;
int ledAzul = 10;

int saida;
int vai1;

void setup()
{
  Serial.begin(9600);

  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
}

void loop()
{
  if (Serial.available() > 0)
  {
    entrada1 = Serial.parseInt();
    entrada2 = Serial.parseInt();
    entrada3 = Serial.parseInt();

    Serial.print("a = ");
    Serial.println(entrada1);
    Serial.print("b = ");
    Serial.println(entrada2);
    Serial.print("op = ");
    Serial.println(entrada3);

    // mostrar entradas
    digitalWrite(ledVermelho, entrada1);
    digitalWrite(ledAmarelo, entrada2);

    vai1 = 0;

    if (entrada3 == 0) // AND
    {
      saida = entrada1 & entrada2;
    }

    if (entrada3 == 1) // OR
    {
      saida = entrada1 | entrada2;
    }

    if (entrada3 == 2) // NOT
    {
      saida = !entrada1;
    }

    if (entrada3 == 3) // SOMA
    {
      saida = entrada1 ^ entrada2;
      vai1 = entrada1 & entrada2;
    }

    digitalWrite(ledVerde, saida);
    digitalWrite(ledAzul, vai1);

    Serial.print("saida = ");
    Serial.println(saida);

    Serial.print("vai1 = ");
    Serial.println(vai1);
  }
}