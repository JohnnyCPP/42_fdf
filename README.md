# FDF

"FDF" stands for *Fil De Fer* in French, which literally means Metal Wire, but refers to a Wireframe Model.

## Project Overview

![42](./resources/42_madrid.jpg "42")

> 42 Madrid is an academy for values, attitude and learning "hard and soft skills" in the digital environment.
<br>
FDF is a project in the graphics branch of the 42 curriculum. It involves creating a 3D wireframe representation of a landscape or a map.

The goal of the project is to render a 3D wireframe model from a 2D map or grid. Students use C and MiniLibX graphics library to create this visualization.

- The input is a file containing a 2D grid where numbers represent heights
- The 2D map is transformed into a 3D wireframe model using mathematical transformations
- Only the edges of the shapes are drawn, creating a "wireframe" effect
- This project contains optional features, including: zooming, rotating, translating, and switching projection

## Run

Clone the repository and run the following make targets:

```bash
git clone https://github.com/JohnnyCPP/42_fdf.git
cd 42_fdf
make help
make fdf
./fdf ./maps/42.fdf
# to run debugging tools
make sanitize
# or
make valgrind
# to build the bonus version
make bonus
# if the standard version is present, 
# clean the project before building the bonus version
make fclean
make bonus
