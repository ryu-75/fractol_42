# Fract-ol

## Description
This is the first graphical project at 42 school. The goal was to generate the most beautiful fractals from the complex numbers of an iterative mathematical construct.
This project uses the graphical library, MiniLibX.

## Usage

--- 

Note that this project was tested on Linux only. It may run on MacOS with small adjustments to the Makefile, as described in hsmits and jvan-sni's [42 Docs](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html).

---

## Installing and Compiling

Clone the repository:
```shell
git clone git@github.com:ryu-75/fractol_42.git && cd fractol_42 && git submodule init && git submodule update
```

You will now be in the correct directory for compilation.
Compile with ```make```.
Fract-ol should now be ready !

## Executing

At execution, you must specify a fractal to display. 
You may also provide other optional parameters:

```shell
./fractol <type> <option>
```

Types are :
* ```mandelbrot```: Mandelbrot fractal
* ```julia```: Julia fractal
* ```"burning ship"```: Burning sheep fractal

For the julia fractal set, two additional parameters can be specified as calculation values.
These represent a complex number that will change the shape of the Julia fractal. They must be fractional numbers between 2.0 and -2.0. For example:

```shell
./fractol julia 0.310 0.015
```

## Fract-ol controls

<table>
  <tr><td><strong>Controls</strong></td><td><strong>Action</strong></td></tr>
  <tr><td><kbd>&nbsp;▲&nbsp;</kbd><kbd>&nbsp;◄&nbsp;</kbd><kbd>&nbsp;▼&nbsp;</kbd><kbd>&nbsp;►&nbsp;</kbd></td><td>Move</td></tr>
  <tr><td><kbd>&nbsp;-&nbsp;</kbd>, <kbd>&nbsp;+&nbsp;</kbd> or <kbd>&nbsp;scroll wheel&nbsp;</kbd></td><td>Zoom in and out</td></tr>
  <tr><td><kbd>&nbsp;m or M&nbsp;</kbd>, <kbd>&nbsp;j or J&nbsp;</kbd>, <kbd>&nbsp;b or B&nbsp;</kbd></td><td>Switch fractals</td></tr>
  <tr><td><kbd>&nbsp;esc&nbsp;</kbd> or close window</td><td>Quit fract-ol</td></tr>
</table>

# Screenshots

## Mandelbrot set
![mandlebrot](https://github.com/ryu-75/fractol_42/assets/79263476/f10bba39-ebde-4726-bf76-f057ee3f4288)

## Julia set
![Julia01](https://github.com/ryu-75/fractol_42/assets/79263476/923f7fdf-9b37-4505-9f28-88b7721f66cf)
![Screenshot from 2024-04-02 19-06-38](https://github.com/ryu-75/fractol_42/assets/79263476/f725cb39-826e-4b25-a040-2f013304f26e)

## Burning ship set
![Screenshot from 2024-04-04 17-13-46](https://github.com/ryu-75/fractol_42/assets/79263476/3884f487-1bf3-418c-9583-dde055f8cf7e)

