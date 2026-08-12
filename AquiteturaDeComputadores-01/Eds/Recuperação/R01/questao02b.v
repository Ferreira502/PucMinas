/*
 Questao_02b.v
 842527 - Gabriel Ferreira Pereira
*/

module f_b (
    output s,
    input a, b, c
);
    wire n1, n2;

    // n1 = b' + c' 
    nand (n1, b, c);

    // s = a * n1
    nand (n2, a, n1);
    nand (s, n2, n2);  // inverte de volta para AND

endmodule