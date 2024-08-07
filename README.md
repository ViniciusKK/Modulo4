# Simon Game with ESP32

![Simon Game](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR25zz81QtS0_Bp7VvyqKZboDpQF7hRA7551Q&s)

## Description

The Simon Game is a classic memory game where players must repeat a sequence of lights and sounds generated randomly by the game. Each round, the sequence increases by one step, making the challenge more difficult. This project recreates the Simon Game using an ESP32, LEDs, and buttons, providing a fun and interactive way to test and improve your memory.

## How does the game work?

1. **Game Setup**: The ESP32 is configured with LEDs and buttons connected to specific pins. When the game starts, a sequence of lights is generated.
2. **Machine's Turn**: The ESP32 lights up the LEDs in a specific order. This order is shown to the player, who must memorize it.
3. **Player's Turn**: The player must repeat the sequence by pressing the buttons corresponding to the LEDs.
4. **Sequence Verification**: The sequence entered by the player is compared to the sequence generated by the machine. If correct, the game moves to the next round, increasing the sequence.
5. **Game Over**: If the player makes a mistake, the game ends and the LEDs indicate that the player has lost. The game can then be restarted.

## How does the code work?

### Code Architecture

- **Setup**: Configures the LED and button pins, initializes serial communication, and sets pin modes.
- **Reset**: Function to restart the ESP32.
- **Machine's Turn**: Generates a random number, adds it to the sequence, and displays the sequence on the LEDs.
- **Player's Turn**: Reads button inputs, compares them to the machine's sequence, and checks if they are correct.
- **Game Over**: If the player makes a mistake, all LEDs light up, indicating the end of the game, and the ESP32 is restarted.
- **Loop**: Alternates between the machine's and player's turns, checking if the game should be restarted.

## Requirements

### Hardware
- ESP32
- 4 LEDs
- 4 buttons
- Resistors
- Connecting wires
- Breadboard

### Software
- Arduino IDE or another IDE compatible with ESP32

## Assembly Instructions

1. **Connecting LEDs**: Connect the LEDs to the specified pins (25, 2, 27, 18) with appropriate resistors.
2. **Connecting Buttons**: Connect the buttons to the specified pins (34, 35, 32, 13) with internal pull-up resistors.
3. **Restart Button**: Connect a button to pin 4 for the reset function.
4. **Power**: Connect the ESP32 to a power source or via USB.

## How to Play

1. Power on the ESP32.
2. Watch the sequence of LEDs light up.
3. Repeat the sequence by pressing the corresponding buttons.
4. If you make a mistake, the LEDs will indicate Game Over.
5. Press the reset button to play again.
