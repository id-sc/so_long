*This project has been created as part of the 42 curriculum by hesainte*

# so_long — 42 Project

## 💡 Overview

**so_long** is a 2D game developed in C using the **MiniLibX** graphical library.  
The objective of this project is to build a small game engine from scratch, handling:

- Window creation and management
- Texture and sprite rendering
- Keyboard input
- Game logic and state management

The player must navigate through a map, collect all required items, and reach the exit — while avoiding enemies.

---

## 🎮 Theme & Story

To personalize the project, I created a custom universe and original assets.

**Story:**  
You play as a Bubble Tea character on a mission to recover your lost tapioca pearls and become whole again.  
But beware — hungry cats are lurking, ready to drink you up if you get too close 🐱🧋

---

## 🎨 Visual & Gameplay Features

- **Animated Collectibles**  
  Tapioca pearls blink and scale dynamically to draw attention.

- **Progressive UI**  
  The cup visually fills up as pearls are collected.

- **Custom Game States**
  - **Victory:** Reach the exit after collecting all pearls — your cup gets its lid!
  - **Defeat:** Get caught by a cat and… you get drunk by the cat.

---

## 🗺️ Map System

The game reads a `.ber` map file to generate the world.  
Each character represents a specific entity:

| Character | Entity       | Description                                  |
|----------|--------------|----------------------------------------------|
| `0`      | Empty        | Walkable space                               |
| `1`      | Wall         | Obstacle blocking movement                  |
| `C`      | Collectible  | Tapioca pearls to collect                   |
| `E`      | Exit         | Reach after collecting all items            |
| `P`      | Player       | Player starting position                    |
| `X`      | Enemy        | **(Bonus)** Avoid to stay alive              |

---

## 🚀 Getting Started

### Compilation

Compile the project using the provided `Makefile`:

```bash
make
```

### Usage

Launch the game with a custom map:

```bash
./so_long maps/level1.ber
```

Or run it without arguments to load a default map.

## 🎮 Controls

You can navigate your character using either the keyboard letters or the arrow keys:

| Key | Action |
| --- | --- |
| **W / Up Arrow** | Move Up |
| **A / Left Arrow** | Move Left |
| **S / Down Arrow** | Move Down |
| **D / Right Arrow** | Move Right |
| **ESC** | Close the game |


## 🛠️ Methodology & Resources

### 🔍 Learning MiniLibX

I started by understanding how to open a window and draw pixels, then gradually progressed to rendering textures and sprites using XPM images.

* **MiniLibX Tutorial:** [42 Docs - Getting Started](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
* **Game Logic Guide:** [Building your first 2D game in C](https://medium.com/@digitalpoolng/42-so-long-and-thanks-for-all-the-fish-building-your-first-2d-game-in-c-ccd24034bc8b)

### 🎨 Design & Art Direction

All visuals were designed by me. The creative workflow included:

**Concept Drafting:** Using AI to explore visual ideas and refine the storyline. [alt text](img/image.png)

**Manual Redrawing:** Reworking all assets by hand to match my personal style and technical constraints.

### 🤖 AI Optimization

AI acted as a technical consultant during development:

* **Code Refactoring:** It helped me condense functions and split large blocks of code into smaller, modular helpers.
* **Pathfinding & Logic:** AI assisted in ensuring the game logic remained solid, explaining where I went wrong when I went off track.

---

### Created by

Heidi Sainte-Catherine (*hesainte*)

---
