/*
 Questao_02a.v
 842527 - Gabriel Ferreira Pereira
*/

module f_a (
    output s,
    input a, b, c
);
    wire w1, w2, w3, w4;

    not  NOT_1 (w1, b);       // w1 = b'
    not  NOT_2 (w2, c);       // w2 = c'
    and  AND_1 (w3, a, w2);   // w3 = a * c'
    and  AND_2 (w4, a, w1, c);// w4 = a * b' * c
    or   OR_1  (s, w3, w4);   // s = w3 + w4

endmodule
