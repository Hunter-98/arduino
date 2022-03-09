#include <TimeLib.h>
#include <Time.h>

// C++ code
//
//AUTHOR: HERNANDEZ GARCIA ROBERTO
//PROYECTO: Primeros programas en arduino

/*NOTAS DE CLASE
 * PYTHON ES UN LENGUAJE DE INTERPRETACION Y ARDUINO ES UN LENGUAJE COMPILADO
 * PORLOTANTO PYTHON OBEDECE A LA IDENTACION 
 */
  

void setup(){
  Serial.begin(9600);
  pinMode(2, INPUT); // Boton de inicio  
  pinMode(3, INPUT); // Boton para Parar
  Serial.println("Presione 1 para Inicio/reset, 2 para parar tiempo transcurrido"); 
  
}

    void Resultado(){
unsigned long Ttranscurrido, finalizado, inicio;
    float h, m,s, ms;
    unsigned long terminado;
    Ttranscurrido = finalizado - inicio;

    h = int(Ttranscurrido / 3600000);
    terminado = Ttranscurrido % 3600000; 
    m = int(terminado / 60000);
    terminado = terminado % 60000;
    s = int(terminado / 1000);
    ms = terminado % 1000; 
    Serial.print("Tiempo transcurrido : "); 
    Serial.println(Ttranscurrido);
    Serial.print("Tiempo transcurrido detallado: ");
    Serial.print(h, 0);
    Serial.print("h ");
    Serial.print(m, 0);
    Serial.print("m ");
    Serial.print(s, 0);
    Serial.print("s ");
    Serial.print(ms, 0);
    Serial.println("ms");
    Serial.println();
    }



  
void loop(){
  unsigned long Ttranscurrido, finalizado, inicio;
  if (digitalRead(2) == HIGH)
      { 
       inicio = millis();
       delay(300); //  por rebote 
       Serial.println("Inicializar...");
      } 
      if (digitalRead(3) == HIGH)
      { 
        finalizado = millis();
        delay(300); // por rebote 
        Resultado(); 
       }
  }
