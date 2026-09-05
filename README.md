# Task 02 - Timers and Non-Blocking Code

## Objective
Rewrite the loop so nothing blocks and timing stays accurate.

## Requirements completed
- No `delay()` in the main loop
- `millis()` is used as a non-blocking timer
- Two independent tasks run at different rates
- The repository includes the non-blocking Arduino code and an explanation

## Project behavior

| Output | Rate | Purpose |
|---|---:|---|
| LED 1 (D8) | Every 500 ms | Fast periodic task |
| LED 2 (D9) | Every 2000 ms | Slow periodic task |

## Why `millis()` instead of `delay()`?
`delay()` pauses program execution while waiting. The `millis()` approach checks elapsed time and lets the main loop continue running, so multiple tasks can operate independently without blocking each other.

## Wiring
- Arduino D8 -> 220 ohm resistor -> LED 1 anode
- LED 1 cathode -> GND
- Arduino D9 -> 220 ohm resistor -> LED 2 anode
- LED 2 cathode -> GND

See `wiring_diagram.svg` and `diagram.json`.

## Simulation
The `diagram.json` is prepared for an Arduino Uno simulation workflow such as Wokwi.

Expected behavior:
- LED 1 changes state every 500 ms
- LED 2 changes state every 2 seconds
- No `delay()` is used

## Expected outcome
A non-blocking timing demonstration with two activities occurring at different rates.

## Suggested submission description
Implemented a non-blocking Arduino timing system using millis(). Two independent LED tasks run at 500 ms and 2000 ms intervals without using delay() in the main loop. The repository includes the Arduino sketch, simulator configuration, and wiring diagram.
