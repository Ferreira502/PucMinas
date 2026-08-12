// ------------------------- 
// Guia_1403.v
// Nome: Gabriel Ferreira Pereira
// Matricula: 842527 
// ------------------------- 

// Registrador de deslocamento circular a direita
// 6 bits com carga unitaria no primeiro estagio (LD)

module ring_right_6bit (
    input clk,          
    input clear,        
    input ld,           
    output [5:0] q      
);

reg [5:0] q_reg;

always @(posedge clk or posedge clear or posedge ld)
begin
    if (clear)
        q_reg <= 6'b000000;          
    else if (ld)
        q_reg <= 6'b000001;          
    else
        q_reg <= {q_reg[0], q_reg[5:1]};
end

assign q = q_reg;

endmodule
