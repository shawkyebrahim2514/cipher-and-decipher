# 10 cipher and decipher programs
the file contain 10 cipher and decipher prograsm that in Assignment 2 FCAI CU

## 0. Affine Cipher
>In affine cipher each letter in an alphabet is mapped to its numeric equivalent, encrypted using a simple mathematical function, and converted back to a letter, Each letter is encrypted with the function (5x + 8) mod 26, The decryption function is 21(y - 8) mod 26
<details><summary>show how it work</summary>
<p>

#### program requires a message and a, b, c integer numbers

      takes three parameters a, b and c and does the encryption and decryption according to these equations:
      E(x) = (a x + b) mod 26 where x is the letter to cipher.
      D(y) = c (y - b) mod 26 where y is the letter to decipher.
      a, b, c are arbitrary positive integers that satisfy the condition (a * c) mod 26 = 1

</p>
<p>

#### Example

      message: i love cpp
      a: 1
      b: 3
      c: 27
      cipher: L ORYH FSS

</p>
</details>

## 1. Caesar Cipher
>It is a type of substitution cipher in which each letter in the plaintext is replaced by a letter at some fixed number of positions down the alphabet
<details><summary>show how it work</summary>
<p>

#### program requires a message and the number of shifts

      message: ABCDEFGHIJKLMNOPQRSTUVWXYZ
      key: 3
      cipher: DEFGHIJKLMNOPQRSTUVWXYZABC

</p>
</details>


## 2. Atbash Cipher
>(called mirror code) it simply reverses the alphabets, so A encodes to Z, B to Y and so on.
<details><summary>show how it work</summary>
<p>

#### program only requires a message

      message: i love cpp
      cipher: R OLEV XKK

</p>
</details>


## 3. Vignere Cipher
>In this method, a keyword is repeatedly added character by character to each alphabetic letter in the original message. The addition is carried out using the ASCII codes for each of the characters, modulo 26, and the result is added to the code for the letter 'A' in the ASCII code sequence
>Only alphabetic characters will be encoded, all other characters will be outputted unchanged, keyword is only alphabetic characters, All alphabetic characters should be converted to uppercase before the encoding process begins, The input message should be restricted to 80 characters, the keyword to 8 characters
<details><summary>show how it work</summary>
<p>

#### program requires a message and a keyword

      message: i love cpp
      keyword: mask
      cipher: U DYIQ UZC

</p>
</details>


## 4. Baconian Cipher
>each letter of the plaintext is replaced by a group of five of the letters 'A' or 'B'. This replacement is a binary encoding.
<details><summary>show how it work</summary>
<p>

#### program requires a message

      message: i love cpp
      cipher: ABAAA ABABBABBBABABABAABAA AAABAABBBBABBBB

</p>
</details>


## 5. Simple Substitution Cipher
>In this cipher, a replacement alphabet is used to replace each letter by another one
>builds the cipher alphabet using a given key of 5 unique letters. The user enters the key to cipher a message and the same key to decipher the message. The cipher alphabet is built by adding the remaining 21 letters in order after the key letters.
<p>

#### if the key is "ZEBRA"

      alphabets: A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
      ciphered alphabets: Z E B R A C D F G H I J K L M N O P Q S T U V W X Y

</p>
<details><summary>show how it work</summary>
<p>

#### program requires a message

      message: i love cpp
      key: ZEBRA
      cipher: G JMUA BNN

</p>
</details>


## 6. Polybius Square Cipher
>A Polybius Square is a table that allows someone to convert letters into numbers, take a key with 5 chaarcters and make it as a row and a column
>To decipher the message, you must enter the same key used to encrypt it, Note that I/J are encrypted to the same numbers by when decrypted, we take I since it is more common
<details><summary>show how it work</summary>
<p>

#### program requires a message

      message: i love cpp
      cipher: 24 31345115 133535

</p>
</details>


## 7. Morse Code
>It is a code consisting of two symbols dot and dash and used to in the telegraph system in the past and also communicate messages in primitive ways
<details><summary>show how it work</summary>
<p>

#### program only requires a message

      message: i love cpp
      cipher: ..  .-.. --- ...- .  -.-. .--. .--.

</p>
</details>


## 8. XOR Cipher
>a secret key consisting of one letter is give. Then each letter of the message goes through XOR operation with the secret letter, The output is printed in text and hexadecimal. The original message can be recovered from the encrypted message by the same algorithm, XOR with the secret letter
<details><summary>show how it work</summary>
<p>

#### program requires a message and a key

      message: i love cpp
      key: p
      cipher: y |⌂fu s``
      hexa: 494c4f5645435050

</p>
</details>


## 9. Rail-fence Cipher
>The rail fence cipher (also called a zigzag cipher) is a form of transposition cipher. It derives its name from the way in which it is encoded
<p>

      defend the east wall of the castle

</p>

<p>

      d . . . n . . . e . . . t . . . l . . . h . . . s . . .
      . e . e . d . h . e . s . w . l . o . t . e . a . t . e
      . . f . . . t . . . a . . . a . . . f . . . c . . . l .

</p>

<details><summary>show how it work</summary>
<p>

#### program requires a message and a key

      message: defend the east wall of the castle
      key: 3
      cipher: dnetlhseedheswloteateftaafcl

</p>
</details>