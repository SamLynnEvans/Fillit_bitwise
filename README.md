# Fillit_bitwise
Fitting tetris pieces in the smallest square (using bit maniulation).

Fillit takes a map containing various tetriminos as a paramater, and returns a printed image of them sorted into the smallest possible square. Rotations of the tetriminos are not allowed.

After failing Fillit for the second time (I forgot to include an author file in the repository...), I respondedly positively to the dissapointment, deciding to learn something new and rewrite the program using bit manipulation.

I had never used bit operators before, so this project was a wonderful entry into the beautiful inception-like world of bit masks (you mean a game of tetris is happening inside that number???).

<b>How to run the program</b>

./fillit map_file

the map_file is a simple text file and should contain tetriminos formatted as in this example:

.#..<br/>
.##.<br/>
..#.<br/>
....<br/>
<br/>
....<br/>
.#..<br/>
.#..<br/>
.##.<br/>
<br/>
.##.<br/>
.##.<br/>
....<br/>
....<br/>
<br/>
This map would result in the following output:<br/><br/>
<img src="https://github.com/SamLynnEvans/Fillit_bitwise/blob/master/output_example.png"/>

More maps can be seen <a href="https://github.com/miniponps/42-Fillit/tree/master/map">here</a>.

<b>The algorithm</b>

Fillit uses a recursive back-tracking algorithm to try putting each piece in each possible square starting from the top-left corner. I first learnt about this technique attempting the n queens problem during the entry exam for my school (Ecole 42), and later in fact wrote a <a href="https://github.com/SamLynnEvans/nqueens_bitwise">much more elegant solution</a> to this same problem using bit manipulation.

Each tetrimino is stored as an 64 bit number, where a binary depiction of the first element in the map above would look like this:

1000000000000000110000000000000001000000000000000000000000000000

Or the same number shown more intutitively:

1000000000000000<br/>
1100000000000000<br/>
0100000000000000<br/>
0000000000000000<br/>

A map is then created which consists of an array of 16 * 16-bit integers, where all values are set to 0. The beauty of this method is that we can then simply move our piece along the map using bit shift operators, and check if in each spot we can place a piece by doing a simple '&' operation between the piece and the map (cast as a uint64_t). 

If the '&' operation results in a number over 0, it means there are 1s on the map (i.e. bits of other placed tetriminos) where our piece has 1s too, so we can't put it. Conversely if it yields 0, there is no overlapping, so the piece can be put.

The most satisfying part of this algorithm then comes in adding a piece to the map through a single '^=' operation between the map and the piece (unlike before when I used char arrays and had to update every coordinate individually...). This same function can also be used to remove a piece.

<b>Learnings</b>

1. The use of bit masks to manipulate numbers into any desirable pattern of 1s and 0s. This was probably the most difficult part for me, and I had to fully get my head round the various operators and use of bit masks to do so.

2. Reinforcement of ability to implement recursive back-tracking algorithms.

3. I gained a deeper understanding of how arrays are stored in the memory and how they can be accessed. One of the biggest conceptual challenges of the project was to deal with changing sizes for the square (ranging from 2 * 2 to 16 * 16). This was achieved by using 16 integers as an array, each representing one row. When seeing if I could fit a piece, casting an integer from the map as a uint64_t would mean the piece was compared beyond only that integer, and would read 64 bits into the array, and compare against the the next 3 integers (and thus rows) too. 
