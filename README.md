# lem_in
Program take params of ant's farm, comands and comments<br>
```[number of ants]<br>
##[comand]                  // comand that apply for next line<br>
[name_1][x][y]              //name and coordinates of the room<br>
[name_2][x][y]<br>
...<br>
[name_n][x][y]<br>
[name_1]-[name_2]           //link<br>
[name_n]-[name_m]<br>
...<br>
```
Than it looking for the best way to deliver all ants from start room to end room, one ant in one room per turn
```
L[ant's number]-[destination room's name]
```
