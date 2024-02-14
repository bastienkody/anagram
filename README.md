# Anagram
Outputs all possible words made from input's letters  
Doublons are removed but not the input  
Green print words found in french dictionnary (33k words in ascii)  
Complexity of factorial (strlen(input)) / factorial (nb of each redodant letters)  
Dict comparision is not yet optimized at all (around 85s for 720 words on i5 2Ghz 8go LPDDR3)  

## Usage
`git clone https://github.com/bastienkody/anagram.git && cd anagram && ./script <input>`  
A file `input_anagram.txt` is generated  

## Improvement :  
- Phrases : compare each word (IFS is sep) to dict
- Make it faster (indexation : separate dict into files by letter? turn it to a C array? ; shorter dict? )
- English dict
- Noms propres ?  
- Ponctuation handled : discard some ponctuations char ?  