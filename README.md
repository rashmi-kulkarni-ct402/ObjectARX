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
