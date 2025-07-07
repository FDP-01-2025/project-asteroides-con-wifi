[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)

# Proyecto de C++ - OWL ROCKET 🚀

## 👨‍🚀 Equipo

- **Nombre del equipo:** Asteroides con WiFi
- **Nombre del juego:** OWL ROCKET

| Nombre | Carnet |
|--------|--------|
| Leila Saraí Campos Peraza | 00141525 |
| Rubén Eliseo Martínez Perez | 00076325 |
| Álvaro David Campos Jimenez | 00135525 |
| Keiryn Lisette Diaz Cartagena | 00061225 |
| Christian Alexis Martinez Moran | 00053325 |

---

## 🧠 Temática y Ambientación

Acompaña a **Noctriz** en un viaje espacial lleno de misiones para salvar a los habitantes de **Algoritmia**, quienes han sido secuestrados por una IA hostil. El juego mezcla lógica, memoria, y velocidad en un entorno de aventura interestelar.

---

## 🎮 Mecánica Principal

El jugador enfrentará distintas **misiones** en diferentes planetas:

- Resolver acertijos de lógica
- Encontrar suministros (memorama)
- Descifrar contraseñas
- Participar en una carrera espacial

Cada misión corresponde a un módulo del programa y se accede a través de un menú interactivo por consola donde el usuario puede seleccionar a que planeta desea iniciar primero en su destino.

---

## 🕹️ Idea General de la Jugabilidad

1. El jugador inicia como Noctriz, astronauta de Algoritmia.

2. Puede elegir entre varias misiones desde un menú principal.

3. Cada misión es un minijuego con su propia mecánica y lógica.

4. Las decisiones y resultados se ven reflejados en mensajes por consola.

5. Al completar todas las misiones, el jugador libera Algoritmia de la IA.

---

## 💻 Aplicación de los Temas Vistos

| Tema del Curso | Aplicación en el Juego |
|----------------|------------------------|
| **Variables y tipos de datos** | Se usan `int`, `float`, `bool`, `string` en misiones y control del flujo del juego. |

| **Estructuras condicionales (if, else, switch)** | Control de decisiones, menús, resultados de las misiones. |

| **Ciclos (for, while, do while)** | Repetición de intentos, validación de datos, interacción dentro de las misiones. |

| **Funciones** | Cada misión y utilidad está encapsulada en funciones (ej. `startMission1()`, etc). |

| **Estructuras de datos** | Se utilizan arreglos (`string[]`, `int[]`) para los minijuegos. |

| **Manejo de archivos** | Se guardan puntajes en archivo usando `fstream`. |
| **Manejo de errores** | Se verifica la entrada de datos de el usuario para que el juego no colapse en algún punto. |
| **Interfaz por consola** | Menús con `cout`, `cin`, separadores, uso de ASCII Art para estética. |

---

## 🛠️ Consideraciones Técnicas del Desarrollo

- Lenguaje: C++
- IDE usado: Visual Studio Code
- Repositorio compartido en GitHub
- Modularización: Cada misión está en su propio archivo `.cpp` y `.h`
- El archivo `main.cpp` solo contiene las llamadas a funciones principales de **OWL ROCKET**.

---

## ▶️ Instrucciones de Ejecución

1. Clona este repositorio:
   ```bash
   git clone https://github.com/FDP-01-2025/project-asteroides-con-wifi.git

2. Abre el proyecto con un IDE o Editor de Código.

3. Compila el archivo en la terminal, pulsa windows+ñ y luego compila el `main.cpp` con el siguiente comando:

   *g++ -o owlrocket ./main.cpp*

4. Ejecuta el juego con el comando:

   *./owlrocket.exe*
