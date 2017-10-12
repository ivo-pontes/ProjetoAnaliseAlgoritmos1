set title "Algoritmos com Valores Desordenados" textcolor "red"

plot 'data/shuffle/bubbleSort.dat' with lines title columnheader(1), 'data/shuffle/insertionSort.dat' with lines title columnheader(1), 'data/shuffle/mergeSort.dat' with lines title columnheader(1), 'data/shuffle/quickSort.dat' with lines title columnheader(1)   
