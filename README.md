# 🎨 Fract-ol: Fractal Exploration Engine

![demo](https://github.com/user-attachments/assets/160fd23a-18ba-486d-8fd7-2aefc1b6696a)


> **A high-performance fractal rendering engine built in C using the MiniLibX library.**

This project involves rendering mathematically complex fractal sets (Mandelbrot, Julia, Burning Ship) and creating an interactive tool to explore them. It demonstrates deep understanding of **complex numbers**, **optimization algorithms**, and **graphics programming**.

---

### ✨ Features

* **Fractal Sets:** Renders classic sets including **Mandelbrot** and **Julia**.
* **Interactive Exploration:**
    * 🖱️ **Infinite Zoom:** Smooth zooming via mouse wheel towards the cursor.
    * ↔️ **Panning:** Move around the coordinate system using arrow keys.
    * 🎨 **Psychedelic Colors:** Shift color palettes dynamically to visualize iteration depths.
* **Dynamic Julia:** Modify the complex constant of the Julia set simply by moving the mouse cursor.

---

### 🧠 Engineering Challenges

Rendering fractals is computationally expensive because every single pixel requires iterating a mathematical formula potentially hundreds of times.

* **Optimization:** The code is optimized to render frames smoothly without lag, handling millions of calculations per second.
* **Complex Math:** Implemented complex number arithmetic and coordinate system mapping (screen space to complex plane) from scratch in C.
* **Event Handling:** Managing keyboard and mouse hooks via MiniLibX for a responsive user experience.

---

### 🚀 How to Run

**Requirements:** `gcc`, `make`, `MiniLibX` (usually available on 42 school machines or Linux with X11).

```bash
# 1. Clone the repository
git clone [https://github.com/GulcB/42_Fractol.git](https://github.com/GulcB/42_Fractol.git)

# 2. Enter the directory
cd 42_Fractol

# 3. Compile
make

# 4. Run with a fractal name
./fractol mandelbrot
# OR
./fractol julia
