# 🎨 **miniRT**  

A simple yet functional ray tracer written in **C** and **MiniLibX**, developed as part of the 42 School curriculum.
This project introduces the fundamentals of **computer graphics**, **mathematics**, and **geometry**, allowing you to generate 3D images from a custom .rt scene file.  

# 🧩 **Overview**  

The goal of miniRT is to render a 3D scene composed of simple geometric shapes — spheres, planes, and cylinders — from a specific camera point of view.
The rendering is performed using the **Ray Tracing algorithm**, which simulates light rays interacting with objects to produce realistic images.  

# ⚙️ **Features**  

- Written in **C(C99)** using **MiniLibX**  
- **Ray tracing engine** with intersection handling
- **Ambient and diffuse lighting** (hard shadows)
- **Scene parsing** from .rt files
- Support for Plane (pl), Sphere (sp) and Cylinder (cy)
- **Camera** and **light transformations** (translation, rotation)
- Real-time window display
- Graceful exit with ESC key or window close (red cross)


# 🧠 Ray Tracing Concepts  

miniRT implements the fundamental parts of a ray tracer:  
- Ray generation from the camera through each pixel
- Intersection detection between rays and objects
- Lighting computation (ambient + diffuse)
- Shadow casting (hard shadows)
- Color computation based on light intensity and object color

# 🗂️ Scene File Format (.rt)  

