# HAck pad

## Overview

HAck pad is a custom PCB project using a Seeed XIAO-compatible module and three Cherry MX-style push switches. The supplied KiCad project contains the schematic and PCB layout.

## Final PCB

![Final PCB](images/final_pcb.png)

The image above is an overview of the supplied PCB layout, showing the board outline, the XIAO module footprint, and three switch positions.

## CAD

![Final CAD](images/final_cad.png)

A STEP model has been generated from the supplied `Shiny Densor.stl` mesh and is included in the `CAD` folder as `Shiny_Densor.step`.

> Note: the STEP model is a faceted conversion of the supplied STL mesh. If the original design was created in a parametric CAD program, the native CAD model should be preferred for future modification.

## Hardware

The supplied BOM identifies:

- U1: `MOUDLE-SEEEDUINO-XIAO`
- SW1, SW2, SW3: `SW_Push`
- Switch footprint: `Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB`
- U1 footprint: `XIAO-Generic-Hybrid-14P-2.54-21X17.8MM...`

See [BOM.csv](BOM.csv) for the generated bill of materials.

## Repository Structure

```text
CAD/
  Shiny_Densor.step
  Shiny_Densor.stl

Firmware/
  README.txt

PCB/
  HAck_pad.kicad_pro
  HAck_pad.kicad_sch
  HAck_pad.kicad_pcb

Production/
  README.txt

images/
  final_pcb.png
  final_cad.png

BOM.csv
README.md
```

## Manufacturing

The final Gerber ZIP is **not included yet** because Gerber files must be plotted from the final KiCad PCB using KiCad's fabrication-output tools. The firmware source was also not present in the uploaded files.

Before submission, generate the Gerbers and drill files from `PCB/HAck_pad.kicad_pcb`, put them into `Production/gerber.zip`, and add the final firmware source to `Firmware/` and `Production/`.

## License

Add the project's license here.
