# Crypt
## Description
This is a project that will be used to challenge my computer science skill. It is a basic program that allows the user to pick from a number of different encryptions and input a message to get an encrypted output. 

## Project State
- **Number of Encryptions:** 2
- **User Interface:** Text Based
- **Type of Memeory:** None
- **Languages Used:** C++

## Encryptions
### Ceaser Cypher
***
- **Input**
  - *Limits:* None
  - *Parameters:*\
    ```Input Message```: Text\
    ```Shift```: Integer

- **Output**
  - *Characters Encoded:*

| Character        |Example| Conversion    |
|:----------------:|:-----:|:-------------:|
| Uppercase Letters| ```A``` - ```Z``` | The letter is shifted by ```Shift``` |
| Lowercase Letters| ```a``` - ```z``` | The letter is shifted by ```Shift``` |
| Numbers          | ```1``` - ```9``` | Untouched|
| Punctuation       | (```!```,```,```,```()```, etc.) | Untouched|
    
- **Example**
  <pre><code>What is the input message? <b> H3llo W0r!d </b>
  How much would you like to shift the letters by? (1-26) <b>15</b>
  Your encrypted message is "W3aad L0g!s"
  </code></pre>

> [!WARNING]
Known Bugs: None

### Matrix Encryption
***
- **Input**
  - *Limits:* Numbers should not be inputted as this makes decryption impossible, but this will not break encryption
  - *Parameters:*\
    `Input Message`: Text\
    `Encoded Numbers`: Text\
    `Matrix Rows`: Integer\
    `Matrix Columns`: Integer\
    `Key Matrix`: Integer

- **Output**
  - *Characters Encoded:*
 
| Character        |Example| Conversion    |
|:----------------:|:-----:|:-------------:|
| Uppercase Letters| ```A``` - ```Z``` | number (Determined by multiplying the key matrix by a matrix translated from the letters) |
| Lowercase Letters| ```a``` - ```z``` | number (Determined by multiplying the key matrix by a matrix translated from the letters) |
| Numbers          | ```1``` - ```9``` | Untouched|
| Punctuation       | (```!```,```,```,```()```, etc.) | Untouched|

- **Example**
  <pre><code>What is the input message? <b>H3ll0 W0r!d</b>
  Would you like to encode numbers as well? (if no, numbers will remain numbers, and will make it impossible to decrypt. <b>no</b>
  How many rows does this matrix have? <b>2</b>
  How many columns does this matrix have? <b>2</b>
  Type in 4 numbers. (Hit Enter after each number).
  <b>1</b>
  <b>2</b>
  <b>3</b>
  <b>4</b>
  Your encrypted message is "32 3 52 66 0 105 59 0 100 ! 58 89 "
  </code></pre>
> [!NOTE]
For now the answer to ```Would you like to encode numbers as well? (if no, numbers will remain numbers, and will make it impossible to decrypt.``` does not matter.

> [!WARNING]
> Known Bugs:
> - [ ] Rectangular Matrices for the key matrix crash the program. 
