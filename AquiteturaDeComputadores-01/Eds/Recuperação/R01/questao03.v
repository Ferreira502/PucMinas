/*
 Questao_03.v
 842527 - Gabriel Ferreira Pereira
*/

module Expressao_S (output S, input A, input B, input C);
  wire w1, w2, w3;

  or  OR1 (w1, ~A, C);  // (A' + C)
  or  OR2 (w2, A, B);   // (A + B)
  or  OR3 (w3, B, C);   // (B + C)

  and AND1 (S, w1, w2, w3);

endmodule