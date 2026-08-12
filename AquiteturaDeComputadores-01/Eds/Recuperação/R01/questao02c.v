/*
 Questao_02c.v
 842527 - Gabriel Ferreira Pereira
*/

module f_c (
    output s,
    input a, b, c
);
    wire nb, nc;
    wire t1, t2;

    not (nb, b);
    not (nc, c);

    or  (t1, a, nb);
    or  (t2, a, nc);
    and (s, t1, t2);

endmodule