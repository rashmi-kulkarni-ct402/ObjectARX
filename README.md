# ObjectARX Application

## Project Overview

This project demonstrates various ObjectARX functionalities in the AutoCAD environment, including creating custom commands, adding lines, creating layers, listing objects, and changing object properties based on user input.

## Exercises

### Exercise 1 - 3: Create a New Project, Compile and Load ObjectARX Project and Define a Custom Command

- **Description:** Creates a new ObjectARX project, compiles and loads the project and runs a custom command that displays a greeting message in the AutoCAD command line.
- **Command:** `MyGreetings`
- **Expected Output:** Displays "Rashmi says Hi!" in the AutoCAD command line.

### Exercise 4: Add Line

- **Description:** Adds a line to the drawing using hardcoded start and end points.
- **Command:** `addNewLine`
- **Expected Output:** Adds a line from point (6000.0, 4000.0, 0.0) to point (10000.0, 2000.0, 0.0).

### Exercise 5: Create New Layer

- **Description:** Creates a new layer named "OBJ" with cyan color if it doesn't exist.
- **Command:** `myLayer`
- **Expected Output:** Creates a new layer named "OBJ" with cyan color.

### Exercise 6: List All Objects

- **Description:** Lists all objects in the current drawing space.
- **Command:** `listAllObjects`
- **Expected Output:** Displays the class names of all objects in the current drawing space.

### Exercise 7: Line Using User Input

- **Description:** Draws a line based on user input for the start and end points.
- **Command:** `addLineUsingUserInput`
- **Expected Output:** Prompts the user for the start and end points, then draws a line accordingly.

### Exercise 8: Select Objects and Request Keyword

- **Description:** Allows the user to select objects and change their color based on a keyword input.
- **Command:** `changeColor`
- **Expected Usage:** Select objects, then enter a color keyword (e.g., "Red", "Yellow", "Green", "Bylayer").
- **Expected Output:** Changes the color of the selected objects to the specified color.

## Usage

1. Build the project in Microsoft Visual Studio.
2. Load the resulting DLL in AutoCAD using the "APPLOAD" command.
3. Enter the respective command for each exercise to execute the functionality.

## Output

Exercise 1:

![Exercise1](https://github.com/rashmi-kulkarni-ct402/ObjectARX/assets/158051740/a20af321-453c-41f6-a40e-e90f1ae76f7e)

Exercise 2:

![Exercise2](https://github.com/rashmi-kulkarni-ct402/ObjectARX/assets/158051740/a12096e0-4d11-4534-8c73-f1e96b913721)

Exercise 3:

![Exercise3](https://github.com/rashmi-kulkarni-ct402/ObjectARX/assets/158051740/d5794f4e-437b-4657-bdbd-315da35a016a)

Exercise 4:

![Exercise4](https://github.com/rashmi-kulkarni-ct402/ObjectARX/assets/158051740/00e22b8c-aaca-4796-81b4-244fc0967330)

Exercise 5:

![Exercise5](https://github.com/rashmi-kulkarni-ct402/ObjectARX/assets/158051740/df917856-3b3b-4462-a516-733e71ed2612)

Exercise 6:

![Exercise6](https://github.com/rashmi-kulkarni-ct402/ObjectARX/assets/158051740/4cdb10ba-607b-4518-9046-6c5ee8de7203)

Exercise 7:

![Exercise7](https://github.com/rashmi-kulkarni-ct402/ObjectARX/assets/158051740/3715cab5-5b87-4d7f-b3f0-9c493a5a27e4)

Exercise 8:

![Exercise8_ChangeColorCommand](https://github.com/rashmi-kulkarni-ct402/ObjectARX/assets/158051740/8e4bde4d-3f30-4473-b9e1-8cad9bf20bb1)

![Exercise8_SelectColor](https://github.com/rashmi-kulkarni-ct402/ObjectARX/assets/158051740/baabc757-8a82-4d43-b176-ce858cd6da98)

![Exercise8_UpdatedColor](https://github.com/rashmi-kulkarni-ct402/ObjectARX/assets/158051740/cf144485-4b26-4df0-a352-5d28b32be6aa)
