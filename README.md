# Portable Photobioreactor
## FabAcademy Microchallenge 3
[Paula Del Rio Arteaga](https://paula-delrio-arteaga.github.io/mdef/)
[Pippa Formosa](https://philippa-formosa.github.io/mdefweb/)
[Marina Lermant](https://marina-lermant.github.io/mdef-website/)

Design and make an **ethical tool or artifact** that allows you to interact with others

### Concept
This new and improved project is a second iteration of our photobioreator from microchallenge 2. This photobioreactor is a space for spirulina to thrive and grow in a controlled environment for cultivation.
![Concept Miro picture](Images/concept.jpg)

### Why?
Though the previous photobioreactor worked well for demonstrative purposes and was more fun-looking in a visual way, we wanted to create one that was more functional. This PBR will be easier to transport, move around to different locations, and is more compact. It also includes a bottom component where a harvesting bottle can be stored.

### Purpose
The PBR maintains optimal conditions for spirulina by providing and monitoring the correct amount of light, temperature, and airflow. By using a light sensor, we are able to determine the density of the spirulina and its growth by the amount of light passage. The temperature sensor will tell us if the spirulina water is getting too cool. The pumps provide airflow by means of air bubbles and circulation. The removable caps allow the user to easily remove the top and tubes by taking it off to harvest. The data from the sensors will be sent to computers via wifi to be monitored.

### Plan And Execution
Before starting anything, we began by thinking back on the photobioreator1.0 and establishing what we wanted to change, modify, or keep the same. We then researched and looked for inspiration through other spirulina growing references we found. Some of these resources included Eduardo Chamorro’s project Sphira and a company for growing your own spirulina called spirulina society. We threw all of our ideas onto the miro board, wrote down a rough plan of what we would do each day of the week, and got started. Given the need for practicality and more complex electronics, we decided to make the design relatively simple compared to the previous one.

![Week plan picture](Images/plan.jpg)

### Fabrication Process and Materials

#### Electronics

  - 2 huzzah feather ESP32
  - light sensors
  - temperature sensor
  - jumper wires
  - power source
  - LED lights with 10k resistor and mosfet
  - potentiometer for temperature
  - relay for air pumo
  - mosfter for persistaltic pump
  - 10k resistor for light sensor
  - air pump
  - peristaltic pump



#### Fabrication

- 2 large glass bottles
- 1 small glass harvesting bottles
- 3mm acrylic pane
- 2mm mdf sheet
- 12mm wood sheet
- tubing
- grow LED lights
- Tube connectors
- screws

We first designed the stand/box in rhino. The upper panels of acrylic and mdf were cut on the laser cutter while the drawer and structure of the box was cut using the CNC. The bottle caps were modeled and then 3D printed with flexible filament. After everything was cut, the pieces were sanded and assembled into a box. To create the sensor mold, it was first 3D printed, then hard silicone was poured in while the sensors were suspended. LED lights were inserted into the top panel to provide light to the bottles from below.

#### System Diagram

#### Integrated Design

#### Future Development Opportunities
With this photobioreator, we aim to be able to maintain a very controlled environment. Something that could help with this is adding a motorized shade that protects the bottles from direct sunlight when it gets too hot. We would need to add additional light sensors facing the outside of the box to detect the amount of sunlight coming in. We also thought about measuring C02 concentrations to see if the algae was in fact bioremediating the air.

#### Hiccups
- We did not have enough acrylic material to create enough space that we needed for the LEDs. In order to solve this, we created a fram from mdf that would act as a spacer.
- For the lid/caps, we originally wanted to print with flexible filament so that it could wrap around the top. It was not supported by the printer so we decided to print with PLA instead.
- Before cutting any of the design, we put the box together in the 3D model version to ensure everything would line up. We then adjusted the model accordingly
- The sensor molds were very finicky as they are small. We first printed a mold in PLA which stuck and ripped the silicone mold. As a second iteration, we printed one with flexi filament in a single-layered spiral print so that the mold would be easy to remove.
- The CNC did not cut through some parts of the box file because the wood thickness was thinner at the edges. We recut some of these parts and sanded down the rest.

