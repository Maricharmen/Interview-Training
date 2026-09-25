/**
 * 
 * Tienes un grid con unos laseres, los laseres tienen una coordenada x, y, el láser impacta a 
 * todas las celdas de su misma fila y columna, luego tienes un robot en otras coordenadas x, y 
 * donde el robot solo se puede mover en linea recta ya sea arriba, abajo, izquierda o derecha, 
 * debes retornar el máximo número de celdas que puede avanzar antes de morir por algún láser, 
 * tu posición inicial está protegida por lo que no puedes morir por el láser ahí 
 * 
 * 
 */

 /*
 
 x x x x x x 
 x x x x x x
 x x l x x x 
 x x x x x x
 x x x x x x 
 x x x x x r

 Assumption: El robot no puede repetir celdas

 l (l1, l2)
 r (r1, r2)

 check if robot and laser are on the same row and colum 
 
 otherwise the maximum nuber of cells is 
 if robot on four cuadrant
 (r-l1-1) * (c-l2-1) 
 thrid
(r-l1-1)*(l2-1)
second
(l1-1)*(c-l2-1)
first
(l1-1)*(l2-1)

 */

