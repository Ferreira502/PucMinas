/*
 Questao_02d.v
 842527 - Gabriel Ferreira Pereira
*/


module f_d (
    output s,
    input a, b, c
);
    wire nb, nc, t1;

    not (nb, b);
    not (nc, c);
    and (t1, nb, nc);
    or  (s, a, t1);

endmodule
