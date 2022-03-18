# 10 cipher and decipher programs
the file contain 10 cipher and decipher prograsm that in Assignment 2 FCAI CU

## 0. Affine Cipher
>In affine cipher each letter in an alphabet is mapped to its numeric equivalent, encrypted using a simple mathematical function, and converted back to a letter, Each letter is encrypted with the function (5x + 8) mod 26, The decryption function is 21(y - 8) mod 26
<details><summary>show how it work</summary>
<p>

#### program require a message and a, b, c integer numbers

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

#### program require a message and the number of shifts

      message: ABCDEFGHIJKLMNOPQRSTUVWXYZ
      key: 3
      cipher: DEFGHIJKLMNOPQRSTUVWXYZABC

</p>
</details>

