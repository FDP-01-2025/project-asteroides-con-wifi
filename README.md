[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)

# Proyecto de C++ - OWL ROCKET 🚀

## 👨‍🚀 Team

- **Team name:** Asteroides con WiFi
- **Nombre del juego:** OWL ROCKET

| Name   | ID|
|--------|--------|
| Leila Saraí Campos Peraza | 00141525 |
| Rubén Eliseo Martínez Perez | 00076325 |
| Álvaro David Campos Jimenez | 00135525 |
| Keiryn Lisette Diaz Cartagena | 00061225 |
| Christian Alexis Martinez Moran | 00053325 |

---

## 🧠 Theme and setting

 You need to go with **Noctriz** in a space adventure full of missions to save all the population of  **Algoritmia**, they have been kidnapped by an AI.This game implies logic in different ways ,memory and chanllenges across the intersllestar space. 

---

## 🎮  Principal Game Mechanic 

The player will face different  **missions** in different planets:

- Solve logic puzzles.
- Find supplies(memogram).
- Find passwords.
- Participate in a space career.

Each mission corresponds to a module of the program and allows access to an interactive menu . This menu lets the player choose the planet they would like to start with, which will be their first destination .
---

## 🕹️ General gameplay idea 

1. The player starts with Noctriz, astronaut of Algoritmia.

2. The player can choose between differents missions in the pincipal menu. 

3. Each mission in every minigame has its own logic and mechanics.

4. Each dessicion and it's results will appear at the console.

5. After completing all the missions, the player frees Algoritmia from the AI.

---

## 💻 Applying the concepts learned

## 🎓 Course Topics & Game Application

| **Course Topic**                | **Application in the Game**                                                                 |
| **Variables and Data Types**    | Uses `int`, `float`, `bool`, and `string` variables in missions to control game mechanics.  |
| **Conditional Structures**      | Uses `if`, `else`, and `switch` statements to manage player decisions and mission outcomes. |
| **Loops (for, while, do-while)**| Used for attempt repetition, data validation, and managing in-game interactions.            |
| **Functions**                   | Each mission and utility is encapsulated in functions (e.g., `startMission1()`, etc.).     |
| **Data Structures**             | Arrays like `string[]` and `int[]` are used in minigames to store and manage game data.    |
| **File Handling**               | Player scores are saved and retrieved using `fstream`.                                     |
| **Error Handling**              | Input validation prevents crashes by handling incorrect or unexpected user input.          |
| **Console Interface**           | Menus and UI elements are built using `cout`, `cin`, separators, and ASCII Art.            |
---

## 🛠️Technical Considerations of Development

- Lenguage: C++
- Used IDE : Visual Studio Code
- Repository shared in GitHub
- Modularization: Each mission is contained in its own`.cpp` and `.h`
- The `main.cpp`  file only includes calls to the primary functions of each mission **OWL ROCKET**.

---

## ▶️ Instrucciones de Ejecución

1. Clone this repository:
   ```bash
   git clone https://github.com/FDP-01-2025/project-asteroides-con-wifi.git

2. Open the poject with IDE or an code Editor.

3. Compile the file in the terminal:

   *g++ -o owlrocket ./main.cpp*

4. Run the game with the following command

   *./owlrocket.exe*
