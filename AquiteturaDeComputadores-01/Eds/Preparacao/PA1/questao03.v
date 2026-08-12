/*
 Questao_03.v
 842527 - Gabriel Ferreira Pereira
*/

module f (output s, input a, input b, input c);
    wire m1, m2, nc;

    // inversões
    not (nc, c);

    // MUX(a, b, c)
    assign m1 = c ? b : a;

    // MUX(~b, ~a, c)
    assign m2 = c ? ~a : ~b;

    // MUX(m1, m2, ~c)
    assign s = nc ? m2 : m1;
endmodule
