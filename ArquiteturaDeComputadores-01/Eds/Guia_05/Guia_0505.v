// ------------------------- 
// Guia_0505.v - GATES 
// Nome: Gabriel Ferreira Pereira 
// Matricula: 842527 
// ------------------------- 

module Guia_0505 (output s, input a, input b);
    wire nota, notb;       // inversos
    wire aandb, notaandnotb; // produtos
    wire or1;              // soma

    // NOT usando NOR
    nor NOR1 (nota, a, a);     
    nor NOR2 (notb, b, b);     

    // AND(a,b) = ~(~a + ~b)
    wire n1;
    nor NOR3 (n1, a, b);       
    wire t1, t2;
    nor NOR4 (t1, nota, nota); 
    nor NOR5 (t2, notb, notb); 
    nor NOR6 (aandb, t1, t2); 

    // AND(~a, ~b)
    wire t3, t4;
    nor NOR7 (t3, nota, nota); 
    nor NOR8 (t4, notb, notb); 
    nor NOR9 (notaandnotb, t3, t4);

    // OR dos dois produtos = XNOR
    wire tmp;
    nor NOR10 (tmp, aandb, notaandnotb);
    nor NOR11 (s, tmp, tmp);   
endmodule


// -------------------------
// Testbench
// -------------------------
module test_Guia_0505;
    reg a, b;
    wire s;

    // Instância
    Guia_0505 XNOR1 (s, a, b);

    initial begin
        $display("Guia_0505 - Gabriel Ferreira Pereira - 842527"); 
        $display("Test module ~(a ^ b) = a xor b"); 
        $display(" a  b  |  s ");
        $display("-------------");

        // Testes
        a=0; b=0; #1 $display(" %b  %b  |  %b", a,b,s);
        a=0; b=1; #1 $display(" %b  %b  |  %b", a,b,s);
        a=1; b=0; #1 $display(" %b  %b  |  %b", a,b,s);
        a=1; b=1; #1 $display(" %b  %b  |  %b", a,b,s);
    end
endmodule