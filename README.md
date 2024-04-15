# Anagram
Outputs all possible words made from input's letters  
Doublons are removed  
Checks words in two ref: prenoms (11k) and french common names (336k)  
Complexity of factorial (strlen(input)) / factorial (nb of each redodant letters)  
Comparision has been optimized using cpp map and vector, binaryserach but is still very long for more than 10 letters inputs  

## Usage
`git clone https://github.com/bastienkody/anagram.git && cd anagram && make`  

`./anag input`

Might not work on not-unix system.  
Needs c/c++ libs and make (makefile tools)

## Illustrations

![alt text](https://github.com/bastienkody/anagram/blob/cpp/data/pirates.png)
![alt text](https://github.com/bastienkody/anagram/blob/cpp/data/carabine.png)
![alt text](https://github.com/bastienkody/anagram/blob/cpp/data/abcdefghi.png)

## To do
Set some flags to stop generating words:  
more than 3-4 consecutives vowels or consonants it might stop these serquence and jump to next  
ie. barista, when it reach brsaait there is no possibility for any brs*** so it might stop that sequence and directly jump to brtaais (wich is also bad), so jump to next etc
