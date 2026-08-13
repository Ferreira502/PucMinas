// -------------------------
// Guia_0507.v
// Nome: Gabriel Ferreira Pereira
// Matricula: 842527
// -------------------------

module Guia_0507 (output s, input a, input b);
    wire notb;
    wire axnornotb;

    // inverter b usando NOR
    nor NOR1 (notb, b, b);   

    // agora precisamos de XNOR(a, notb)

    // passo 1: XOR = (a | notb) & (~a | ~notb)
    wire nota, notnotb;
    wire a_or_notb, nota_or_notnotb;
    wire xor1;

    // inverter entradas
    nor NOR2 (nota, a, a);         
    nor NOR3 (notnotb, notb, notb);

    // ORs
    wire na, nb;
    nor NOR4 (na, a, a);           
    nor NOR5 (nb, notb, notb);     
    nor NOR6 (a_or_notb, na, nb);  

    wire nna, nnb;
    nor NOR7 (nna, nota, nota);        
    nor NOR8 (nnb, notnotb, notnotb); 
    nor NOR9 (nota_or_notnotb, nna, nnb); 

    // XOR = (a|notb) & (~a|~notb)
    wire tmp;
    nor NOR10 (tmp, a_or_notb, nota_or_notnotb);
    nor NOR11 (xor1, tmp, tmp);

    // XNOR = ~(XOR)
    nor NOR12 (s, xor1, xor1);
endmodule


// -------------------------
// Testbench
// -------------------------
module test_Guia_0507;
    reg a, b;
    wire s;

    Guia_0507 modulo (s, a, b);

    initial begin
        $display("Guia_0507 - Gabriel Ferreira Pereira - 842527"); 
        $display("Test module - f(a,b) = ~(a ^ ~b) usando apenas NOR");
        $display(" a  b  |  s ");
        $display("-------------");

        a=0; b=0; #1 $display(" %b  %b  |  %b", a,b,s);
        a=0; b=1; #1 $display(" %b  %b  |  %b", a,b,s);
        a=1; b=0; #1 $display(" %b  %b  |  %b", a,b,s);
        a=1; b=1; #1 $display(" %b  %b  |  %b", a,b,s);
    end
endmodule