/*
 Questao_02.v
 842527 - Gabriel Ferreira Pereira
*/

module f (output s, input x, input y);
    wire w1, w2, w3, w4, w5;

    not  NOT_1 (w1, x);      // w1 = ~x
    not  NOT_2 (w2, y);      // w2 = ~y
    and  AND_1 (w3, y, w2);  // w3 = y & ~y  => sempre 0
    or   OR_1  (w4, w1, x);  // w4 = ~x | x  => sempre 1
    not  NOT_3 (w5, w4);     // w5 = ~(~x | x) => sempre 0
    and  AND_2 (s, w3, w5);  // s = w3 & w5 => 0
endmodule


/* Saida esperada
x y | s
----------
0 0 | 0
0 1 | 0
1 0 | 0
1 1 | 0
*/