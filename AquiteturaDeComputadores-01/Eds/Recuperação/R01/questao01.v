/*
 Questao_01.v
 842527 - Gabriel Ferreira Pereira
*/

module SOP_NAND (
    input a, b, c, d,
    output f
);
    wire na, nb, nc, nd;
    wire n1, n2, n3;
    wire t1, t2, t3, n4;

    nand(na, a, a);
    nand(nb, b, b);
    nand(nc, c, c);
    nand(nd, d, d);

    nand(t1, nb, c);

    nand(n1, a, d);
    nand(t2, n1, nc);

    nand(n2, na, b);
    nand(t3, n2, d);

    nand(n4, t1, t2);
    nand(f, n4, t3);

endmodule


module POS_NOR (
    input a, b, c, d,
    output f
);
    wire na, nb, nc, nd;
    wire n1, n2, n3;
    wire t1, t2, t3, n4;

    nor(na, a, a);
    nor(nb, b, b);
    nor(nc, c, c);
    nor(nd, d, d);

    nor(t1, b, nc);

    nor(n1, a, nb);
    nor(t2, n1, nd);

    nor(n2, c, na);
    nor(t3, n2, nd);

    nor(n4, t1, t2);
    nor(f, n4, t3);

endmodule