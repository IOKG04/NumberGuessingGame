## NumberGuessingGame

NumberGuessingGame is a game about guessing a randomly generated number

### Building

Building NumberGuessingGame is simple, you just run
```bash
make
```

That is assuming you have `make` and `gcc` installed.  
If not, install those and run
```bash
make
```

### Usage

Ive already typed all of this out, so heres the help message:
```
Usage:
 nggame                         Starts the game with a number between 1 and 1000 (inclusive)
 nggame [max]                   Starts the game with a number between 1 and [max] (inclusive)
 nggame [min] [max]             Starts the game with a number between [min] and [max] (inclusive)
 nggame [min] [max] [guesses]   Starts the game with a number between [min] and [max] (inclusive) and [guesses] guesses
 nggame help          Shows this message

How to play the game:
 A random number will be generated between the specified limits (by default 1 and 1000 (inclusive)).
 You will have to guess said number. If you manage to do so, you win, if you dont, you lose.
 You guess by typing a number.
 If the number you typed is the number generated, you win.
 If it isnt the number that was generated, it will tell you if you guessed over or under the generated number.
 Lastly, you only have a limited number of guesses (usually log_2 of the amount of possible numbers). If you go over that limit, you lose.

Please note that all numbers entered to this program will be interpreted as 32 bit unsigned base 10 integers (so no fractions or negative numbers allowed)

```
